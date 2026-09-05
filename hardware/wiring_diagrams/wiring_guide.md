# 🔌 Hardware Wiring & Pinout Guide

## 1. Transmitter Remote Control (TX) Pinout
| Component | Pin | ESP32 GPIO | Description |
| :--- | :--- | :--- | :--- |
| **nRF24L01+** | VCC | 3.3V (with 10uF cap) | Power Supply |
| | GND | GND | Common Ground |
| | CE | GPIO 4 | Chip Enable |
| | CSN | GPIO 5 | SPI Chip Select |
| | SCK | GPIO 18 | SPI Clock |
| | MOSI | GPIO 23 | SPI Master Out |
| | MISO | GPIO 19 | SPI Master In |
| **Joystick** | X-Axis (Steering) | GPIO 34 (Analog A0) | Steering Input |
| | Y-Axis (Throttle) | GPIO 35 (Analog A1) | Throttle Input |

## 2. Robot USV Receiver (RX) Pinout
| Component | Pin | ESP32 GPIO | Description |
| :--- | :--- | :--- | :--- |
| **nRF24L01+** | VCC | 3.3V | Power Supply |
| | GND | GND | Common Ground |
| | CE | GPIO 4 | Chip Enable |
| | CSN | GPIO 5 | SPI Chip Select |
| | SCK | GPIO 18 | SPI Clock |
| | MOSI | GPIO 23 | SPI Master Out |
| | MISO | GPIO 19 | SPI Master In |
| **Left ESC** | Signal (White/Yellow) | GPIO 12 | Hardware PWM 50Hz |
| **Right ESC** | Signal (White/Yellow) | GPIO 14 | Hardware PWM 50Hz |
| **LM2596 Buck** | Output 5V | VIN | 5V Power for ESP32 |
