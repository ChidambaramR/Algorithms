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

void memcpy_bits(void *dst, void *src, int len)
{
	int bits_left = len % 8;
	int bytes = len / 8;
	unsigned char mask, temp;
	
	my_memcpy(dst, src, bytes);
	dst = dst + bytes;
	src = src + bytes;
	mask = ((1 << bits_left) -1);
	mask = mask << (8 - bits_left);
	temp = *src & mask;
	*dst = temp;
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
