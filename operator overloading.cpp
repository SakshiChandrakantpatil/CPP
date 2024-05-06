#include <iostream>

class Number {
private:
    int value;
public:
    Number(int val) : value(val) {
	}

    Number operator+(const Number& other) 
	const
	 {
        return Number(value + other.value);
    }

    Number operator-(const Number& other) 
	const
	 {
        return Number(value - other.value);
    }

    void display() 
	const 
	{
        std::cout << "Value: " << value << std::endl;
    }
};

int main()
 {
    Number num1(10);
    Number num2(5);

    Number result_addition = num1 + num2;
    Number result_subtraction = num1 - num2;

    std::cout << "Addition result: ";
    result_addition.display();

    std::cout << "Subtraction result: ";
    result_subtraction.display();

    return 0;
}
