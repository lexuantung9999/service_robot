Service Robot
(Những phần bên dưới các ô cứ Clone về và chỉnh sửa, xong thì publish lên một branch khác nhé, để không bị trộn lẫn với nhau
Sau đó m
+ Những Package hiện tại: 
  + SLAM: Gmapping 
  + Navigation: 
    + Teb_Local_Planner: Local Planner
    + AMCL: Localize vị trí của robot trong map 
    + Move_Base: Gửi giá trị vận tốc cho robot di chuyển sau khi xác định được đường đi và vị trí của robot trên map
  + Localize: 
    +robot_localization
      + Subscribe: giá trị của odom (Encoder -> (bước trung gian) -> Odom) và giá trị của Imu
      + Publish: Giá trị của Odom sau khi kết hợp giá trị của 2 data trên
+ Những node hiện có: 
  + diff_tf: 
    + Chuyển đổi từ message của /cmd_vel (vx, vy, az) sang giá trị của Odom
    + Publish giá trị của Odom 
    + Gửi Transform từ Odom -> Base_footprint
  + sub_button_msg:
    + Subscribe tới một node gửi giá trị message theo kiểu ("Button1", "Button2")
    + Nhận giá trị message và chỉ định tọa độ của xe sẽ di chuyển đến ở trên map 

+ Những task cần thêm: 
  + Cần thêm Package của Lidar đang sử dụng để đưa vào code (hiện tại Lidar trong code không phải của RPLidar)
  + Hiện tại chỉ có Source code về phần ROS,chưa có source code về phần điều khiển của Hardware (Arduino Mega ) 
  + Thêm phần xử lý giao diện GUI cho robot 
  + Thêm phần xử lý ảnh + AI (Human Detection or Object Detection) 
  + Thêm phần tự động di chuyển về điểm sạc ( Nếu có ) 
  + Thêm phần nhận diện giọng nói ( Nếu có ) 
  + Thêm phần Emotion GUI ( Nếu có ) 
  

