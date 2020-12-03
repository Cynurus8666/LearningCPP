#include <iostream>
using namespace std;

/*
1. Lap tu 1 -> n
2. Voi lan lap thu k thi dua phan tu a[k] ve dung vi tri trong a
3. Swap a[k] voi phan tu truoc no cho toi khi no lon hon hoac bang phan tu dung truoc no.
*/
void printArr(int *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    return;
}

void insertionSort(int *arr, int arr_size)
{
    for (int i = 1; i < arr_size; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (arr[j] > arr[j - 1])
            {
                break;
            }
            else
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
        printArr(arr, arr_size);
    }
}

void bubbleSort(int *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        bool done = true;
        for (int j = 0; j < arr_size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                done = false;
            }
        }
        if (done)
        {
            cout << "Ok: " << i << endl;
            break;
        }
    }
}

int main()
{
    int a[5] = {1, 2, 5, 4, 3};
    printArr(a, 5);
    bubbleSort(a, 5);
    printArr(a, 5);

    return 0;
}