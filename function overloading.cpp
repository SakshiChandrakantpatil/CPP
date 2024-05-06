#include <iostream>

int add(int a, int b) 
{
    return a + b;
}


int add(int a, int b, int c)
 {
    return a + b + c;
}


double add(double a, double b)
 {
    return a + b;
}

int main()
 {
    std::cout << "Adding two integers: " << add(3, 5) << std::endl;
    std::cout << "Adding three integers: " << add(3, 5, 7) << std::endl;
    std::cout << "Adding two doubles: " << add(3.5, 2.7) << std::endl;
    
    return 0;
}
