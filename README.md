# THE RACE AGAINST TIME
21020762 - Nguyễn Cao Đức - UET_Project

# INTRODUTINE
- Họ và tên: Nguyễn Cao Đức
- Lớp: K66CD
- Bài tập lớn: The Race Against Time (INT2215_1)
# GENERAL DESCRIPTION
- Đây là game điều khiển xe chạy đua với thời gian
- Game có kèm theo các hiệu ứng âm thanh đơn giản
- Các chức năng chính của game: bắt đầu chơi, thoát game, tạm dừng, tiếp tục, quit game, bật/tắt âm thanh
- Giới hạn thời gian chơi game: 3 phút, mỗi khi va chạm với chướng ngại vật thì thời gian chơi sẽ bị giảm đi 3s
- Link video demo: https://youtu.be/YNEf0xwzLW8
- Trong video, ban đầu để thời gian render ra đích của game là sau 10s để có thể thấy rõ được điều gì xảy ra khi ta thắng game, sau đó, thời gian render đích đến được sửa lại thành sau khi ta start game 170s, như vậy ta chỉ được phép va chạm ô tô với chướng ngại vật tối đa là 3 lần, quá 3 lần sẽ không có cách nào để thắng được game
# GUIDE PLAY
- Người chơi sử dụng các phím di chuyển lên, xuống, trái, phải để điều khiển xe đi theo hướng tương ứng
- Điều khiển xe tránh các chướng ngại vật để đi đến đích an toàn
# PREVIEW
![image](https://user-images.githubusercontent.com/95302057/169871877-19b4b24b-840e-49f5-a500-40b67a4bc521.png)
![image](https://user-images.githubusercontent.com/95302057/169871939-5c12674c-c346-449a-b245-9a932358e818.png)
![image](https://user-images.githubusercontent.com/95302057/169872057-1481d626-c7c8-44d3-b81d-5dab7db64f03.png)
![image](https://user-images.githubusercontent.com/95302057/169872160-6af7d924-9147-42b1-9e8f-9f18571b1b67.png)
![image](https://user-images.githubusercontent.com/95302057/169872233-b5227dea-8344-454e-9f8e-fccf5c946934.png)
# CÁC KỸ THUẬT ĐƯỢC SỬ DỤNG
- Thư viện đồ họa SDL2
- Tách chương trình ra thành các file nhỏ
- Xử lý thời gian, sự kiện bàn phím, chuột, âm thanh, hình ảnh
- Sử dụng con trỏ để có thể truyền đường dẫn hình ảnh, âm thanh, font chữ
# Nguồn tham khảo
- Lazy foo: https://lazyfoo.net/tutorials/SDL/index.php
- Blog: phattrienphanmem123az
# Kết luận
* Các điểm tâm đắc:
  - Hiểu được cách chia tách file để có thể dễ dàng quản lý chương trình
  - Tự làm và có thể hiểu được code
  - Dễ dàng cải tiến chương trình
* Hướng phát triển
  - Xây dựng thêm các chức năng mới như: Chơi lại, cập nhật điểm khi đi qua các chướng ngại vật, thêm các boost để xe tăng tốc
# Cách cài đặt
- Sử dụng link: https://drive.google.com/drive/folders/1H7afo2j48AgQrUusefTCJ2iNZ0D4Bqwv?usp=sharing
- Tải file debug về máy, giải nén file đã tải, nháy đúp chuột vào file debug, tiếp tục tìm file project_ltnc.exe, nháy đúp chuột vào và chơi
