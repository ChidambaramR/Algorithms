#include <stdio.h>

void fred();
void bread();
void barbara ( void (*function_ptr)() );
int main();

int main()
{
  barbara (fred);
  barbara (bread);
  return 0;
}

void fred(){
  printf("fred here!\n");
}

void bread(){
  printf("bread here\n");
}

void barbara ( void (*function_ptr)() ){
  /* Call fred */
  (*function_ptr)();
}
