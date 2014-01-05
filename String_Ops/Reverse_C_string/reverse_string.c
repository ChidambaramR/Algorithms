#include <stdio.h>
#include <string.h>
#define MAX 100 

char* rev(char *str){
	static char rev_str[MAX];
	static int j=0;
	char temp;

	if(*str){	
		rev(str+1);
		temp = *str;
		*str = rev_str[j];
		rev_str[j++] = temp;
	}

	return rev_str;
		
}

void rev_iter(char *str){
	char *end = str;
	char temp;

	while(*end)
		end++;
	end--;

	while(str < end){
		temp = *end;
		*end = *str;
		*str = temp;
		str++;
		end--;		
	}
}

int main(){
	char a[100], *a_rev;

	printf("Enter the string ");
	scanf("%s",a);
	rev_iter(a);
	printf("Reversed string: %s\n",a);
	a_rev=rev(a);
	printf("Reversed string: %s\n",a_rev);
	return 0;
}


