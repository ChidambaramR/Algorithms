#include <stdio.h>
#include <stdlib.h>

void my_memcpy(void *dst, void *src, int len){
	int i=0;

	// We can copy a value from NULL pointers
	if(!dst || !src)
		return;

	for(i=0; i<len; i++)
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
}

void my_memcpyBits(void *dst, void *src, int numBits){
	int numBytes = numBits/8;
	
	my_memcpy(dst, src, numBytes);

	dst = (void*)((unsigned char*)dst + numBytes); 
	src = (void*)((unsigned char*)src + numBytes); 

	// Now dst and source have been moved till the bytes copied. We have to copy the bits
	int bitsLeft = numBits % 8;
	int mask = (1 << (numBits +1))-1;
	dst = (void*)(((*(unsigned char*)src & mask) | (*(unsigned char*)dst & (~mask))));
}

int main(){
	int i;
	int *a = (int*)malloc(5*sizeof(int));
	a[0]=4;
	a[1]=5;
	a[2]=7;
	a[3]=8;
	a[4]=9;

	int *b = (int*)calloc(5, sizeof(int));
	my_memcpy(b, a, 3*sizeof(int));
	for(i=0; i<5; i++){
		printf("Src: %d , Dst %d\n",a[i],b[i]);
	}
	return 0;
}
