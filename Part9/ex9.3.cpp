#include"ex9.3.hpp"
#include<iostream>

int main()
{
    interval<float> a(3, 9);
    singleton<float> b(3.2);

#if FALSE    
    // Don't compile, getLowerBound is deleted
    std::cout << b.getLowerBound() << std::endl;
#endif    
    std::cout << b.getValue() << std::endl;
    std::cout << a << " & " << b << " = " 
        << (a & b) << std::endl;

    return 0;
}