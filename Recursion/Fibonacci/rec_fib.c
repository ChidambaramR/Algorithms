#include <stdio.h>

int rec_fib(int n){
//	printf("%d\n",n);
	int val = 0;
	if((n==0) || (n==1))
		return n;
	val = rec_fib(n-2) + rec_fib(n-1);
//	printf("%d \n",val);
	return val;
}


int main(){
	printf("%d\n",rec_fib(8));
	return 0;
}
