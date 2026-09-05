# TẠP CHÍ KHOA HỌC VÀ CÔNG NGHỆ (JSTT 2026)

**Mã bài báo:** JSTT-2026-USV01  
**Ngày nộp bài:** 04/09/2026 | **Ngày chấp nhận:** 15/09/2026 | **Ngày đăng bài:** 20/09/2026  
**Tác giả liên hệ:** Trần Trung Hiếu (Email: hieutt@domain.edu.vn)

---

# THIẾT KẾ VÀ CHẾ TẠO MÔ HÌNH ROBOT CỨU HỘ MẶT NƯỚC ĐIỀU KHIỂN TỪ XA
### DESIGN AND FABRICATION OF A REMOTE-CONTROLLED SURFACE RESCUE ROBOT MODEL

**Trần Trung Hiếu$^{1,*}$, Bùi Diệu Linh$^1$**  
$^1$ *Trường Đại học Kỹ thuật, Việt Nam*  
*(*Email tác giả liên hệ: hieutt@domain.edu.vn)*

---

### TÓM TẮT

Bài báo trình bày thiết kế và chế tạo mô hình robot cứu hộ mặt nước điều khiển từ xa dạng phương tiện mặt nước không người lái (Unmanned Surface Vehicle - USV). Mô hình được định hướng cho nhiệm vụ tiếp cận nhanh nạn nhân gặp sự cố đuối nước trên mặt nước tĩnh và vận chuyển phao cứu sinh trợ nổi, giúp kéo dài thời gian sống sót của nạn nhân trước khi lực lượng cứu hộ chuyên nghiệp tiếp cận. Hệ thống sử dụng vi điều khiển trung tâm ESP32 kết hợp với module truyền nhận không dây nRF24L01+ PA/LNA hoạt động ở dải tần 2,4 GHz theo phương thức điều chế GFSK. Khung vỏ robot được xây dựng theo kết cấu phao đôi Catamaran từ ống nhựa PVC 90 mm, đảm bảo tổng lực nổi cực đại 124,8 N và độ nổi dự trữ 74,8%, giữ cho hệ thống nổi ổn định với trọng tâm đặt thấp. Động cơ đẩy chìm không chổi than (Brushless Thruster) kháng nước chuẩn IP68 kết hợp với bộ điều tốc ESC 30A cho phép robot đạt tốc độ di chuyển tối đa 1,8 m/s (~6,5 km/h). Thử nghiệm thực tế tại hồ nước tĩnh chứng minh robot duy trì kết nối điều khiển tin cậy ở khoảng cách tầm nhìn thẳng (LOS) lên đến 165 m với tỉ lệ rớt gói tin dưới 3%, thời gian vận hành liên tục đạt 28,5 phút với khối pin LiPo 4S 4500 mAh. Các hạn chế về bộ điều tốc một chiều và phương hướng nâng cấp hệ thống định vị GPS cũng được thảo luận chi tiết.

**Từ khóa:** *Robot cứu hộ mặt nước; Phương tiện mặt nước không người lái (USV); Điều khiển từ xa; nRF24L01+; Phao cứu sinh.*

---

### ABSTRACT

This paper presents the design and fabrication of a remote-controlled surface rescue robot model based on an Unmanned Surface Vehicle (USV) architecture. The system is engineered to rapidly approach drowning victims in calm water environments and deploy emergency flotation lifebuoys, prolonging survival time prior to the arrival of professional rescue teams. The hardware architecture incorporates an ESP32 microcontroller as the central processing unit and an nRF24L01+ PA/LNA wireless transceiver module operating at 2.4 GHz with GFSK modulation. The hull structure adopts a Catamaran dual-pontoon configuration made from 90 mm PVC pipes, providing a maximum buoyant force of 124.8 N and a reserve buoyancy of 74.8%, which guarantees static stability with a low center of gravity. Powered by IP68 waterproof brushless thrusters and 30A Electronic Speed Controllers (ESCs), the robot achieves a maximum cruising speed of 1.8 m/s (~6.5 km/h). Experimental field trials conducted in calm lake conditions demonstrate a reliable wireless control range up to 165 m under Line-of-Sight (LOS) conditions with a packet loss rate below 3%, and a continuous operational runtime of 28.5 minutes using a 4S 4500 mAh LiPo battery pack. Current limitations regarding unidirectional ESC drive and future perspectives on GPS navigation integration are also thoroughly addressed.

**Keywords:** *Surface rescue robot; Unmanned Surface Vehicle (USV); Remote control; nRF24L01+; Lifebuoy.*

---

## 1. MỞ ĐẦU (INTRODUCTION)

Tai nạn đuối nước là một trong những hiểm họa toàn cầu nghiêm trọng đối với sức khỏe cộng đồng. Theo Báo cáo tình hình phòng chống đuối nước toàn cầu của Tổ chức Y tế Thế giới (WHO), mỗi năm có khoảng 300.000 người tử vong do đuối nước trên toàn thế giới [1]. Đáng chú ý, hơn 92% số ca tử vong xảy ra tại các quốc gia có thu nhập thấp và trung bình (LMICs), trong đó trẻ em và thanh thiếu niên là nhóm đối tượng chịu ảnh hưởng nặng nề nhất. Tại Việt Nam, với hệ thống sông hồ và bờ biển kéo dài, đuối nước vẫn luôn là nguyên nhân hàng đầu gây tử vong do chấn thương không cố ý.

Trong các sự cố đuối nước, "thời gian vàng" để cứu trợ nạn nhân chỉ kéo dài trong vài phút ngắn ngủi trước khi nạn nhân bị kiệt sức hoặc chìm. Việc cứu hộ thủ công bằng bơi lội trực tiếp đòi hỏi lực lượng phản ứng nhanh và thường tiềm ẩn rủi ro nguy hiểm cho chính người cứu hộ. Do đó, việc nghiên cứu phát triển các phương tiện mặt nước không người lái (Unmanned Surface Vehicle - USV) hỗ trợ cứu hộ từ xa đang trở thành xu hướng kỹ thuật cấp thiết [2, 3].

Tuy nhiên, các dòng USV cứu hộ thương mại hiện nay thường có chi phí chế tạo rất cao, kích thước lớn và đòi hỏi hạ tầng bảo dưỡng phức tạp, khó triển khai đại trà tại các vùng sông nước nông thôn. Các nghiên cứu robot cứu hộ học thuật trước đây thường gặp phải một số hạn chế: (i) Chưa phân định rõ bản chất phương tiện mặt nước (USV) và thiết bị lặn dưới nước (ROV/AUV); (ii) Thiếu các tính toán động lực học nổi và thử nghiệm định lượng về cự ly truyền thông cũng như thời lượng pin [4].

Xuất phát từ thực tiễn đó, bài báo này tập trung nghiên cứu thiết kế, chế tạo và thử nghiệm mô hình **Robot cứu hộ mặt nước điều khiển từ xa** với các đóng góp chính bao gồm:
1. Xây dựng kết cấu phao đôi Catamaran tối ưu từ vật liệu nhựa PVC giá thành thấp, có độ nổi dự trữ lớn (~75%) và cân bằng tĩnh ổn định trên mặt nước.
2. Thiết kế hệ thống điều khiển trung tâm trên cơ sở vi điều khiển ESP32 và module thu phát RF nRF24L01+ PA/LNA dải 2,4 GHz sử dụng điều chế GFSK, đảm bảo điều khiển mượt mà với độ trễ thấp ở khoảng cách xa.
3. Thực nghiệm định lượng toàn diện trên mặt nước tĩnh nhằm xác định tốc độ di chuyển, cự ly truyền thông thực tế (LOS), tỉ lệ rớt gói tin và thời gian xả pin dưới tải.

---

## 2. THIẾT KẾ VÀ CHẾ TẠO HỆ THỐNG (SYSTEM DESIGN AND FABRICATION)

### 2.1. Cấu trúc tổng quan và nguyên lý hoạt động

Hệ thống robot cứu hộ mặt nước bao gồm hai phân hệ chính: **Bộ điều khiển cầm tay (Transmitter - TX)** và **Robot cứu hộ mặt nước (Receiver - RX)**. Sơ đồ khối chức năng tổng quan của hệ thống được thể hiện trong **Hình 1**.

```
+------------------------------------+          +------------------------------------+
|     BỘ ĐIỀU KHIỂN CẦM TAY (TX)     |          |       ROBOT CỨU HỘ MẶT NƯỚC (RX)   |
|                                    |  2.4GHz  |                                    |
| [Joystick] ---> [ESP32 Transmitter]| GFSK RF  | [nRF24L01+] ---> [ESP32 Receiver]  |
|                        |           |=========>|                        |           |
|                  [nRF24L01+]       |   LOS    |                  +-----+-----+     |
|                        |           |          |                  |           |     |
|                     [Anten]        |          |               [ESC Left]  [ESC Right]|
|                                    |          |                  |           |     |
|                                    |          |              [Motor L]   [Motor R] |
|                                    |          |                  |           |     |
|                                    |          |             (Chân vịt)   (Chân vịt)|
+------------------------------------+          +------------------------------------+
```
*Hình 1. Sơ đồ khối cấu trúc hệ thống robot cứu hộ mặt nước điều khiển từ xa*

Khi người điều khiển thao tác trên Joystick, ESP32 phía TX đọc tín hiệu điện áp tương tự (ADC 12-bit), đóng gói dữ liệu và gửi qua module nRF24L01+ qua sóng vô tuyến 2,4 GHz. Phía Robot, module nRF24L01+ nhận gói tin, truyền về ESP32 phía RX giải mã thành các lệnh điều khiển độ rộng xung PWM (1000–2000 µs) cung cấp cho hai bộ điều tốc ESC. Hai động cơ chìm không chổi than hoạt động độc lập để tạo lực đẩy vi phân (Differential Thrust), giúp robot tiến, rẽ trái, rẽ phải và quay đầu linh hoạt trên mặt nước.

---

### 2.2. Thiết kế phần cứng và lựa chọn linh kiện

Các linh kiện phần cứng được lựa chọn dựa trên tiêu chí tính sẵn có, khả năng kháng nước, hiệu suất năng lượng và độ tin cậy. Thông số kỹ thuật chi tiết của các thành phần phần cứng được tổng hợp trong **Bảng 1**.

**Bảng 1. Thông số kỹ thuật chi tiết của các thành phần phần cứng hệ thống**

| STT | Linh kiện | Model / Thông số kỹ thuật chi tiết | Vai trò trong hệ thống |
| :--- | :--- | :--- | :--- |
| 1 | Board điều khiển trung tâm | **ESP32 DevKit V1** (Module ESP32-WROOM-32, CPU Xtensa 32-bit dual-core 240 MHz, SRAM 520 KB, Flash 4MB, ADC 12-bit) | Xử lý thuật toán, giải mã lệnh, phát xung PWM phần cứng |
| 2 | Module thu phát RF | **nRF24L01+ PA/LNA** (ISM 2,4 GHz, tích hợp bộ khuếch đại công suất PA và anten SMA 2 dBi, công suất phát +20 dBm) | Truyền nhận dữ liệu điều khiển không dây tầm xa |
| 3 | Động cơ đẩy | **Brushless Thruster T60** (Động cơ chìm không chổi than, công suất 30–200 W, lực đẩy cực đại 2,5 kgf tại 16,8 V, kháng nước IP68) | Tạo lực đẩy vi phân di chuyển robot |
| 4 | Bộ điều tốc động cơ | **ESC Brushless 30A** (Điện áp 2S-4S LiPo, dòng đỉnh 40A, nhận tín hiệu PWM chuẩn 50 Hz) | Điều khiển tốc độ quay động cơ |
| 5 | Nguồn năng lượng | **Khối pin LiPo 4S** (14,8 V – 4500 mAh 35C, tích hợp mạch bảo vệ BMS) | Cung cấp nguồn điện năng cho hệ thống |
| 6 | Mạch hạ áp nguồn | **LM2596S DC-DC Step-Down** (Điện áp vào 4,5-40V, đầu ra 5V/3A) | Cấp nguồn ổn định 5V cho ESP32 và nRF24L01+ |

---

### 2.3. Thiết kế kết cấu cơ khí và tính toán động lực học nổi

Khung vỏ robot được thiết kế dạng **Catamaran (phao đôi)** nhằm đạt độ ổn định ngang cực đại và giảm lực cản ma sát đường rẽ nước. Phao được chế tạo từ 2 ống nhựa PVC đường kính ngoài $D = 0{,}09\text{ m}$ (90 mm), chiều dài mỗi ống $L = 1{,}0\text{ m}$.

#### Tính toán lực đẩy Archimedes lý thuyết cực đại:
Thể tích chiếm chỗ ngoài cực đại của một mét ống PVC 90 mm được tính theo công thức:
\[ V_{1m} = \pi \cdot \frac{D^2}{4} \cdot L = \pi \cdot \frac{0{,}09^2}{4} \cdot 1{,}0 \approx 0{,}00636\text{ m}^3 \]

Lực đẩy Archimedes cực đại trên mỗi mét ống khi chìm hoàn toàn trong nước ngọt ($\rho = 1000\text{ kg/m}^3$, $g = 9{,}81\text{ m/s}^2$) là:
\[ F_{A,max/m} = \rho \cdot g \cdot V_{1m} = 1000 \cdot 9{,}81 \cdot 0{,}00636 \approx 62{,}4\text{ N/m} \]

Tổng lực nổi cực đại của hệ phao đôi (tổng chiều dài 2,0 m ống):
\[ F_{A,total} = 2 \cdot F_{A,max/m} = 2 \cdot 62{,}4 = 124{,}8\text{ N} \quad (\approx 12{,}7\text{ kgf}) \]

#### Tính toán độ nổi dự trữ và mớn nước tĩnh:
Khối lượng toàn bộ robot khi lắp hoàn chỉnh là $m = 3{,}25\text{ kg}$, tương ứng trọng lượng tổng $P = m \cdot g = 3{,}25 \cdot 9{,}81 = 31{,}88\text{ N}$.  
Độ nổi dự trữ $R_b$ của robot được xác định:
\[ R_b = \frac{F_{A,total} - P}{F_{A,total}} \cdot 100\% = \frac{124{,}8 - 31{,}88}{124{,}8} \cdot 100\% \approx 74{,}45\% \]

Tỉ lệ nổi dự trữ cao (~74,5%) giúp mớn nước tĩnh (Draft) của robot chỉ chiếm khoảng 25% chiều cao phao (~45 mm), giữ cho khoang bo mạch điều khiển và khối pin luôn cách xa mặt nước tĩnh 150 mm, tránh nguy cơ ngập nước.

#### Phân tích tính ổn định cân bằng tĩnh (CG - CB):
Do khối pin LiPo nặng nhất và hai động cơ chìm được bố trí dưới đáy khoang phao, Trọng tâm của toàn hệ thống (Center of Gravity - CG) nằm thấp hơn đáng kể so với Tâm nổi tĩnh (Center of Buoyancy - CB). Khoảng cách $CG - CB$ dương kết hợp với khoảng cách rộng giữa hai thân phao ($350\text{ mm}$) tạo nên tay đòn đung đung phục hồi lớn, đảm bảo tính tự cân bằng tĩnh, chống lật ngang/lật dọc tốt khi gặp sóng nhỏ trên mặt nước tĩnh.

---

### 2.4. Phân hệ truyền thông vô tuyến tầm xa nRF24L01+

Để đảm bảo khả năng điều khiển ổn định trong môi trường mặt nước có hiện tượng phản xạ sóng vô tuyến, hệ thống sử dụng module **nRF24L01+ PA/LNA** tích hợp bộ khuếch đại công suất PA (Power Amplifier) và bộ khuếch đại nhiễu thấp LNA (Low Noise Amplifier).

* **Phương thức điều chế:** Dữ liệu được điều chế dạng **GFSK (Gaussian Frequency Shift Keying)** trên dải tần ISM 2,4 GHz, giúp tối ưu băng thông và kháng nhiễu tần số hiệu quả.
* **Giao tiếp phần cứng:** Module nRF24L01+ giao tiếp với ESP32 qua chuẩn SPI 4 dây bao gồm: `SCK` (GPIO18), `MOSI` (GPIO23), `MISO` (GPIO19), `CSN` (GPIO5), kết hợp với chân điều khiển trạng thái vi mạch `CE` (GPIO4). Chân ngắt tín hiệu `IRQ` (GPIO2) được cấu hình ngắt phần cứng nhận dữ liệu tự động.
* **Nguồn cấp tín hiệu:** Nguồn 3,3V cấp cho nRF24L01+ được lọc nhiễu bằng tụ hóa 10 µF kết hợp tụ gốm 0,1 µF đấu song song song sát chân nguồn module để ngăn ngừa sụt áp khi phát công suất cực đại (+20 dBm).

---

## 3. THUẬT TOÁN ĐIỀU KHIỂN VÀ PHẦN MỀM (CONTROL ALGORITHM AND SOFTWARE)

### 3.1. Thuật toán điều khiển lực đẩy vi phân

Robot sử dụng cơ chế lái vi phân (Differential Steering) bằng cách thay đổi tốc độ quay tương đối giữa hai động cơ trái ($M_L$) và phải ($M_R$). Tín hiệu đọc từ Joystick tay điều khiển gồm biến Tốc độ (Throttle $\tau \in [-1000, 1000]$) và biến Hướng lái (Steering $\sigma \in [-1000, 1000]$).

Tín hiệu điều khiển cơ sở $u_L$ và $u_R$ cho hai động cơ được tính toán theo công thức:
\[ u_L = sat(\tau + k \cdot \sigma) \]
\[ u_R = sat(\tau - k \cdot \sigma) \]

Trong đó $k = 0{,}7$ là hệ số nhạy hướng lái, và hàm bão hòa $sat(x)$ giới hạn giá trị trong khoảng $[0, 1000]$.

#### Ánh xạ sang tín hiệu xung PWM cho ESC một chiều:
Bộ điều tốc ESC sử dụng trong mô hình thử nghiệm là loại một chiều (Unidirectional ESC), tiếp nhận tín hiệu điều khiển xung PWM có độ rộng chuẩn từ 1000 µs đến 2000 µs (tần số 50 Hz). Do đó, giá trị $u \in [0, 1000]$ được ánh xạ trực tiếp sang độ rộng xung PWM $T_{PWM}$ theo công thức:
\[ T_{PWM} = 1000 + u \quad (\mu s) \]

* Khi $u = 0$ ($T_{PWM} = 1000\ \mu s$): Động cơ ở trạng thái dừng (0% ga).
* Khi $u = 1000$ ($T_{PWM} = 2000\ \mu s$): Động cơ quay với 100% công suất tối đa.

---

### 3.2. Cấu trúc phần mềm và cơ chế An toàn (Failsafe)

Chương trình điều khiển trên ESP32 được xây dựng trên nền hệ điều hành thời gian thực (FreeRTOS) để quản lý đa nhiệm mượt mà. Động lực học vòng lặp được mô tả trong **Hình 2**.

```
[Khởi tạo Hệ thống (SPI, PWM 50Hz, nRF24)]
                |
                v
       [Kiểm tra Ngắt nRF24]
          /            \
     (Có gói tin)   (Mất kết nối > 500ms)
        /                \
       v                  v
[Giải mã Joystick]   [KÍCH HOẠT FAILSAFE]
       |                  |
       v                  v
[Tính u_L, u_R]      [Gán u_L=0, u_R=0]
       |                  |
       +--------+---------+
                |
                v
  [Phát PWM 50Hz tới 2 ESC]
                |
                v
     [Delay Vòng lặp 20ms]
```
*Hình 2. Lưu đồ thuật toán thực thi và cơ chế an toàn Failsafe*

1. **Tần số vòng lặp:** Vòng lặp điều khiển chính được thiết lập chu kỳ lấy mẫu và tính toán $T_{loop} = 20\text{ ms}$ (tần số 50 Hz). Tín hiệu điều khiển xung PWM gửi tới ESC được tạo ra thông qua bộ tạo xung phần cứng LEDC của ESP32 ở tần số 50 Hz (chu kỳ 20 ms, độ phân giải 16-bit), đảm bảo sự đồng bộ hoàn toàn giữa thuật toán phần mềm và tần số đáp ứng phần cứng của ESC.
2. **Cơ chế an toàn Failsafe:** Để phòng ngừa sự cố robot chạy mất kiểm soát khi vượt quá cự ly truyền thông hoặc bị nhiễu sóng mạnh, chương trình tích hợp bộ đếm thời gian Failsafe. Nếu sau $500\text{ ms}$ liên tục mà ESP32 phía RX không nhận được gói tin hợp lệ từ TX, hệ thống sẽ tự động ngắt công suất hai động cơ ($T_{PWM} = 1000\ \mu s$), giữ robot dừng nổi an toàn trên mặt nước.

---

## 4. KẾT QUẢ THỬ NGHIỆM VÀ ĐÁNH GIÁ (EXPERIMENTAL RESULTS AND EVALUATION)

### 4.1. Mô hình thực nghiệm và môi trường thử nghiệm

Mô hình robot cứu hộ mặt nước hoàn thiện có tổng chiều dài 1000 mm, chiều rộng 450 mm, chiều cao 250 mm. Thử nghiệm thực địa được tiến hành tại hồ nước tĩnh với điều kiện thời tiết nắng nhẹ, gió nhẹ (vận tốc gió $< 2\text{ m/s}$), mặt nước không có sóng lớn.

### 4.2. Số liệu thử nghiệm định lượng

Để đánh giá chính xác hiệu năng làm việc của mô hình thay vì chỉ mô tả định tính, các thông số kỹ thuật thực tế đã được đo đạc bằng thiết bị đo chuyên dụng (GPS Module, Cân điện tử, Máy hiện sóng và thiết bị đo dòng/áp) và được tổng hợp chi tiết trong **Bảng 3**.

**Bảng 3. Số liệu thực nghiệm định lượng của mô hình robot cứu hộ mặt nước**

| STT | Thông số đo đạc thực nghiệm | Giá trị đo thực tế | Điều kiện / Thiết bị đo đạc |
| :--- | :--- | :--- | :--- |
| 1 | Kích thước tổng thể (Dài × Rộng × Cao) | $1000 \times 450 \times 250\text{ mm}$ | Đo bằng thước kẹp và thước dây chuẩn |
| 2 | Khối lượng toàn bộ robot ($m$) | $3{,}25\text{ kg}$ | Cân điện tử độ chính xác $\pm 5\text{ g}$ |
| 3 | Mớn nước tĩnh thực tế (Draft) | $45\text{ mm}$ | Đo mực nước chiếm chỗ trên thân phao PVC |
| 4 | Tốc độ di chuyển tối đa ($v_{max}$) | $1{,}8\text{ m/s}$ (~6,5 km/h) | Đo bằng module GPS Neo-6M trên đoạn đường 50 m |
| 5 | Cự ly điều khiển không dây tối đa (LOS) | $165\text{ m}$ | Thử nghiệm thực địa hồ tĩnh, tỉ lệ rớt gói $< 3\%$ |
| 6 | Độ trễ phản hồi lệnh điều khiển ($\Delta t$) | $35 \pm 5\text{ ms}$ | Đo qua Serial Timestamp giữa TX và RX |
| 7 | Thời gian tự động ngắt Failsafe | $500\text{ ms}$ | Thử nghiệm tắt nguồn tay điều khiển TX khi robot chạy |
| 8 | Thời gian hoạt động liên tục (tải 60%) | $28{,}5\text{ phút}$ | Xả pin LiPo 4S từ 16,8 V xuống mức an toàn 14,0 V |
| 9 | Lực kéo phao cứu sinh cực đại | $2{,}5\text{ kgf}$ (~24,5 N) | Đo bằng lực kế lò xo khi kéo phao tròn cứu sinh |

---

### 4.3. Đánh giá đường cong sụt áp pin và tính ổn định truyền thông

#### Thực nghiệm sụt áp pin theo thời gian:
Pin LiPo 4S (14,8 V – 4500 mAh) khi sạc đầy đạt điện áp 16,8 V (4,2 V/cell). Khi robot chạy thử nghiệm liên tục ở mức ga trung bình 60% (công suất tiêu thụ trung bình xấp xỉ $95\text{ W}$), diễn biến điện áp khối pin được ghi nhận trong **Hình 3a**.

```
 Điện áp (V)
  16.8 +--*
       |   \
  16.0 +    *---*
       |         \
  15.0 +          *---*
       |               \
  14.0 +----------------* (Ngắt an toàn tại 28.5 phút)
       +----+----+----+----+----> Thời gian (phút)
       0    10   15   20   28.5
```
*Hình 3a. Đường cong sụt áp khối pin LiPo 4S theo thời gian vận hành thực tế*

Kết quả cho thấy điện áp sụt giảm tuyến tính ổn định từ 16,8 V xuống 14,8 V trong 20 phút đầu, sau đó giảm nhanh hơn từ 14,8 V xuống 14,0 V (3,5 V/cell). Hệ thống đạt thời gian vận hành thực tế $28{,}5\text{ phút}$, phù hợp với tính toán lý thuyết ước tính ($34\text{ phút}$) sau khi tính đến tổn hao nhiệt trên ESC và động cơ.

#### Thực nghiệm cự ly truyền không dây nRF24L01+:
Tỉ lệ rớt gói tin (Packet Loss Rate) theo khoảng cách truyền dẫn sóng vô tuyến tầm nhìn thẳng (LOS) trên mặt nước được ghi nhận ở **Hình 3b**.

```
 Rớt gói (%)
   10 +                                 * (Vượt ngưỡng 165m)
    5 +                            *
    2 +                  *----+----
    0 +--*----+----*-----+
       +----+----+----+----+----+----> Khoảng cách (m)
       0    50   100  150  165  200
```
*Hình 3b. Tỉ lệ rớt gói tin nRF24L01+ PA/LNA theo khoảng cách truyền dẫn LOS*

Ở cự ly từ 0 đến 100 m, tỉ lệ rớt gói tin đạt mức rất thấp ($< 1\%$), tín hiệu điều khiển phản hồi tức thì. Trong khoảng 100–150 m, tỉ lệ rớt gói dao động từ 1% đến 2,5%, robot vẫn đáp ứng mượt mà. Khi khoảng cách vượt quá 165 m, tỉ lệ rớt gói tăng nhanh trên 5% và kích hoạt cơ chế Failsafe ngắt động cơ ở khoảng cách 180 m. Số liệu này chứng minh cự ly làm việc tin cậy thực tế của hệ thống là **165 m**, đáp ứng tốt yêu cầu tác nghiệp cứu hộ ban đầu ở hồ nước ngọt tĩnh.

---

## 5. KẾT LUẬN VÀ HƯỚNG PHÁT TRIỂN (CONCLUSION AND FUTURE WORK)

### 5.1. Kết luận

Nghiên cứu đã hoàn thành việc thiết kế, chế tạo và kiểm chứng thực nghiệm mô hình **Robot cứu hộ mặt nước điều khiển từ xa**. Các kết quả chính đạt được bao gồm:
1. Chế tạo thành công kết cấu phao đôi Catamaran PVC 90 mm có khối lượng nhẹ ($3{,}25\text{ kg}$), lực nổi cực đại $124{,}8\text{ N}$, độ nổi dự trữ $74{,}45\%$, đảm bảo khả năng cân bằng tĩnh ổn định trên mặt nước.
2. Xây dựng mạch điều khiển tích hợp ESP32 và nRF24L01+ PA/LNA 2,4 GHz (GFSK), đạt cự ly điều khiển thực tế $165\text{ m}$ (LOS), độ trễ phản hồi $35\text{ ms}$ và tích hợp chế độ an toàn Failsafe tự ngắt sau $500\text{ ms}$ mất sóng.
3. Động cơ chìm IP68 giúp robot đạt tốc độ di chuyển $1{,}8\text{ m/s}$ (~6,5 km/h), lực kéo phao $2{,}5\text{ kgf}$ và thời gian vận hành liên tục $28{,}5\text{ phút}$.

### 5.2. Hạn chế và Hướng phát triển

* **Hạn chế hiện tại:** Bộ điều tốc ESC sử dụng là loại một chiều nên robot chưa có khả năng lùi bằng động cơ; hệ thống chưa tích hợp cảm biến phát hiện nạn nhân tự động và chưa có camera truyền hình ảnh thời gian thực.
* **Hướng phát triển tiếp theo:**
  1. Thay thế ESC một chiều bằng ESC hai chiều (Bidirectional ESC) để bổ sung tính năng lùi và quay trở tại chỗ.
  2. Bổ sung module định vị GPS và cảm biến la bàn số để phát triển thuật toán tự động di chuyển theo tọa độ (Waypoint Navigation) và tự động quay về vị trí xuất phát (Return-to-Home).
  3. Tích hợp camera truyền hình ảnh FPV 5,8 GHz và cơ chế nhả phao tự động thông qua ngắt Servo để nâng cao hiệu quả cứu hộ chuyên nghiệp.

---

## TÀI LIỆU THAM KHẢO (REFERENCES)

[1] World Health Organization (WHO), *Global status report on drowning prevention 2024*, Geneva: World Health Organization, 2024.

[2] H. M. Tran, V. H. Nguyen, and T. A. Le, "Design and Control of an Unmanned Surface Vehicle for Water Quality Monitoring and Search-and-Rescue Operations," *IEEE Access*, vol. 11, pp. 45210–45222, 2023.

[3] A. Bonfitto and N. Amati, "Model-based Control Design for Unmanned Surface Vehicles in Search and Rescue Scenarios," *Ocean Engineering*, vol. 268, p. 113420, 2023.

[4] Y. Zhang, W. Liu, and X. Chen, "Path Planning and Control of USV for Emergency Water Rescue in Complex Environments," *Journal of Marine Science and Engineering*, vol. 12, no. 3, p. 412, 2024.

[5] Espressif Systems, *ESP32 Series Datasheet v4.2*, Espressif Systems Co., Ltd., 2024.

[6] Nordic Semiconductor, *nRF24L01+ Single Chip 2.4GHz Transceiver Product Specification v1.0*, Nordic Semiconductor ASA, 2023.
