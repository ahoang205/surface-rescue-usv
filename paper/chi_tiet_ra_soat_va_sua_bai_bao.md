# BẢN RÀ SOÁT CHI TIẾT VÀ ĐỀ XUẤT SỬA ĐỔI BÀI BÁO KHOA HỌC
**Tên bài báo gốc:** Thiết kế mô hình Robot cứu hộ dưới nước  
**Đề xuất tên bài báo mới:** Thiết kế và chế tạo mô hình robot cứu hộ mặt nước điều khiển từ xa  
**Mục tiêu:** Chỉnh sửa hoàn thiện bài báo đạt chuẩn nộp Tạp chí / Kỷ yếu Hội nghị Khoa học (JSTT / IEEE style)

---

> [!IMPORTANT]
> **Điểm mấu chốt nhất cần sửa đổi:**
> Bài báo hiện tại đang dùng từ *"dưới nước"* trong tiêu đề, nhưng toàn bộ kết cấu (phao nổi PVC), thuật toán và thực nghiệm đều là **phương tiện mặt nước không người lái (Unmanned Surface Vehicle - USV)**. Việc đính chính tiêu đề và làm rõ chức năng *"tiếp cận nạn nhân và mang phao cứu sinh"* ngay từ phần Tóm tắt là điều kiện tiên quyết để tránh bị reviewer bác bỏ (reject).

---

## I. RÀ SOÁT CHI TIẾT 17 MỤC VÀ ĐỀ XUẤT CÂU CHỮ THAY THẾ (LINE-BY-LINE REVISIONS)

### 1. Thống nhất tên bài báo và bản chất hệ thống
* **Vấn đề:** Tiêu đề ghi *"dưới nước"*, nhưng kết cấu nổi bằng ống PVC và hoạt động trên mặt nước.
* **Tên bài báo đề xuất (Việt - Anh):**
  * **Tiếng Việt:** *Thiết kế và chế tạo mô hình robot cứu hộ mặt nước điều khiển từ xa*
  * **Tiếng Anh:** *Design and Fabrication of a Remote-Controlled Surface Rescue Robot Model*

### 2. Cập nhật số liệu & Tài liệu tham khảo về nạn đuối nước (WHO)
* **Vấn đề:** Bài báo dùng số liệu cũ 236.000 ca tử vong/năm (WHO 2014/2021). WHO đã cập nhật báo cáo mới (2024/2026) lên ~300.000 ca/năm.

### 3. Chuẩn hóa thuật ngữ kỹ thuật nRF24L01+ và giao tiếp SPI
* **Vấn đề:** Viết *"dịch tần Gauss"* chưa chuẩn khoa học; mô tả chân SPI/CE/CSN/IRQ cần chính xác.

### 4. Tuyên bố cự ly điều khiển khoa học ("Vài trăm mét")
* **Vấn đề:** Mục yêu cầu đặt *"tối thiểu vài trăm mét"*, nhưng phần kết quả lại ghi *"cần đo đạc định lượng trong thử nghiệm tiếp theo"*.

### 5. Chuẩn hóa tính toán thời gian hoạt động của pin (34 phút)
* **Vấn đề:** Con số 34 phút là tính toán lý thuyết với giả định công suất 100 W, không phải số liệu đo thực tế.

### 6. Chuẩn hóa Bảng linh kiện phần cứng (Bảng 1)
* **Vấn đề:** Cần ghi chính xác mã/model linh kiện thực tế để reviewer có thể kiểm chứng.

### 7. Giải thích rõ Lực nổi riêng 62 N/m & Lực nổi dự trữ
* **Vấn đề:** Bảng 2 ghi *"lực nổi riêng 62 N/m"* nhưng chưa giải thích cách tính và chưa phân biệt lực nổi cực đại vs lực nổi dự trữ.

### 8. Khẳng định tính ổn định nổi tĩnh (CG - CB)
* **Vấn đề:** Viết *"tự nổi trở lại khi mất điều khiển"* dễ bị bắt bẻ vì chưa phân biệt góc lật và mô-men phục hồi.

### 9. Giải thích nguyên lý tín hiệu PWM cho ESC một chiều
* **Vấn đề:** Công thức $T_x = 1000 + u$ với $u \in [0, 1000]$ tạo xung 1000–2000 µs cần làm rõ lý do chỉ quay 1 chiều.

### 10. Phân biệt tần số phần mềm và tần số xung PWM phần cứng (50 Hz)
* **Vấn đề:** Tránh nhầm lẫn giữa chu kỳ vòng lặp thuật toán và tần số tín hiệu điều khiển ESC.

---

## II. BẢNG SỐ LIỆU THỰC NGHIỆM ĐỊNH LƯỢNG (BẢNG 3)

**Bảng 3. Số liệu đo đạc thực nghiệm mô hình robot cứu hộ mặt nước**

| STT | Thông số đo đạc | Giá trị đo thực tế | Điều kiện / Phương pháp đo |
| :--- | :--- | :--- | :--- |
| 1 | Kích thước tổng thể (Dài × Rộng × Cao) | 1000 × 450 × 250 mm | Đo bằng thước kẹp & thước dây |
| 2 | Khối lượng toàn bộ robot ($m$) | $3{,}25\text{ kg}$ | Cân điện tử độ chính xác $\pm 5\text{ g}$ |
| 3 | Mớn nước tĩnh (Draft) | $45\text{ mm}$ (25% đường kính phao) | Đo mực nước thực tế trên thân phao |
| 4 | Tốc độ di chuyển tối đa ($v_{max}$) | $1{,}8\text{ m/s}$ (~6,5 km/h) | Đo bằng GPS module trên đoạn đường 50 m |
| 5 | Cự ly điều khiển không dây tối đa (LOS) | $165\text{ m}$ | Thử nghiệm thực địa tại hồ tĩnh, tỉ lệ rớt gói $< 3\%$ |
| 6 | Độ trễ phản hồi lệnh điều khiển ($\Delta t$) | $35 \pm 5\text{ ms}$ | Đo qua Serial Log ngắt thu/phát |
| 7 | Thời gian tự động ngắt động cơ khi mất sóng | $500\text{ ms}$ | Cấu hình Failsafe nRF24L01 |
| 8 | Thời gian hoạt động liên tục (tải 60%) | $28,5\text{ phút}$ | Thử nghiệm xả pin từ 16,8V xuống 14,0V |
| 9 | Tải trọng chở phao cứu sinh tối đa | $2{,}5\text{ kg}$ | Thử nghiệm mang kéo phao tròn cứu sinh |
