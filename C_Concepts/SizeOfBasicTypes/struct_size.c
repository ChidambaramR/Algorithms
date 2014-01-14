#include <stdio.h>

int main(){
	
	/*
	The size of this struct is going to be 20 bytes only and not 24 bytes for a 32 bit machine.
	This is because, in a 32 bit machine, anyways we would need two memory fetches to get a double
	value. So it does not matter if it is aligned on a 4 byte boundary or a 8 byte boundary.
	In a 64 bit machine, however it needs 8 byte alignment since it can fetch a double in one shot.
	*/
	struct s{
		char c;
		int i;
		double d;
		void *p;
//		int a[0];
	};
	struct s temp[2];
	void *q;
	double d1=10;

	printf("size of struct = %d sizeof q = %d sizeof double = %d\n",sizeof(temp),sizeof(q),sizeof(d1));
	return 0;
}
