#include "header.h"

void func1()
{
    std::cout << "Function 1" << std::endl;
    func2();
}

void func2()
{
    std::cout << "Function 2" << std::endl;
}