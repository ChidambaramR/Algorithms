#include <stdio.h>

/*
Let a number be x. If we xor a number y to x two times, then
it makes no difference to the number x. So the logic is to 
xor all elements of the array.
The take the result and xor with all numbers from 1 to n. 
If the list is 1,2,3,4,6
XOR all these numbers. 
Take the result and xor with 1,2,3,4,5,6.
Since 1,2,3,4 and 6 are being xor'd two times, all wil cancel out.
Only 5 will be remaining.
*/
int missing_xor(int a[], int n){
	int x1=a[0];
	int i;

	for(i=1; i<n; i++)
		x1 = x1^a[i];

	for(i=1; i<=(n+1); i++)
		x1 = x1^i;

	return x1;
}

int missing_sum(int a[], int n){
    	int i, total;
	/*
	Sum of 1st n numbers. its (n+1)*(n+2) because, one number is missing.
	So it is not n*(n+1)/2.
	*/
    	total  = (n+1)*(n+2)/2;  
    	for ( i = 0; i< n; i++)
       		total -= a[i];
    	return total;
}

int main(){
	int a[]={1,2,3,4,5,7,8,9};
	printf("Missing number: %d\n",missing_xor(a, 8));
	printf("Missing number1: %d\n",missing_sum(a, 8));
	return 0;
}
