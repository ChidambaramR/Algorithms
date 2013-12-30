#include <iostream>
#include <stdio.h>

class Base{
  public:
  int x;
};

// This is equivalent to class Derived : private Base
class Derived : Base
{
};

struct Test : Base
{
};

int main(){
  Derived d;
  Test t;
  d.x = 20;
  t.x = 20;
  return 0;
}
