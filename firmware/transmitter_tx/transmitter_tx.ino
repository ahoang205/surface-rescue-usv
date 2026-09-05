/*
 * =====================================================================================
 * Project: Surface Rescue USV - Remote Controller (Transmitter TX)
 * Platform: ESP32 DevKit V1
 * Wireless: nRF24L01+ PA/LNA (2.4 GHz GFSK)
 * Description: Reads analog Joystick inputs, packs control payloads, and transmits via RF.
 * Author: Tran Trung Hieu & Bui Dieu Linh (2026)
 * =====================================================================================
 */

#include <SPI.h>
#include <RF24.h>

// --- Pin Definitions ---
#define PIN_CE        4
#define PIN_CSN       5
#define PIN_JOY_X     34  // Joystick Steering (A0 / GPIO34)
#define PIN_JOY_Y     35  // Joystick Throttle (A1 / GPIO35)

// --- RF24 Configuration ---
RF24 radio(PIN_CE, PIN_CSN);
const byte pipeAddress[6] = "USV01";

// --- Control Data Structure ---
struct ControlData {
  int throttle;  // -1000 to 1000
  int steering;  // -1000 to 1000
};

ControlData payload;

void setup() {
  Serial.begin(115200);
  
  // Initialize RF24 Transceiver
  if (!radio.begin()) {
    Serial.println(F("[ERROR] nRF24L01+ Hardware Not Responding!"));
    while (1);
  }

  radio.openWritingPipe(pipeAddress);
  radio.setPALevel(RF24_PA_MAX);       // Max PA Power for long-range (+20 dBm)
  radio.setDataRate(RF24_250KBPS);     // 250kbps for maximum sensitivity & range
  radio.stopListening();               // Set as Transmitter

  // Configure Joystick Pins
  pinMode(PIN_JOY_X, INPUT);
  pinMode(PIN_JOY_Y, INPUT);

  Serial.println(F("[OK] USV Transmitter TX Ready. Transmitting..."));
}

void loop() {
  // Read Analog Joystick (ESP32 ADC 12-bit: 0 to 4095)
  int rawX = analogRead(PIN_JOY_X);
  int rawY = analogRead(PIN_JOY_Y);

  // Map to [-1000, 1000] control range
  payload.steering = map(rawX, 0, 4095, -1000, 1000);
  payload.throttle = map(rawY, 0, 4095, -1000, 1000);

  // Deadzone filter around center position
  if (abs(payload.steering) < 50) payload.steering = 0;
  if (abs(payload.throttle) < 50) payload.throttle = 0;

  // Send Control Payload over 2.4GHz GFSK RF
  bool success = radio.write(&payload, sizeof(ControlData));

  if (success) {
    Serial.printf("[TX OK] Throttle: %d | Steering: %d\n", payload.throttle, payload.steering);
  } else {
    Serial.println(F("[TX FAIL] Packet Transmission Dropped"));
  }

  delay(20); // 50 Hz control update rate
}
