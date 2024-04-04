#include <iostream>
#include <iomanip> 

using namespace std;

int main() {

    double pi = 3.14;
    cout << "Default precision of pi: " << pi << endl;
    cout << "Setting precision to 5: " << setprecision(5) << pi << endl;
    cout << "Setting precision to 10: " << setprecision(10) << pi << endl;
    cout << "Resetting to default precision: " << setprecision(6) << pi << endl;
    
    cout << "Field width of 10, right-aligned:" << endl;
    cout << setw(10) << "Hello" << endl;
    cout << setw(10) << "World" << endl;
    
    cout << "Field width of 10, left-aligned:" << left << endl;
    cout << setw(10) << "Hello" << endl;
    cout << setw(10) << "World" << endl;
    
    cout << "Field width of 10, right-aligned, filled with *:" << endl;
    cout << setfill('*') << setw(10) << "Hello" << endl;
    cout << setw(10) << "World" << endl;
    
    return 0;
}
