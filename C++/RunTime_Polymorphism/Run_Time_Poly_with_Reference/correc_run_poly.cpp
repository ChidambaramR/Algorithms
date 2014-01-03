#include <iostream>
using namespace std;

class Base{
	public:
	virtual void show(){
		cout << "This is base class \n";
	}
};

class Derived : public Base{
	public:
	virtual void show(){
		cout << "This is derived class \n";
	}
};

/*
Receiving the parameter as a reference. So there
is not Object slicing and the program correctly prints with
base class method if called with base class instance and prints
with derived class method if called with derived class instance.
*/
void print(Base &b){
	b.show();
}

int main(){
	Base b;
	Derived d;
	print(b);
	print(d);
	return 0;
}
