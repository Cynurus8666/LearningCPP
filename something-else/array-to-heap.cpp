#include <iostream>
#include <string>
using namespace std;

void max_heap(int *arr, int N, int check_pos)
{
    int largest;
    int left = check_pos * 2;
    int right = check_pos * 2 + 1;
    if (left < N and arr[left] > arr[check_pos])
        largest = left;
    else
        largest = check_pos;
    if (right < N and arr[right] > arr[check_pos])
        largest = right;
    else
        largest = check_pos;
    if (largest != check_pos)
    {
        swap(arr[check_pos], arr[largest]);
        max_heap(arr, N, largest);
    }
}

int main()
{
    int a[8] = {1, 4, 3, 6, 4, 2, 3, 8};
    for (int i = 7; i > -1; i--)
        max_heap(a, 8, i);
    for (const auto &item : a)
    {
        cout << item << "  ";
    }
    cout << endl;

    return 0;
}