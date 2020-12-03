#include <iostream>
#include <string>
using namespace std;
#define N 14

int main()
{
    string all_start = "";
    string all_space = "";
    for (int i = 0; i < N; i++)
    {
        all_start += '*';
        all_space += ' ';
    }

    int a = 1, b = N - 2;

    for (int i = 0; i < N; i++)
    {
        if (i == 0 || i == N - 1)
            cout << all_start << endl;
        else
        {
            string temp = all_space;
            temp[0] = '*';
            temp[N - 1] = '*';
            temp[b] = '*';
            temp[a] = '*';
            --b;
            ++a;
            cout << temp << endl;
        }
    }

    return 0;
}