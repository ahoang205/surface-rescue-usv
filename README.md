# THIẾT KẾ VÀ CHẾ TẠO MÔ HÌNH ROBOT CỨU HỘ MẶT NƯỚC ĐIỀU KHIỂN TỪ XA
### (Design and Fabrication of a Remote-Controlled Surface Rescue Robot Model)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![MCU: ESP32](https://img.shields.io/badge/MCU-ESP32--WROOM--32-blue.svg)](https://www.espressif.com/)
[![RF: nRF24L01+](https://img.shields.io/badge/RF-nRF24L01%2B%202.4GHz-green.svg)](https://www.nordicsemi.com/)
[![Status: Tested in Field](https://img.shields.io/badge/Status-Field%20Tested%20%26%20Verified-brightgreen.svg)]()

> **BÁO CÁO NGHIÊN CỨU & NGUỒN MỞ DỰ ÁN CƠ ĐIỆN TỬ - HỆ THỐNG USV CỨU HỘ MẶT NƯỚC**  
> **Tác giả:** Trần Trung Hiếu, Bùi Diệu Linh (2026)  
> **Repository:** [https://github.com/ahoang205/surface-rescue-usv](https://github.com/ahoang205/surface-rescue-usv)

---

## 📌 TÓM TẮT BÁO CÁO (ABSTRACT)

Báo cáo trình bày chi tiết nghiên cứu thiết kế, chế tạo và thử nghiệm thực địa mô hình robot cứu hộ mặt nước điều khiển từ xa dạng phương tiện mặt nước không người lái (Unmanned Surface Vehicle - USV). Hệ thống được định hướng cho nhiệm vụ di chuyển tiếp cận nhanh nạn nhân gặp sự cố đuối nước trên mặt nước tĩnh (hồ, ao, sông nhỏ) và vận chuyển phao cứu sinh trợ nổi khẩn cấp, giúp kéo dài thời gian sống sót của nạn nhân trước khi lực lượng cứu hộ tới nơi. 

Cấu trúc cốt lõi của robot sử dụng vi điều khiển trung tâm ESP32 kết hợp với module truyền nhận sóng vô tuyến tầm xa nRF24L01+ PA/LNA hoạt động ở dải tần 2,4 GHz theo phương thức điều chế GFSK. Thân vỏ robot dạng phao đôi Catamaran được thiết chế từ 2 ống nhựa PVC 90 mm, đạt tổng lực nổi cực đại 124,8 N và độ nổi dự trữ lớn (~74,5%), đảm bảo khả năng tự cân bằng tĩnh ổn định với trọng tâm thấp. Động cơ đẩy chìm không chổi than (Brushless Thruster) chuẩn kháng nước IP68 kết hợp với bộ điều tốc ESC 30A cho phép robot đạt tốc độ di chuyển tối đa 1,8 m/s (~6,5 km/h) và lực kéo phao $2{,}5\text{ kgf}$. Thử nghiệm thực tế tại hồ nước tĩnh khẳng định cự ly điều khiển tin cậy tầm nhìn thẳng (LOS) đạt 165 m với tỉ lệ rớt gói tin $< 3\%$, thời gian vận hành liên tục 28,5 phút với khối pin LiPo 4S 4500 mAh.

**Từ khóa:** *Robot cứu hộ mặt nước; Phương tiện mặt nước không người lái (USV); Điều khiển từ xa; nRF24L01+; Phao cứu sinh; ESP32.*

---

## 1. MỞ ĐẦU & TÍNH CẤP THIẾT CỦA ĐỀ TÀI

### 1.1. Thực trạng tai nạn đuối nước
Theo Báo cáo tình hình phòng chống đuối nước toàn cầu của Tổ chức Y tế Thế giới (WHO), tai nạn đuối nước cướp đi khoảng **300.000 sinh mạng mỗi năm** trên toàn thế giới [1]. Trong đó, hơn 92% số ca tử vong xảy ra tại các quốc gia có thu nhập thấp và trung bình (LMICs), và đối tượng chịu ảnh hưởng nặng nề nhất là trẻ em và thanh thiếu niên.

### 1.2. Giải pháp Robot Cứu hộ Mặt nước (USV)
Trong các sự cố tai nạn sông nước, "thời gian vàng" để hỗ trợ nạn nhân chỉ kéo dài trong vài phút trước khi nạn nhân bị kiệt sức. Cứu hộ thủ công bơi trực tiếp đòi hỏi thể lực tốt và tiềm ẩn nguy hiểm cho chính người cứu nạn. Việc ứng dụng **phương tiện mặt nước không người lái (USV)** di chuyển tốc độ cao để mang phao cứu sinh tới vị trí nạn nhân là giải pháp hỗ trợ khẩn cấp mang tính khả thi và an toàn cao [2, 3].

### 1.3. Mục tiêu nghiên cứu
1. Chế tạo khung phao đôi Catamaran từ nhựa PVC giá thành tối ưu, có độ nổi dự trữ lớn (~75%) và tự cân bằng tĩnh tốt trên mặt nước.
2. Thiết kế mạch điều khiển không dây tầm xa dựa trên ESP32 và nRF24L01+ PA/LNA (2,4 GHz GFSK), điều khiển tốc độ vi phân với độ trễ thấp ($< 35\text{ ms}$).
3. Đo đạc thử nghiệm định lượng tốc độ di chuyển, cự ly truyền thông thực tế (LOS), tỉ lệ rớt gói tin và thời gian xả pin dưới tải.

---

## 2. THIẾT KẾ VÀ CHẾ TẠO HỆ THỐNG

### 2.1. Cấu trúc tổng quan
Hệ thống gồm 2 phân hệ: **Tay điều khiển cầm tay (TX)** và **Robot cứu hộ mặt nước (RX)**.

```
+------------------------------------+          +------------------------------------+
|    TAY ĐIỀU KHIỂN CẦM TAY (TX)     |          |       ROBOT CỨU HỘ MẶT NƯỚC (RX)   |
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

### 2.2. Danh mục Linh kiện Phần cứng (BOM)

| STT | Linh kiện | Model / Thông số kỹ thuật chi tiết | Vai trò trong hệ thống |
| :--- | :--- | :--- | :--- |
| 1 | Board điều khiển | **ESP32 DevKit V1** (Dual-core 240 MHz, Flash 4MB, ADC 12-bit) | Xử lý trung tâm, phát xung PWM phần cứng |
| 2 | Module thu phát RF | **nRF24L01+ PA/LNA** (ISM 2,4 GHz, anten SMA 2dBi, công suất +20 dBm) | Truyền nhận dữ liệu điều khiển không dây tầm xa |
| 3 | Động cơ đẩy | **Brushless Thruster T60** (Công suất 30–200W, lực đẩy 2,5 kgf, IP68) | Tạo lực đẩy vi phân di chuyển robot |
| 4 | Bộ điều tốc ESC | **ESC Brushless 30A** (Tín hiệu PWM 50 Hz, dải 1000–2000 µs) | Điều khiển tốc độ quay động cơ |
| 5 | Nguồn năng lượng | **Khối pin LiPo 4S** (14,8 V – 4500 mAh 35C + BMS) | Cung cấp nguồn năng lượng chính |
| 6 | Mạch hạ áp | **LM2596S DC-DC Step-Down** (Vào 14,8V -> Ra 5V/3A) | Cấp nguồn ổn định cho bo mạch vi điều khiển |

---

### 2.3. Tính toán Động lực học Nổi & Cân bằng

#### Tính toán lực đẩy Archimedes lý thuyết cực đại:
Phao đôi Catamaran sử dụng 2 ống PVC đường kính ngoài $D = 0{,}09\text{ m}$ (90 mm), chiều dài mỗi ống $L = 1{,}0\text{ m}$. Thể tích ngoài 1 mét ống:
\[ V_{1m} = \pi \cdot \frac{D^2}{4} \cdot 1{,}0 = \pi \cdot \frac{0{,}09^2}{4} \cdot 1{,}0 \approx 0{,}00636\text{ m}^3 \]

Lực đẩy Archimedes cực đại trên mỗi mét ống khi ngập hoàn toàn trong nước ($\rho = 1000\text{ kg/m}^3$, $g = 9{,}81\text{ m/s}^2$):
\[ F_{A,max/m} = \rho \cdot g \cdot V_{1m} = 1000 \cdot 9{,}81 \cdot 0{,}00636 \approx 62{,}4\text{ N/m} \]

Tổng lực nổi cực đại của hệ phao đôi (tổng chiều dài 2,0 m ống):
\[ F_{A,total} = 2 \cdot 62{,}4 = 124{,}8\text{ N} \quad (\approx 12{,}7\text{ kgf}) \]

#### Tính toán độ nổi dự trữ và mớn nước tĩnh:
Khối lượng toàn bộ robot khi lắp hoàn chỉnh $m = 3{,}25\text{ kg}$ (trọng lượng $P \approx 31{,}88\text{ N}$).  
Độ nổi dự trữ $R_b$ của robot:
\[ R_b = \frac{F_{A,total} - P}{F_{A,total}} \cdot 100\% = \frac{124{,}8 - 31{,}88}{124{,}8} \cdot 100\% \approx 74{,}45\% \]

Tỉ lệ nổi dự trữ cao (~74,5%) giữ mớn nước tĩnh (Draft) ở mức 45 mm (25% chiều cao phao), giúp bo mạch điều khiển và pin luôn khô ráo và cách xa mặt nước 150 mm.

---

## 3. THUẬT TOÁN ĐIỀU KHIỂN VÀ PHẦN MỀM

### 3.1. Thuật toán điều khiển lực đẩy vi phân
Tín hiệu đọc từ Joystick tay điều khiển gồm Tốc độ ($\tau \in [-1000, 1000]$) và Hướng lái ($\sigma \in [-1000, 1000]$). Giá trị điều khiển động cơ trái ($u_L$) và phải ($u_R$):
\[ u_L = sat(\tau + k \cdot \sigma), \quad u_R = sat(\tau - k \cdot \sigma) \quad (k = 0{,}7) \]

Ánh xạ sang độ rộng xung PWM $T_{PWM}$ cho ESC một chiều (50 Hz):
\[ T_{PWM} = 1000 + u \quad (\mu s) \quad \text{với } u \in [0, 1000] \]

### 3.2. Cơ chế An toàn Failsafe tự động
Chương trình trên ESP32 chạy chu kỳ vòng lặp 20 ms (50 Hz). Tích hợp bộ đếm thời gian an toàn **Failsafe**: Nếu sau $500\text{ ms}$ liên tục rớt sóng nRF24L01+, ESP32 tự động ngắt xung ga về $1000\ \mu s$ (dừng động cơ hoàn toàn), tránh sự cố robot trôi dạt mất kiểm soát.

---

## 4. KẾT QUẢ THỬ NGHIỆM ĐỊNH LƯỢNG

**Bảng tổng hợp số liệu đo đạc thực nghiệm trên mặt nước tĩnh:**

| STT | Thông số đo đạc | Giá trị thực đo | Phương pháp / Thiết bị kiểm chứng |
| :--- | :--- | :--- | :--- |
| 1 | Kích thước tổng thể | $1000 \times 450 \times 250\text{ mm}$ | Đo bằng thước kẹp & thước dây chuẩn |
| 2 | Khối lượng toàn bộ robot | $3{,}25\text{ kg}$ | Cân điện tử độ chính xác $\pm 5\text{ g}$ |
| 3 | Mớn nước tĩnh (Draft) | $45\text{ mm}$ | Đo mực nước thực tế trên thân phao PVC |
| 4 | Tốc độ di chuyển tối đa | $1{,}8\text{ m/s}$ (~6,5 km/h) | Đo bằng module GPS Neo-6M trên đường chạy 50 m |
| 5 | Cự ly điều khiển tối đa (LOS) | $165\text{ m}$ | Thử nghiệm hồ tĩnh, tỉ lệ rớt gói tin $< 3\%$ |
| 6 | Độ trễ phản hồi lệnh điều khiển | $35 \pm 5\text{ ms}$ | Ghi nhận timestamp Serial ngắt thu/phát |
| 7 | Thời gian tự ngắt Failsafe | $500\text{ ms}$ | Thử nghiệm ngắt nguồn tay điều khiển TX khi robot chạy |
| 8 | Thời gian hoạt động liên tục | $28{,}5\text{ phút}$ | Thử nghiệm xả pin LiPo 4S từ 16,8V xuống 14,0V |
| 9 | Lực kéo phao cứu sinh | $2{,}5\text{ kgf}$ (~24,5 N) | Đo bằng lực kế lò xo khi kéo phao tròn |

---

## 📂 CẤU TRÚC THƯ MỤC REPOSITORY (PROJECT STRUCTURE)

```text
surface-rescue-usv/
├── README.md                                         # Báo cáo tổng quan dự án
├── LICENSE                                           # Giấy phép nguồn mở (MIT License)
├── .gitignore                                        # File cấu hình lọc file rác
│
├── 📁 paper/                                            # 📄 TOÀN BỘ BÁO CÁO & BÀI BÁO KHOA HỌC
│   ├── Bai_Bao_Robot_Cuu_Ho_Mat_Nuoc_Hoan_Chinh.md   # Bản thảo bài báo khoa học 7 trang đầy đủ (JSTT 2026)
│   ├── chi_tiet_ra_soat_va_sua_bai_bao.md             # Tài liệu rà soát 17 mục & tính toán lực đẩy
│   ├── Thiết kế mô hình Robot cứu hộ dưới nước.docx   # Báo cáo Word gốc
│   └── 13. ĐTSV25-26-295.docx                        # File báo cáo đề tài gốc
│
├── 📁 firmware/                                         # 💻 MÃ NGUỒN ĐIỀU KHIỂN ESP32
│   ├── transmitter_tx/                               # Firmware Tay điều khiển TX
│   │   └── transmitter_tx.ino
│   └── receiver_usv_rx/                              # Firmware Robot USV RX (PWM 50Hz + Failsafe)
│       └── receiver_usv_rx.ino
│
├── 📁 hardware/                                         # 📐 THIẾT KẾ PHẦN CỨNG & KẾT CẤU CƠ KHÍ
│   ├── schematics/                                   # Sơ đồ nối chân GPIO & dây điện
│   │   └── wiring_guide.md
│   ├── mechanical_cad/                               # Thông số kết cấu phao PVC Catamaran
│   │   └── pvc_pontoon_specs.md
│   ├── mạch thu sóng/                                # File thiết kế mạch PCB thu sóng (STEP, PDF, BOM)
│   └── tay điều khiển/                               # Sơ đồ mạch tay điều khiển (PDF)
│
└── 📁 docs/                                             # 📚 TÀI LIỆU KIẾN TRÚC HỆ THỐNG
    └── system_architecture.md
```

---

## ⚡ HƯỚNG DẪN NẠP FIRMWARE & VẬN HÀNH

1. Mở phần mềm **Arduino IDE 2.x** hoặc **VS Code + PlatformIO**.
2. Thêm bo mạch ESP32 và cài đặt 2 thư viện: `RF24` (by TMRh20) và `ESP32Servo`.
3. Nạp `firmware/transmitter_tx/transmitter_tx.ino` cho ESP32 phía Tay điều khiển.
4. Nạp `firmware/receiver_usv_rx/receiver_usv_rx.ino` cho ESP32 phía Robot.
5. **Quy trình bật nguồn:** Bật nguồn Tay điều khiển trước -> Cắm pin LiPo cho Robot -> Chờ ESC phát tiếng bíp ngắt lệnh khởi động -> Thao tác Joystick để điều khiển robot.

---

## 📄 TÀI LIỆU THAM KHẢO (REFERENCES)

[1] World Health Organization (WHO), *Global status report on drowning prevention 2024*, Geneva: World Health Organization, 2024.  
[2] H. M. Tran, V. H. Nguyen, and T. A. Le, "Design and Control of an Unmanned Surface Vehicle for Water Quality Monitoring and Search-and-Rescue Operations," *IEEE Access*, vol. 11, pp. 45210–45222, 2023.  
[3] A. Bonfitto and N. Amati, "Model-based Control Design for Unmanned Surface Vehicles in Search and Rescue Scenarios," *Ocean Engineering*, vol. 268, p. 113420, 2023.  
[4] Y. Zhang, W. Liu, and X. Chen, "Path Planning and Control of USV for Emergency Water Rescue in Complex Environments," *Journal of Marine Science and Engineering*, vol. 12, no. 3, p. 412, 2024.  
[5] Espressif Systems, *ESP32 Series Datasheet v4.2*, Espressif Systems Co., Ltd., 2024.  
[6] Nordic Semiconductor, *nRF24L01+ Single Chip 2.4GHz Transceiver Product Specification v1.0*, Nordic Semiconductor ASA, 2023.
