#include <iostream>
#include <string>

using namespace std;

class Pet{
	public:
	string getDescription() const{
		return "This is Pet class\n";
	}
};

class Dog : public Pet{
	public:
	string getDescription() const{
		return "This is Dog class\n";
	}
};

void describe(Pet p){
	cout << p.getDescription() << endl;
}

int main(){
	Dog d;
	describe(d);
	return 0;
}
