# Panda
 1. Hướng dẫn cài đặt

- Cài SFML: https://www.sfml-dev.org/tutorials/2.5/
          
          https://www.youtube.com/watch?v=G5-8Tcz6WaU&t=1616s

- Cài Cmake : https://cmake.org/download/ 

- Tải code:  https://github.com/Mynuhihi/Panda -> Code -> Download Zip -> Giải nén -> Mở bằng CodeBlock.  
Sau đó trích lại đường dẫn folder include trong folder Source code SFML mà mình tải trước đó, và trích đường dẫn folder lib trong folder SFML mà mình tự build trước đó. Sau đó chỉ cần F9 là được (nếu trong trường hợp F9 báo lỗi “Undefined reference to 'SDL_main'” thì chỉ cần thêm “int argc, char* argv[]” vào trong int main() rồi F9 lại là được.


2. Mô tả chung về trò chơi, các ý tưởng chính

Game tên Panda, gồm 1 quả bóng nảy qua nảy lại. 2 thanh ngang dùng cả sinh mệnh để đỡ bóng. Bóng tựa gấu trúc, thanh ngang tựa cây tre.

Nếu đấu lẫn nhau, người chơi bên trái dùng phím W để di chuyển thanh lên và S để di chuyển thanh xuống, người chơi bên phải dùng phím Up để di chuyển thanh lên và Down để di chuyển thanh xuống.

Nếu đấu với máy, người chơi dùng phím W để di chuyển thanh lên và S để di chuyển thanh xuống.


3. Mô tả chức năng đã cài đặt:

- Có menu để lựa chọn chức năng mình muốn (1:1, chơi cùng Al, xem luật…)

- Chế độ đấu 2 người ( 1:1)

- Chế độ đấu với Bot (Play against Bot)

- Cơ chế tính điểm, ai đạt 5 điểm trước sẽ thắng đồng thời kết thúc game!


4. Các kỹ thuật lập trình được sử dụng trong chương trình

- Mảng: Dùng cho menu, …

- Switch case: Dùng khá nhiều thay cho if, if và if

- Hàm con: Mấy hàm trong menu

- Lớp: Dùng cho menu, …

- Đồ họa: Background, …
 
- Âm thanh: Nhạc nền, hiệu ứng bóng đập, hiệu ứng khi lựa chọn menu,...

- Và còn nhiều kỹ thuật khác thông dụng…


5. Kết luận

C++ là một loại ngôn ngữ lập trình đa năng, C++ hiện đại có các tính năng như lập trình tổng quát, lập trình hướng đối tượng… Thư viện SFML được viết bằng ngôn ngữ C++  một thư viện phát triển phần mềm đa nền tảng được thiết kế để cung cấp giao diện lập trình ứng dụng đơn giản cho các thành phần đa phương tiện khác nhau trong máy tính.

SFML đem lại sự thuận tiện và dễ dàng hơn nhiều thư viện khác, tuy nhiên cũng sẽ có những hạn chế nhất định

PANDA là game đầu tay của bản thân em, trong quá trình hoàn thiện gặp rất nhiều bug, bug và bug. Tuy  nhiên, đến cuối cùng cũng ra dáng một game nho nhỏ. Dự tính sẽ thiết lập thêm một vài tính năng như:

- Người chơi có thể điều chỉnh âm lượng âm thanh, vận tốc bóng…

- Thêm vài hiệu ứng âm thanh

- Quả bóng sẽ được thiết kế lại thành mặt con gấu trúc

- Thanh ngang thiết kế thành hình ảnh thanh tre

- Bot bất tử

- …

Điều tâm đắc nhất sau khi hoàn thiện chương trình có lẽ là học được rất nhiều cái mới, từ kiến thức chuyên ngành nói chung đến cách học sao cho hiệu quả hơn nói riêng, tiến dần hơn đến công việc sau này. (Nói thế thôi chứ em tâm đắc cái Background Kung Fu Panda của em nhất hí hí)


