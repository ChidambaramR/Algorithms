#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

bool is_unique(char *a){
	int length = strlen(a);
	int mask=0,i;
	char tmp;
	for(i=0; i<length; i++){
		tmp = a[i] - 'a';
		if(mask & (1 << tmp))
			return 0;
		mask |= (1 << tmp);
	}
	printf("Mask = %d\n",mask);
	return true;
}

int main(){
	char a[100];
	printf("Enter the string ");
	scanf("%s",a);
	if(is_unique(a))
		printf("String contains all unique characters\n");
	else
		printf("String contains duplicate characters\n");
	return 0;
}
