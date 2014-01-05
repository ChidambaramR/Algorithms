#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;
bool hash[256];

void rem_dup(char *str){
	//int len = strlen(str);
	int ip_ind=1, res_ind=1;
	while(str[ip_ind]){
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


void rem_dup_efficient(char *str){
	int length = strlen(str);
	int tail = 1;
	int i,j;

	for(i=1; i<length; i++){
		for(j=0; j<tail; j++){
			if(str[j] == str[i])
				break;
		}
		if(j == tail){
			str[tail] = str[i];
			tail++;
		}
	}
	str[tail] = '\0';
}

int main(){
	char a[100];
	printf("Enter the string to rem duplicates ");
	scanf("%s",a);
	hash[a[0] - 'a']++;
	rem_dup_efficient(a);
	printf("\nThe string after removing duplicates: %s\n",a);
	return 0;
}
