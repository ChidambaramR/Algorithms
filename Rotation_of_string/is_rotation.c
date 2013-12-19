#include <stdio.h>
#include <string.h>

int main(){
	char a[100];
	char b[100];
	char temp[100];
	char *ptr;
	printf("Enter string 1 ");
	scanf("%s",a);
	printf("Enter string 2 ");
	scanf("%s",b);
	strcat(temp, a);
	strcat(temp, a);
	ptr = strstr(temp, b);
	if(ptr != NULL)
		printf("Strings are roatations of each other\n");
	else
		printf("Strings are not rotations of each other\n");

	return 0;
}
