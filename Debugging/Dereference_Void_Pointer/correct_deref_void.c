#include<stdio.h>
int main()
{
   void *p;
   int x=10;
   float y=20.2;
   p=&x;
   printf("int %d\n",*(int*)p);
   *(int*)p=20;
   p=&y;
   printf("float %g\n",*(float*)p);
   return 0;
 }
