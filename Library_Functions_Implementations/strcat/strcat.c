#include <stdio.h>

char* my_strcat(char *s, char *t){
	char *temp = s;
	if(!t)
		return s;

	while(*temp)
		temp++;
	while(*t){
		*temp++ = *t++;
	}

	return s;
}

int main(){
	char dst[20] = "chid";
	char *src = "ambaram";
	printf("Concatenated string = %s\n",my_strcat(dst, src));
	return 0;
}
