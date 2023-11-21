#include"ex7.2.hpp"
#include<iostream>

int main()
{
    interval<long> a(3, 9);
    interval<long> b(2, 7);
    auto c = a & b;
    std::cout << "[" << c.getLowerBound() 
        << ", "  << c.getUpperBound() 
        << "]";
    return 0;
}