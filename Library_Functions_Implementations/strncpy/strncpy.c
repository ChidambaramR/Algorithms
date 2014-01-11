#include <stdio.h>

int my_strlen(const char *str){
	int length = 0;

	if(!str)
		return 0;
	while(*str++)
		length++;

	return length;
}

void my_strncpy(char *dst, const char *src, int n){
	while(n--){
		*dst++ = *src++;
	}
	*dst = '\0';
}

int main(){
	char dst[100];
	char *src = "Hello";
	my_strncpy(dst, src, my_strlen(src));
	printf("Source string: %s\nDestination string: %s\n",src,dst);
	return 0;
}
