#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }
};

int main() {
    Person person1("John Doe", 30);

    cout << "Initial Information:" << endl;
    person1.display();
    person1.setName("Jane Smith");
    person1.setAge(25);

    cout << "\nUpdated Information:" << endl;
    person1.display();

    return 0;
}
