#include<iostream>
using namespace std;
 
class Empty {};

class Derived1 : public Empty
{};

/*
The size of this class (Derived2) is 8.
Derived2 inherits the class Empty as vitual. So, a virtual pointer
will be created and its of size 8 bytes (64 bit machine).
*/  
class Derived2 : virtual public Empty
{};
  
class Derived3 : public Empty
{   
    char c;
};
 
/*
The siz of this class (Derived4) is 16.
Derived4 inherits Empty as virtual. So, a virtual pointer will be
created and its size is 8 bytes (64 bit machine). Now a char is of 
size 1 byte. So total is 9 bytes. Due to byte padding, another 7
bytes are added and hence the total size is 16
*/ 
class Derived4 : virtual public Empty
{
    char c;
};
  
class Dummy
{
    char c;
};
 
int main()
{
    cout << endl << sizeof(Empty) << endl;
    Empty* p1 = new Empty;
    Empty* p2 = new Empty;
 
    if (p1 == p2)
        cout << "impossible " << endl;
    else
        cout << "Fine p1 = " << p1 << " p2 = " << p2 << endl;

    cout << "sizeof(Empty) " << sizeof(Empty) << endl;
    cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
    cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
    cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;   
    cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;  
    return 0;
}
