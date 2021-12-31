# ThucTapCoSo
Trong đời sống, chúng ta thường gặp những tình huống như sau:để đi từ địa điểm A đến địa điểm B, có nhiều đường đi, nhiều cách đi; có lúc ta chọn đường đi ngắn nhất (theo nghĩa cự ly), có lúc lại cần chọn đường đi nhanh nhất ( theo nghĩa thời gian) và có lúc phải cân nhắc để chọn đường đi rẻ tiền nhất( theo nghĩa chi phí),…

![image](https://user-images.githubusercontent.com/78671855/147327329-033362bc-ff25-43af-871d-d2e3f91f5f32.png)
1.	Ngôn ngữ sử dụng
C++ (C Plus Plus) là một loại ngôn ngữ lập trình bậc trung. Đây là ngôn 
ngữ lập trình đa năng được tạo ra bởi Bjarne Stroustrup như một phần mở rộng của ngôn ngữ lập trình C, hoặc "C với các lớp Class", Ngôn ngữ đã được mở rộng đáng kể theo thời gian và C ++ hiện đại có các tính năng: lập trình tổng quát, lập trình hướng đối tượng, lập trình thủ tục, ngôn ngữ đa mẫu hình tự do có kiểu tĩnh, dữ liệu trừu tượng, và lập trình đa hình, ngoài ra còn có thêm các tính năng, công cụ để thao tác với bộ nhớ cấp thấp. Từ thập niên 1990, C++ đã trở thành một trong những ngôn ngữ thương mại ưa thích và phổ biến của lập trình viên.
2.	Môi trường phát triển
Dev-C++ là một môi trường phát triển tích hợp tự do (IDE) được phân phối dưới hình thức giấy phép Công cộng GNU hỗ trợ việc lập trình bằng C/C++. Nó cũng nằm trong bộ trình dịch mã nguồn mở MinGW. Chương trình IDE này được viết bằng ngôn ngữ Delphi. Ngoài ra thêm thư viện đồ họa graphics/ winbgim dùng để mô phỏng thuật toán các trực quan hơn.


![image](https://user-images.githubusercontent.com/78671855/147800173-40dfeb18-457b-4aa8-8526-238d7913b3cd.png)

![image](https://user-images.githubusercontent.com/78671855/147800177-a6bb9cd7-446a-4d26-a43b-8dbefc8f519a.png)

![image](https://user-images.githubusercontent.com/78671855/147800210-5e903b7e-ee27-4fb8-b352-1087f5d09804.png)

Sau khi có được đỉnh đầu và đỉnh cuối, tạo mảng lưu các đỉnh và trọng số ngắn nhất từ đỉnh đầu đến các đỉnh còn lại.

Cho trọng số các đỉnh chưa duyệt là vô cùng.

Vòng lặp for đầu tiên để duyệt các đỉnh kề với đỉnh đầu được chọn.

Vòng lặp for thứ hai là kiểm tra xem các đỉnh không kề có đường đi đến hay không. Nếu không có thì vẫn là vô cùng, nếu có đường đi ngắn hơn thì cập nhật lại.

Cứ như thế khi nào đến hết thì thoát khỏi vòng lặp while.

![image](https://user-images.githubusercontent.com/78671855/147800598-1ba6bdd3-394b-4e37-845f-bcc0beba7c73.png)
![image](https://user-images.githubusercontent.com/78671855/147800603-1b8911f8-4d3f-48bb-bc6b-9d7949ebdac1.png)
Tạo ma trận A lưu độ dài các cạnh (số thực), tức là A[x,y] là độ dài của cạnh (x,y), nếu không có cạnh (x,y) thì A[x,y] = ∞.
Mảng S[n] trong đó n là số nguyên lưu các số 0 và 1, đây là một vecto biểu diễn tập hợp S.
Nếu S[x]==1 là x thuộc S, nếu S[x] == 0 là thuộc tập V-S.
Khởi đầu cho S[x0]=1 nghĩa là x0 thuộc tập S, và các S[x]=0 nghĩa là các x còn lại nằm ngoại tập hợp S. Tại mỗi bước nếu w (đường đi ngắn nhất) được đưa vào S => đặt S[w]=1.
Mảng D[n] để lưu độ dài của đường đi ngắn nhất từ x0 đến mỗi đỉnh của đồ thị.
Khởi đầu cho D[x] bằng độ dài của x0 đến x thì D[x]=A[x0,x], nếu không có cạnh từ x0 đến x thì D[x]=∞ .
Tại mỗi bước, sẽ cập nhật lại D[x] để lưu độ dài đường đi ngắn nhất từ đỉnh x0 tới đỉnh x, đường đi này chỉ đi qua các đỉnh đã có trong S.
 
Giả sử đỉnh U đến V là ngắn hơn đường trước đó thì sẽ xóa đường cũ đi và cập nhật lại.



