#include <iostream>

class Animal {
public:
    void eat() 
	{
        std::cout << "Animal eats" << std::endl;
    }

    void sleep()
	 {
        std::cout << "Animal sleeps" << std::endl;
    }
};


class Dog : public Animal
 {
public:
    void bark() 
	{
        std::cout << "Dog barks" << std::endl;
    }
};

int main() 
{

    Dog dog;
    dog.eat();
    dog.sleep();
    dog.bark();

    return 0;
}
