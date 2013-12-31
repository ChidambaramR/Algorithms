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

void print(Base b){
	b.show();
}

int main(){
	Base b;
	Derived d;
	print(b);
	print(d);
	return 0;
}
