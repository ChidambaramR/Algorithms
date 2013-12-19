#include <stdio.h>
#include <stdint.h>

typedef enum { false, true } bool;
int8_t count[256];

bool is_anag(char *str1, char *str2){
	int i;
	while( *str1 && *str2 ){
		count[(*str1) - 'a']++;
		count[(*str2) - 'a']--;
		*str1++;
		*str2++;
	}
	if(*str1 != '\0' || *str2 != '\0')
		return false;

	for(i=0; i<256; i++)
		if(count[i])
			return false;
	return true;
}

int main(){
	char a[100];
	char b[100];
	printf("Enter string 1 ");
	scanf("%s",a);
	printf("\nEnter string 2 ");
	scanf("%s",b);
	if(is_anag(a,b))
		printf("Strings are anagrams\n");
	else
		printf("Strings are not anagrams\n");
	return 0;
}
