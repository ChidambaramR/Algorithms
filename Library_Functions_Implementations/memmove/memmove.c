#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_memcpy(void *dst, const void *src, size_t len){
	if(!dst || !src)
		return;

	char *s = (char*)src;
	char *d = (char*)dst;

	while(len--){
		*d++ = *s++;
	}
}


void* my_memmove(void *dst, const void *src, int len){
	char *p1 = (char*)dst;
	const char* p2 = (const char*)src;

	// Dont do anything if pointers are same
	if(p1 == p2)
		return dst;

	p2 = p2+len;

	// Iterate through src and check if the pointers are equal
	while(p2 != src && --p2 != p1);

	if(p2 != src){
		// Overlap detected
		p2 = (const char*)src;
		p2 = p2 + len;
		p1 = p1 + len;
		// Copy from back
		while(len--)
			*--p1 = *--p2;
	}
	else{
		while(len--)
			*p1++ = *p2++;
	}
	return dst;
}


int main(){
	char *p1 = (char*)malloc(12);
	char *p2;

	memset(p1, 12, '\0');
	
	strcpy(p1, "ABCDEFGHI");
	p2 = p1 + 2;

	printf("\n--------------------------------\n");
	printf("\nSrc (before) = [%s]",p1);
	printf("\nDst (before) = [%s]",p2);

	//my_memmove(p2, p1, 10);
	my_memcpy(p2, p1, 10);
	
	printf("\n--------------------------------\n");
	printf("\nSrc (After) = [%s]",p1);
	printf("\nDst (After) = [%s]\n",p2);
	return 0;
}
