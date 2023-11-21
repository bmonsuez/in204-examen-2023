#include"ex8.2.hpp"
#include<iostream>

int main()
{
    std::cout << interval<float>(0.0, 1.5) << std::endl;
    std::cout << interval<float>() << std::endl;
    interval<long> a(3, 9);
    interval<long> b(2, 7);
    std::cout << a << " & " << b << " = " 
        << (a & b) << std::endl;

    return 0;
}