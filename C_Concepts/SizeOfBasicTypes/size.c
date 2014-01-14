#include <stdio.h>

#define my_sizeof(type) ((char*)(&type + 1) - (char*)(&type))

int main(){
	int a = 1;
	unsigned int b = 10;
	long c = 10;
	double d = 10;
	long long e = 20;
	long double f = 20;
	long g = 10;
	printf("size of int = %d, unsigned int = %d, long = %d, double = %d, long long = %d, long double = %d\n",sizeof(a),sizeof(b),sizeof(c),sizeof(d),sizeof(e),sizeof(f));
	printf("\nSize of long = %d\n",sizeof(g));
	return 0;
}
