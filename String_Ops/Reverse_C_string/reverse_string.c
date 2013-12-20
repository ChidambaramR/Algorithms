#include <stdio.h>

void rev(char *str){
	if(*str)
		rev(str+1);
	printf("%c",*str);
}

int main(){
	char a[100];
	printf("Enter the string ");
	scanf("%s",a);
	rev(a);
	printf("\n");
	return 0;
}
