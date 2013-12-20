#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;
bool hash[256];

void rem_dup(char *str){
	//int len = strlen(str);
	int ip_ind=1, res_ind=1;
	while(*(str+ip_ind)){
		hash[str[ip_ind] - 'a']++;
		if(hash[str[ip_ind] - 'a'] == 1){
			str[res_ind] = str[ip_ind];
			res_ind++;
		}
		ip_ind++;
	}
	while(res_ind < ip_ind){
		str[res_ind] = '\0';
		res_ind++;
	}
}

int main(){
	char a[100];
	printf("Enter the string to rem duplicates ");
	scanf("%s",a);
	hash[a[0] - 'a']++;
	rem_dup(a);
	printf("\nThe string after removing duplicates: %s\n",a);
	return 0;
}
