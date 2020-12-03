/*
Cho mot mang voi chi so tuong ung voi moi nguoi. chi ra so luong nguoi co the nhin thay nhau.
Nguoi nhin thay nhau la:
+ 2 nguoi canh nhau
+ Giua 2 nguoi khong co ai cao hon ca 2
*/

#include <iostream>
using namespace std;

int getNumWhoSeeEachOther(int arr[], int arr_size)
{
    int res = arr_size - 1;
    int step = 2;
    while (step < arr_size)
    {
        for (int i = 0; i < arr_size - step; i++)
        {
            int max_j_i = arr[i] > arr[i + step] ? arr[i] : arr[i + step];
            int max_in_range = arr[i + 1];
            for (int k = i + 1; k < i + step + 1; k++)
            {
                max_in_range = arr[k] > max_in_range ? arr[k] : max_in_range;
            }

            if (max_in_range <= max_j_i)
            {
                res++;
                cout << "-----------------------" << endl;
                cout << step << endl;
                cout << max_in_range << endl;
                cout << max_j_i << endl;
                cout << arr[i] << " - " << arr[i + step] << endl;
                cout << res << endl;
            }
        }
        step++;
    }
    return res;
}

int main()
{
    int x = 4;
    int arr[x] = {3, 1, 2, 5};
    cout << getNumWhoSeeEachOther(arr, x) << endl;
    return 0;
}