#include <stdio.h>

void reverse(char *s, char *end){
	char temp;
	while( s < end ){
		temp = *s;
		*s = *end;
		*end = temp;
		s++;
		end--;
	}
}	
void reverse_words(char *str){
	char *start = str;
	char *end = str;

	while(*end){
		end++;
		if(*end == '\0')
			reverse(start, end-1);
		else if(*end == ' '){
			reverse(start, end-1);
			start = end+1;
		}
	}

	reverse(str, end-1);
}

int main(){
	char str[] = "I Love my country";
	reverse_words(str);
	printf("Reversed string: %s\n",str);
	return 0;
}
