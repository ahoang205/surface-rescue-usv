# 🏗️ System Architecture & BOM

## Software Architecture
* **OS / RTOS:** FreeRTOS on ESP32
* **Control Frequency:** 50 Hz (20 ms loop execution)
* **Motor Drive:** Hardware PWM 50 Hz (LEDC)
* **Failsafe:** Auto-stop timer triggering after 500 ms of RF signal loss

## Hardware Bill of Materials (BOM)
1. **ESP32 DevKit V1** (2x) - Transmitter & Receiver MCUs
2. **nRF24L01+ PA/LNA + SMA Antenna** (2x) - 2.4GHz GFSK RF Transceivers
3. **Brushless Thruster T60 IP68** (2x) - Waterproof Thruster Motors (2.5 kgf max thrust)
4. **Brushless ESC 30A** (2x) - Electronic Speed Controllers
5. **LiPo Battery 4S 14.8V 4500mAh 35C** (1x) - Main Power Pack (~28.5 min runtime)
6. **LM2596 DC-DC Step-Down** (1x) - 5V 3A Logic Power Supply
7. **PVC Pipes (Ø90mm, 1m)** (2x) - Pontoon Catamaran Hull
