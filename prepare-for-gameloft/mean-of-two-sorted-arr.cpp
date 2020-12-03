#include <iostream>
using namespace std;

double getMean(int a1[], int sa1, int a2[], int sa2)
{
    int mean_pos = (sa1 + sa2 - 1) / 2;
    bool even = (sa1 + sa2) % 2 == 0 ? true : false;

    int sum = 0;
    int num_sum = 0;

    int i = 0, j = 0;
    int mean_cur = -1;

    while (i < sa1 && j < sa2)
    {
        if (a1[i] < a2[j])
        {
            mean_cur++;
            if (mean_cur == mean_pos || mean_cur == mean_pos + 1)
            {
                if (!even)
                {
                    return a1[i] * 1.0;
                }
                else
                {
                    if (num_sum == 1)
                    {
                        sum += a1[i];
                        return sum / 2.0;
                    }
                    else
                    {
                        sum += a1[i];
                        num_sum++;
                    }
                }
            }
            i++;
        }
        else
        {
            mean_cur++;
            if (mean_cur == mean_pos || mean_cur == mean_pos + 1)
            {
                if (!even)
                {
                    return a2[j] * 1.0;
                }
                else
                {
                    if (num_sum == 1)
                    {
                        sum += a2[j];
                        return sum / 2.0;
                    }
                    else
                    {
                        sum += a2[j];
                        num_sum++;
                    }
                }
            }
            j++;
        }
    }

    if (i == sa1)
    {
        while (j < sa2)
        {
            mean_cur++;
            if (mean_cur == mean_pos || mean_cur == mean_pos + 1)
            {
                if (!even)
                {
                    return a2[j] * 1.0;
                }
                else
                {
                    if (num_sum == 1)
                    {
                        sum += a2[j];
                        return sum / 2.0;
                    }
                    else
                    {
                        sum += a2[j];
                        num_sum++;
                    }
                }
            }
            j++;
        }
    }
    else
    {
        while (i < sa1)
        {

            mean_cur++;
            if (mean_cur == mean_pos || mean_cur == mean_pos + 1)
            {
                if (!even)
                {
                    return a1[i] * 1.0;
                }
                else
                {
                    if (num_sum == 1)
                    {
                        sum += a1[i];
                        return sum / 2.0;
                    }
                    else
                    {
                        sum += a1[i];
                        num_sum++;
                    }
                }
            }
            i++;
        }
    }
    return sum;
}

int main()
{
    int arr1_size = 3;
    int arr1[arr1_size]{1, 6, 7};
    int arr2_size = 3;
    int arr2[arr1_size]{3, 4, 5};
    cout << getMean(arr1, arr1_size, arr2, arr2_size) << endl;
    return 0;
}

//Cuoi cung cung lam duoc, dm. Y tuong la dua tren cach noi 2 mang da sap xep lai voi nhau. Do co phan so chan nen hoi phien phuc chut.