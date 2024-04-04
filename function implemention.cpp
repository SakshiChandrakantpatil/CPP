#include <iostream>
#include <string>

using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class Student
class Student : public Person {
private:
    int studentID;
public:
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}

    void display() {
        Person::display();
        cout << "Student ID: " << studentID << endl;
    }
};

// Derived class Employee
class Employee : public Person {
private:
    int employeeID;
    double salary;
public:
    Employee(string n, int a, int empID, double sal) : Person(n, a), employeeID(empID), salary(sal) {}

    void display() {
        Person::display();
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    // Creating objects of each class
    Person person("John Doe", 30);
    Student student("Alice Smith", 20, 12345);
    Employee employee("Bob Johnson", 35, 1001, 50000.0);

    // Displaying information
    cout << "Person:" << endl;
    person.display();
    cout << endl;

    cout << "Student:" << endl;
    student.display();
    cout << endl;

    cout << "Employee:" << endl;
    employee.display();
    cout << endl;

    return 0;
}
