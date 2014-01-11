#include <stdio.h>
#include <stdlib.h>

int* circ_shift(int a[], int length, int shift_size){
	int *b = (int*)malloc(sizeof(length));
	int i=0, k=0;
	while(i < length){
		k =  (shift_size+i)%length;
		b[k] = a[i++];
	}
	return b;
}

int main(){
	int a[] = {1,3,4,5,7,8,9,11,24,67};
	int *b;
	int i;
	int length = (sizeof(a)/sizeof(a[0]));
	printf("Length %d\n",length);
	b = circ_shift(a, length, 4);
	for(i=0; i<length; i++)
		printf("%d ",b[i]);
	return 0;
}
