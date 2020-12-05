/**
 * Chương trình này được dùng để  in ra số nguyên dương còn thiếu trong một mảng cho trước
*/
#include <iostream>
using namespace std;

/**
 * Decription: Hàm này được dùng để in ra giá trị số dương nhỏ nhất còn thiếu trong một mảng cho trước
 * Param: Mảng cho vào và kích thước của mảng
 * Return: Giá trị số nguyên dương nhỏ nhất còn thiếu
*/
int minPosNumber(int arr[], int arr_size)
{
    //
    int check_num = 1;
    bool done = true;
    while (done)
    {
        for (int *p = arr; p != nullptr; p++)
        {
            if (check_num == *p)
            {
                done = false;
                check_num++;
                break;
            }
        }
    }

    return check_num;
}

int main()
{
    int arr[4] = {3, 2, 4, 0};
    cout << minPosNumber(arr, 4);
    return 0;
}