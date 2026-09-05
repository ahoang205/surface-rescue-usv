# 🚤 Surface Rescue USV (Remote-Controlled Surface Rescue Robot)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Microcontroller: ESP32](https://img.shields.io/badge/MCU-ESP32--WROOM--32-blue.svg)](https://www.espressif.com/)
[![RF: nRF24L01+](https://img.shields.io/badge/RF-nRF24L01%2B%202.4GHz-green.svg)](https://www.nordicsemi.com/)
[![Research Paper: Included](https://img.shields.io/badge/Paper-JSTT%202026-brightgreen.svg)](paper/Bai_Bao_Robot_Cuu_Ho_Mat_Nuoc_Hoan_Chinh.md)

> **Open-Source Hardware & Firmware for an ESP32-powered Unmanned Surface Vehicle (USV) designed for rapid water rescue and emergency lifebuoy deployment.**

---

## 📄 Research Paper & Report (Báo Cáo Khoa Học)

Báo cáo khoa học hoàn chỉnh và các tính toán chi tiết của dự án được lưu riêng biệt tại thư mục **[`paper/`](paper/)**:

* 📕 **[Bai_Bao_Robot_Cuu_Ho_Mat_Nuoc_Hoan_Chinh.md](paper/Bai_Bao_Robot_Cuu_Ho_Mat_Nuoc_Hoan_Chinh.md)**: Bản thảo bài báo khoa học 7 trang đầy đủ theo chuẩn Tạp chí JSTT / IEEE.
* 📋 **[chi_tiet_ra_soat_va_sua_bai_bao.md](paper/chi_tiet_ra_soat_va_sua_bai_bao.md)**: Biên bản rà soát chi tiết 17 mục góp ý và số liệu thực nghiệm định lượng.

---

## 📌 Project Overview

**Surface Rescue USV** is a low-cost, high-performance remote-controlled surface vessel engineered to rapidly approach drowning victims in calm water environments (lakes, ponds, rivers) and deploy emergency flotation devices (lifebuoys). 

* **Dual Pontoon Catamaran Hull:** Built with 90 mm PVC pipes providing **124.8 N max buoyant force** and **74.5% reserve buoyancy**.
* **Long-Range Wireless Control:** Utilizes `nRF24L01+ PA/LNA` (2.4 GHz GFSK) achieving up to **165 meters** Line-of-Sight (LOS) range with **<3% packet loss**.
* **High Thrust & Efficiency:** Powered by dual IP68 waterproof brushless thrusters (T60) delivering **1.8 m/s (~6.5 km/h)** top speed and **2.5 kgf** towing capacity.
* **Safety Failsafe:** Built-in auto-cutoff safety mechanism (stops motors within **500 ms** upon signal loss).

---

## 🛠️ Hardware Architecture & Component BOM

### System Block Diagram

```
+------------------------------------+          +------------------------------------+
|    TRANSMITTER / REMOTE (TX)       |          |        SURFACE RESCUE USV (RX)     |
|                                    |  2.4GHz  |                                    |
| [Joystick] ---> [ESP32 Transmitter]| GFSK RF  | [nRF24L01+] ---> [ESP32 Receiver]  |
|                        |           |=========>|                        |           |
|                  [nRF24L01+]       |   LOS    |                  +-----+-----+     |
|                        |           | 165m Range|                 |           |     |
|                     [Anten]        |          |               [ESC Left]  [ESC Right]|
|                                    |          |                  |           |     |
|                                    |          |              [Motor L]   [Motor R] |
+------------------------------------+          +------------------------------------+
```

See [`docs/system_architecture.md`](docs/system_architecture.md) and [`hardware/schematics/wiring_guide.md`](hardware/schematics/wiring_guide.md) for full circuit diagrams and component details.

---

## 📂 Repository Structure

```text
surface-rescue-usv/
├── paper/                                            # 📄 BÁO CÁO KHOA HỌC (ĐỂ RIÊNG)
│   ├── Bai_Bao_Robot_Cuu_Ho_Mat_Nuoc_Hoan_Chinh.md   # Bài báo khoa học chuẩn JSTT 2026
│   └── chi_tiet_ra_soat_va_sua_bai_bao.md             # Nhật ký rà soát & số liệu thực nghiệm
├── firmware/                                         # 💻 MÃ NGUỒN CỐT LÕI (FIRMWARE)
│   ├── transmitter_tx/                               # Firmware ESP32 phía tay điều khiển TX
│   │   └── transmitter_tx.ino
│   └── receiver_usv_rx/                              # Firmware ESP32 phía robot USV RX
│       └── receiver_usv_rx.ino
├── hardware/                                         # 📐 THIẾT KẾ PHẦN CỨNG & CƠ KHÍ
│   ├── mechanical_cad/                               # Thông số kết cấu phao PVC Catamaran
│   │   └── pvc_pontoon_specs.md
│   └── schematics/                                   # Sơ đồ nối dây chi tiết
│       └── wiring_guide.md
├── docs/                                             # 📚 TÀI LIỆU KIẾN TRÚC HỆ THỐNG
│   └── system_architecture.md
├── .gitignore                                        # Đã cấu hình bỏ file tạm
├── LICENSE                                           # Giấy phép nguồn mở (MIT License)
└── README.md                                         # Trang giới thiệu chính dự án
```

---

## ⚡ Getting Started & Firmware Flashing

1. Open `firmware/transmitter_tx/transmitter_tx.ino` in Arduino IDE / PlatformIO and upload to the Remote Control ESP32.
2. Open `firmware/receiver_usv_rx/receiver_usv_rx.ino` and upload to the USV Robot ESP32.
3. Power on the Remote Control first, then connect the LiPo 4S battery to the USV.

---

## 📄 Citation

If you use this project or research paper, please cite:
```bibtex
@article{Hieu2026SurfaceRescueUSV,
  title={Thiết kế và chế tạo mô hình robot cứu hộ mặt nước điều khiển từ xa},
  author={Trần Trung Hiếu and Bùi Diệu Linh},
  journal={Tạp chí Khoa học và Công nghệ (JSTT)},
  year={2026},
  volume={JSTT-2026-USV01}
}
```

**Developed by Tran Trung Hieu & Bui Dieu Linh (2026).**
