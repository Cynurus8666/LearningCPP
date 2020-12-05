/*
* Bài code này được sử dụng để giải bài toàn chuỗi lock-and-say. Bài toán như sau:
*   Kí tự đầu tiên là "1"
*   Kí tự thứ 2 là "11"
*   Với mỗi kí tự tiếp theo sẽ in ra số lượng kí tự liên tục và kí tự đó. Ví dụ ở trên là 2 số 1 nên in ra: "21"
* Trong chuỗi in ra được có thể cộng lại tạo thành chuỗi tăng: 1 - 2 - 3 - ... Chuỗi này được gọi là chuỗi lock-and-say
*/
#include <iostream>
#include <string>
using namespace std;

/*
* Decription: Hàm trả về một chuỗi string giá trị lock-and-say thứ n.
* Param: Giá trị thứ n trong chuỗi lock-and-say: Như n = 3 thì giá trị lock-and-say là "21"
* Return: Chuỗi biểu thị giá trị lock-and-say thứ n
*/
string lookAndSay(unsigned int n)
{
    // Hạn chế bước lặp thì có thể kiểm tra từ kí tự n = 2
    if (n == 1)
    {
        return "1";
    }
    else if (n == 2)
    {
        return "11";
    }
    else
    {
        // Giá trị khởi đầu để thực hiện lock-and-say cho các giá trị kế tiếp. Giá trị này sẽ được
        // cập nhật sau mỗi bước lặp của n
        string res = "11";

        // 1. Chạy tuần tự để xác định kết quả cần
        for (int i = 2; i < n; i++)
        {
            // Giá trị
            string temp_res = "";

            // 2. Kiểm tra từng giá trị trong chuỗi kết quả hiện tại để đếm số lượng kí tự
            for (int j = 0; j < res.length(); j++)
            {
                // Số lượng kí tự đếm được ban đầu luôn là 1 - Chính là kí tự kiểm tra đầu tiên
                int count = 1;

                // 3. Lặp tiếp từ vị trí j kiểm tra để xem có bao nhiêu kí tự sau đó giống vị trí j
                for (int k = j + 1; k < res.length(); k++)
                {
                    // Nếu gặp được phần tử giống thì tăng biến count lên và tăng giá trị biến đếm j để sau không phải lặp lại kiểm tra vị trí này nữa.
                    // Nếu không bằng nhau thì chuỗi liên tục đã hết, break để kiếm tra giá trị khác.
                    if (res[k] == res[j])
                    {
                        count++;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                // 4. Kiểm tra xong giá trị thứ j, ta in ra số lượng kí tự và kí tự đó. Nối thêm vào temp_res
                temp_res += to_string(count) + res[j];
            }

            /*
            * Đoạn code này được dùng để in ra tổng các kí tự trong chuỗi tìm được.
            int sum = 0;
            for (int m = 0; m < temp_res.length(); m++)
            {
                sum += (int)temp_res[m] - 48;
            }
            cout << "i: " << i + 1 << " - " << temp_res << " - " << sum << endl;
            */

            // 5. Sau khi kiểm tra toàn bộ kí tự thì gán chuỗi vừa tìm được làm kết quả trả về.
            res = temp_res;
        }
        return res;
    }
}

int main()
{
    int N = 10;
    cout << lookAndSay(N) << endl;
    return 0;
}