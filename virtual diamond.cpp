 #include<iostream>
using namespace std;
class Base
{
public:
 virtual void display()
{cout<<"Display Base class"<<endl;}
void accept()
{

cout<<"Accept Base class\n";
}
};
 
class Derived1:virtual public Base
{
public:
void display()
{
	cout<<"Display Derived Class 1";
}
void accept()
{

cout<<"Accept Derived Class1";

}
};

class Derived2:public Base
{
public:
void display(){cout<<"Display Derived Class 2";}
void accept()
{

cout<<"Accept Derived Class2";

}
};

class Derived3:public Derived1,public Derived2
{
public:
void display(){cout<<"Display Derived Class 3";}
void accept()
{

cout<<"Accept Derived Class3";

}
};

int main()
{
Derived3 d;
Base *b1; 
b1= &d;
b1->display();
b1->accept();

return 0;
}
