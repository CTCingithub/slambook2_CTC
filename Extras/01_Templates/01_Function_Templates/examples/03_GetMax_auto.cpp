#include <iostream>
#include <typeinfo>
#include "03_GetMax_auto.h"

int main(int argc, char **argv)
{
    int a = 1;
    float b = 2.5;
    double c = 3.5;
    auto result_1 = GetMax(a, b);
    auto result_2 = GetMax(b, c);
    std::cout << "Max of a and b is: " << result_1 << " " << typeid(result_1).name() << std::endl;
    std::cout << "Max of b and c is: " << result_2 << " " << typeid(result_2).name() << std::endl;
    return 0;
}