#include <iostream>
#include <string>
using namespace std;

string lookAndSay(unsigned int n)
{
    if (n == 1)
    {
        return "1";
    }
    else if (n == 2)
    {
        return "11";
    }
    else
    {
        string res = "11";
        for (int i = 2; i < n; i++)
        {
            string new_res = "";
            for (int j = 0; j < res.length(); j++)
            {
                int count = 1;
                for (int k = j + 1; k < res.length(); k++)
                {
                    if (res[k] == res[j])
                    {
                        count++;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                new_res += to_string(count) + res[j];
            }
            int sum = 0;
            for (int m = 0; m < new_res.length(); m++)
            {
                sum += (int)new_res[m] - 48;
            }
            cout << "i: " << i + 1 << " - " << new_res << " - " << sum << endl;
            res = new_res;
        }
        return res;
    }
}

int main()
{
    int N = 10;
    cout << lookAndSay(N) << endl;
    return 0;
}