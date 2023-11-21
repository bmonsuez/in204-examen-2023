#include"ex9.2.hpp"
#include<iostream>

int main()
{
    interval<float> a(3, 9);
    singleton<float> b(3.2);
    std::cout << a << " & " << b << " = " 
        << (a & b) << std::endl;

    return 0;
}