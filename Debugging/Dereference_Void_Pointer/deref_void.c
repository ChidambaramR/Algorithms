#include<stdio.h>
  int main()
  {
          void *p;
          int x=10;
          float y=20.2;
          p=&x;
          printf("int %d\n",*p);
          *p=20;
          p=&y;
          printf("float %d\n",*p);
          return 0;
 }
