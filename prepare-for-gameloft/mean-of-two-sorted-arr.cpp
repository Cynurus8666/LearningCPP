/**
 * Chương trình này được mình viết ra để tìm kiếm giá trị trung vị của 2 mảng đã được sắp xếp sau khi gộp lại là gì.
 * Thực sự mà nói thì nó không khó nhưng lúc làm đã làm mình tốn kha khá thời gian. :((
*/
#include <iostream>
using namespace std;

/**
 * Decription:  Hàm này được dùng để lấy giá trị trung vị của mảng được tạo ra từ 2 mảng đã được sắp xếp ban đầu
 * Param:       2 mảng đã được sắp xếp và kích thước của chúng
 * Return:      
 *              Nếu mảng tạo được có số phần tử lẻ thì trung vị là giá trị của phần tử mảng ở giữa
 *              Nếu mảng tạo được có số phần tử chẳn thì trung vị là giá trị trung bình của 2 phần tử giữa
*/
double getMean(int arr_1[], int size_arr_1, int arr_2[], int size_arr_2)
{
    //Vị trí trung vị, vị trí này là vị trí cận dưới (trong trường hợp tổng kích thước là chẵn)
    int mean_pos = (size_arr_1 + size_arr_2 - 1) / 2;

    //Xác định xem tổng kích thước của 2 mảng là chẵn hay không
    bool even = (size_arr_1 + size_arr_2) % 2 == 0 ? true : false;

    // Lưu trữ tổng của các giá trị mean (tối đa là 2)
    int sum_of_mean = 0;
    // Dùng để kiếm tra số lượng giá trị mean đã đạt được (trong trường hợp có 2 giá trị)
    int num_of_mean = 0;

    // Các con trỏ chạy để kiểm tra trên mảng 1 và 2
    int arr_1_cur = 0, arr_2_cur = 0;

    // Con trỏ để kiểm tra vị trí mean
    int mean_cur = -1;

    // 1. Cho con trỏ chạy ở 2 mảng cho tới khi tìm được đủ các giá trị cho trung
    // vị hoặc 1 trong 2 mảng không còn phần tử chưa được duyệt nữa.
    while (arr_1_cur < size_arr_1 && arr_2_cur < size_arr_2)
    {
        // 2. Kiểm tra chênh lệch 2 phần tử cần kiểm tra của 2 mảng dựa trên con trỏ của 2 mảng.
        // 3. Với mỗi giá trị kiểm tra thành công thì con trỏ mean sẽ tăng lên 1.
        // 4. Nếu giá trị con trỏ mean bằng với giá trị mean cần tìm thì cần:
        //      4.1 kiểm tra xem mean cần tìm có số lượng chẵn hay lẻ. Nếu là lẻ thì trả về chính giá trị đó.
        //      4.2 Nếu là chẳn thì cần kiểm tra số lượng vị trí mean đã đủ chưa. Nếu đã có 1 thì trả về
        //          trung bình củagiá trị sum_of_mean và giá trị mới tìm được. Nếu chưa có thì gán giá trị này
        //          vào sum_of_mean và tăng giá trị của num_of_mean lên 1.

        if (arr_1[arr_1_cur] < arr_2[arr_2_cur])
        {
            // Khi phép so sánh được thực hiện thành công thì giá trị của mean_cur tăng lên 1. Dùng ở
            // đầu vì khỏi tạo là -1 nhằm kiểm tra xem giá trị mean_cur đã bằng với vị trí mean cần tìm chưa.

            mean_cur++;
            if (mean_cur == mean_pos || mean_cur == mean_pos + 1)
            {
                // Nếu tổng size là số lẻ thì trả về vị trí tìm được (dưới dạng số thực)
                if (!even)
                {
                    return arr_1[arr_1_cur] * 1.0;
                }
                // Nếu là số chẵn thì kết quả tùy thuộc vào số lượng mean đã được cộng vào
                else
                {
                    if (num_of_mean == 1)
                    {
                        sum_of_mean += arr_1[arr_1_cur];
                        return sum_of_mean / 2.0;
                    }
                    else
                    {
                        sum_of_mean += arr_1[arr_1_cur];
                        num_of_mean++;
                    }
                }
            }

            // Tăng con trỏ của mảng được kiểm tra lên 1
            arr_1_cur++;
        }
        // Xử lý tương tự luồng ở trên
        else
        {
            mean_cur++;
            if (mean_cur == mean_pos || mean_cur == mean_pos + 1)
            {
                // Nếu tổng size là số lẻ thì trả về vị trí tìm được (dưới dạng số thực)
                if (!even)
                {
                    return arr_2[arr_2_cur] * 1.0;
                }
                else
                {
                    // Nếu là số chẵn thì kết quả tùy thuộc vào số lượng mean đã được cộng vào
                    if (num_of_mean == 1)
                    {
                        sum_of_mean += arr_2[arr_2_cur];
                        return sum_of_mean / 2.0;
                    }
                    else
                    {
                        sum_of_mean += arr_2[arr_2_cur];
                        num_of_mean++;
                    }
                }
            }
            arr_2_cur++;
        }
    }

    // 5. Trường hợp này xảy ra khi mà 1 trong 2 mảng đã bị duyệt hết nhưng vẫn chưa đến được vị trí mean.
    //      5.1 Nếu mảng 1 bị duyệt hết thì sẽ chỉ kiểm tra mảng 2 nữa thôi.
    //      5.2 Nếu mảng 2 bị duyệt hết thì sẽ chỉ kiểm tra mảng 1 nữa thôi.
    //      Cách lấy phần tử cần là dùng hiệu số mean_pos và kích thước mảng đã kiểm tra hết. Như vậy
    //      là có thể dễ dàng có được vị trí mean đầu tiên, vị trí mean thứ 2 (nếu cần) chính là giá trị tiếp
    //       của mảng
    if (arr_1_cur == size_arr_1)
    {
        // Vị trí mean_cur cần trên arr_2
        arr_2_cur = mean_pos - arr_1_cur;

        if (!even)
        {
            return arr_2[arr_2_cur] * 1.0;
        }
        else
        {
            return (arr_2[arr_2_cur] + arr_2[arr_2_cur + 1]) / 2.0;
        }
    }
    else
    {
        // Vị trí mean_cur cần trên arr_2
        arr_1_cur = mean_pos - arr_1_cur;
        if (!even)
        {
            return arr_1[arr_1_cur] * 1.0;
        }
        else
        {
            return (arr_1[arr_1_cur] + arr_1[arr_1_cur + 1]) / 2.0;
        }
    }
}

int main()
{
    int arr1_size = 1;
    int arr1[arr1_size]{3};
    int arr2_size = 7;
    int arr2[arr2_size]{1, 3, 4, 5, 7, 10, 15};
    cout << getMean(arr1, arr1_size, arr2, arr2_size) << endl;
    return 0;
}