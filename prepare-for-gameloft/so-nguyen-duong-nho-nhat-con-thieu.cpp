/*
Cho mot mang so nguyen, in ra gia tri nguyen duong nho nhat con thieu.
*/
#include <iostream>
using namespace std;

int minPosNumber(int arr[], int arr_size)
{
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
    int arr[4] = {1, 4, 3, 0};
    cout << minPosNumber(arr, 4);
    return 0;
}