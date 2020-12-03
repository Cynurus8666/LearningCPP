#include <iostream>
using namespace std;

int calFactorial(int num)
{
    int res = 1;
    for (int i = 1; i < num + 1; i++)
    {
        res *= i;
    }
    return res;
}

int numBit1(int len_of_bit)
{
    int num_of_res = 1;
    for (int i = 1; i < len_of_bit; i++)
    {

        int temp = calFactorial(len_of_bit - 1) / ((calFactorial(i) * calFactorial(len_of_bit - 1 - i)));
        for (int j = 0; j < temp; j++)
        {
            num_of_res += i + 1;
        }
    }
    return num_of_res;
}

int main()
{
    int res = 0;
    int n = 8;
    for (int i = 1; i < n + 1; i++)
    {
        res += numBit1(i);
    }
    cout << res << endl;
}