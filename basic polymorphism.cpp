#include<iostream>
using namespace std;
class Base
{
public:
 virtual void show()
{
cout<<"Base Class";
}
void show1()
{cout<<"Base Class-show1";}
};

class Derived:public Base
{
public:
void show()
{
cout<<"Derived Class";
}
void show1()
{cout<<"Derived Class-show1";}
};

int main()
{
Derived d;
Base b;
Base*b1; 
b1=&d;
b1->show();
b1->show1();

return 0;
}
