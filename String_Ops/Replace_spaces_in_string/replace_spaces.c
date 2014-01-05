#include <stdio.h>
#include <string.h>

void replace(char *str){
	int length = strlen(str);
	int i;
	int space_count=0;
	int newLength;
	
	for(i=0; i<length; i++){
		if(str[i] == ' ')
			space_count++;
	}
	/*
	This is not 3 * space_count because, a character is already there for space.
	We need to replace ' ' with %20. Thus we need to add only 2 more characters
	and not 3 characters. So we need 2*spacecount characters extra space.
	*/
	newLength = length + 2*space_count;
	str[newLength] = '\0';
	
	/*
	We are proceeding from the last because, if we come from 1st then we need to
	shift characters in the original string. Whereas, in this method we move the
	last to newLength which is length + 2*no_of_spaces. Thus there will not be
	a situation to shift characters in the original string and we also keep 
	adding in the same string without creating a new string.
	*/
	for(i=(length-1); i >=0 ; i--){
		if(str[i] == ' '){
			str[newLength-1] = '0';
			str[newLength-2] = '2';
			str[newLength-3] = '%';
			newLength = newLength - 3;
		}
		else{
			str[newLength-1] = str[i];
			newLength = newLength - 1;
		}
	}
}

int main(){
	char a[100];
	printf("Enter the string with spaces: ");
	fgets(a, 100, stdin);
//	scanf("%s",a);
	replace(a);
	printf("\nThe new string is: %s\n",a);
	return 0;
}
