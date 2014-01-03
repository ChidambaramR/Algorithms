#include <stdio.h>

typedef int(*ptrMyFunc1)();
typedef void(*ptrMyFunc2)(int);

struct Base{
	int membervar1 ;
	ptrMyFunc1 memberFunc1;
	ptrMyFunc2 memberFunc2 ;

};

struct Derived{
	int membervar1 ;
	ptrMyFunc1 memberFunc1;
	ptrMyFunc2 memberFunc2 ;
};

int MyBaseFunc1(){
	printf("Base class\n");
	return 10;
}

void MyBaseFunc2(int x){
	printf("Base class\n");
	if(x == 10 )
		printf("Got 10 min. left\n");

}

int MyDerivedFunc1(){
	printf("Derived class\n");
	return 20;
}

void MyDerivedFunc2(int x){
	printf("Derived class %d\n",x);
}

void baseFunc(struct Base *b){
	b->memberFunc1();
	b->memberFunc2(20);
}

int main(int argc, char* argv[])
{
	struct Derived der1 ;
	struct Base * bsPtr =NULL;
	struct Base b;
	b.membervar1 = 20;
	b.memberFunc1 = MyBaseFunc1 ; // mimic class member function
	b.memberFunc2 = MyBaseFunc2 ; // mimic class member function
	bsPtr = &b;

	der1.membervar1 = 45 ;
	der1.memberFunc1 = MyDerivedFunc1 ; // mimic class member function
	der1.memberFunc2 = MyDerivedFunc2 ;
	
	baseFunc(der1);
	baseFunc(bsPtr);

}
