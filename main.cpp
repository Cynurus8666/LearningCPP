/*
This is a temporary file that I use for testing some code.
*/

#include <iostream>
using namespace std;
class mayLaptop
{
private:
    int chieudai = 10;

protected:
    int a = 3;

public:
    void setChieuDai(int n)
    {
        this->chieudai = n;
    }
};
class mayVitinh : private mayLaptop
{
public:
    void printOut()
    {
        cout << a << endl;
        cout << "OK" << endl;
    }
};
int main()
{
    mayLaptop mayAcer;
    mayVitinh mayVitinh;
    mayVitinh.printOut();
    return 0;
}