//#include "header.h"
#include <iostream>

using namespace std;

int globalVariable;

void foo()
{
    int a;
    cout << a << endl;
}

int main()
{
    cout << globalVariable << endl;
    foo();
    return 0;
}
