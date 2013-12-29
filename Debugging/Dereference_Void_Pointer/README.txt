Objective:
===========
  Find the compilation error in the program

Logic:
======
  The given program dereferences a void pointer. That is not allowed. So we typecast it and assign the values.
  i.e int x=10;
      void *p = &x;
      printf("%d",*(int*)p)
