#include <iostream>
#include <string>

using namespace std;

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
    Person person("Sakshi", 30);
    Student student("Panu", 20, 12345);
    Employee employee("Smita", 35, 1001, 50000.0);
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
