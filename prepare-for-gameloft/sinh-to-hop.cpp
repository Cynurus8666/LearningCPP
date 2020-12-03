#include <stdio.h>

int n, k;
int th[11];

void khoitao()
{
    for (int i = 1; i <= k; i++)
    {
        th[i] = i;
    }
}

void in()
{
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", th[i]);
    }
}

int dung = 0;
void sinhth()
{
    int i = k;
    while (i > 0 && th[i] == n - k + i)
        i--;
    if (i > 0)
    {
        th[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            th[j] = th[i] + j - i;
        }
    }
    else
        dung = 1;
}

int main()
{
    n = 4, k = 3;
    khoitao();
    do
    {
        in();
        printf("\n");
        sinhth();
    } while (dung != 1);

    return 0;
}
