#include <stdio.h>

/*
The overall organisation og pointers will be like this.
0x400 - black
0x500 - White
0x600 - yellow
0x700 - violet

char *s[] = {0x400, 0x500, 0x600, 0x700}

s - 0x100
i.e 0x400 | 0x500 | 0x600 | 0x700
    -----
    0x100 <-- s ( base address )

char **ptr[] = {0x112, 0x108, 0x104, 0x100}
		-----  -----  -----  -----
		s+3  | s+2  | s+1  |  s

ptr - 0x50
i.e 0x112 | 0x108 | 0x104 | 0x100
    ------
    0x50 <-- ptr ( base address )

char ***p = ptr
p - 0x50

Thus printf("%s",**p) will give
	1. Dereference 0x50. We get 0x112
	2. Dereference 0x112. We get 0x700
	3. Now %s will dereference 0x700 to get violet
*/
int main(){
	/*
	s is an array of pointers to characters.
	Thus the value of s is the base address of the array and not the
		the 1st value. i.e if char *s[] = {0x100, 0x200, 0x300, 0x400},
		then s = 0x10 which stores the value 0x100. Thus 's' if of type
		pointer to pointer and hence stored with **ptr.
	*/
	static char *s[]={"black", "white", "yellow", "violet"};

	/*
	ptr is an array of pointers to character pointers.
	Thus value of ptr will be {0x20, 0x18, 0x14, 0x10}. Note that 0x10 points to
	0x100.
	*/
	char **ptr[] = {s+3, s+2, s+1, s};
	/*
	ptr is the base address of char **ptr[]. Let is be 0x5. This value is stored in p.
	thus p = 0x5
	*/
	char ***p;
	p = ptr;
	printf("%s\n",**p);
	return 0;
}

