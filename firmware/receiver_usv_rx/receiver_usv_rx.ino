/*
 * =====================================================================================
 * Project: Surface Rescue USV - Robot Receiver (Receiver RX)
 * Platform: ESP32 DevKit V1
 * Wireless: nRF24L01+ PA/LNA (2.4 GHz GFSK)
 * Description: Receives control payloads, computes differential thrust, generates 50Hz PWM
 *              signals for ESCs, and enforces 500ms Failsafe motor shutdown.
 * Author: Tran Trung Hieu & Bui Dieu Linh (2026)
 * =====================================================================================
 */

#include <SPI.h>
#include <RF24.h>
#include <ESP32Servo.h>

// --- Pin Definitions ---
#define PIN_CE          4
#define PIN_CSN         5
#define PIN_ESC_LEFT    12  // Left Brushless ESC Signal Pin
#define PIN_ESC_RIGHT   14  // Right Brushless ESC Signal Pin

// --- RF24 & Servo Configuration ---
RF24 radio(PIN_CE, PIN_CSN);
const byte pipeAddress[6] = "USV01";

Servo escLeft;
Servo escRight;

// --- Control Payload Structure ---
struct ControlData {
  int throttle;  // -1000 to 1000
  int steering;  // -1000 to 1000
};

ControlData payload;
unsigned long lastPacketTime = 0;
const unsigned long FAILSAFE_TIMEOUT_MS = 500; // Auto stop motors if signal lost > 500ms

void setup() {
  Serial.begin(115200);

  // Initialize Hardware PWM 50Hz for Brushless ESCs
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  escLeft.setPeriodHertz(50);    // Standard 50Hz Servo/ESC frequency
  escRight.setPeriodHertz(50);
  escLeft.attach(PIN_ESC_LEFT, 1000, 2000);   // 1000us (0% throttle) to 2000us (100% throttle)
  escRight.attach(PIN_ESC_RIGHT, 1000, 2000);

  // Arm ESCs (Send 1000us stop pulse)
  escLeft.writeMicroseconds(1000);
  escRight.writeMicroseconds(1000);
  delay(2000); // Wait for ESC arming beep

  // Initialize RF24 Receiver
  if (!radio.begin()) {
    Serial.println(F("[ERROR] nRF24L01+ Hardware Not Responding!"));
    while (1);
  }

  radio.openReadingPipe(1, pipeAddress);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

  lastPacketTime = millis();
  Serial.println(F("[OK] USV Robot Receiver RX Ready. Listening..."));
}

void loop() {
  // Check if RF packet is available
  if (radio.available()) {
    radio.read(&payload, sizeof(ControlData));
    lastPacketTime = millis(); // Update Failsafe timer

    // Compute Differential Thrust
    float k = 0.7; // Steering sensitivity factor
    int rawLeft  = payload.throttle + (int)(k * payload.steering);
    int rawRight = payload.throttle - (int)(k * payload.steering);

    // Constrain to [0, 1000] for Unidirectional ESCs
    int uL = constrain(rawLeft, 0, 1000);
    int uR = constrain(rawRight, 0, 1000);

    // Map [0, 1000] to PWM microseconds [1000, 2000]
    int pwmLeft  = 1000 + uL;
    int pwmRight = 1000 + uR;

    // Output PWM pulses to ESCs
    escLeft.writeMicroseconds(pwmLeft);
    escRight.writeMicroseconds(pwmRight);

    Serial.printf("[RX OK] PWM Left: %d us | PWM Right: %d us\n", pwmLeft, pwmRight);
  }

  // Check Failsafe Timeout
  if (millis() - lastPacketTime > FAILSAFE_TIMEOUT_MS) {
    // SIGNAL LOST! Cut power to both motors immediately
    escLeft.writeMicroseconds(1000);
    escRight.writeMicroseconds(1000);
    Serial.println(F("[FAILSAFE ACTIVE] Signal Lost > 500ms! Motors Stopped."));
  }

  delay(20); // 50 Hz loop update
}
