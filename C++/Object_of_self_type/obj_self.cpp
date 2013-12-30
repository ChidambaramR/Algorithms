#include <iostream>

class Test{
	static Test self;
};

class Test1{
	Test1* self;
};

class Test2{
	Test2 self;
};

int main(){
	Test t;
	Test1 t1;
//	Test2 t2;
	return 0;
}
