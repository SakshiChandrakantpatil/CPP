#include <iostream>

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    
    friend std::ostream& operator<<(std::ostream& os, const Complex& obj) {
        os << obj.real << " + " << obj.imaginary << "i";
        return os;
    }

    
    friend std::istream& operator>>(std::istream& is, Complex& obj) {
        std::cout << "Enter real part: ";
        is >> obj.real;
        std::cout << "Enter imaginary part: ";
        is >> obj.imaginary;
        return is;
    }
};

int main() {
    Complex c1;
    std::cout << "Enter a complex number (real + imaginary): ";
    std::cin >> c1;

    std::cout << "You entered: " << c1 << std::endl;

    return 0;
}
