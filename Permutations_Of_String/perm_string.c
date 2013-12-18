#include <stdio.h>
#include <string.h>

void swap(char *src, char *dst){
	char tmp;
	tmp = *src;
	*src = *dst;
	*dst = tmp;
}


void perm(char *a, int k, int n){
	int i;
	if(k == n){
		printf("%s\n",a);
	}
	else{
		for(i=k; i<n; i++){
			swap(&a[k], &a[i]);
			perm(a, k+1, n);
			swap(&a[k], &a[i]); // Backtrack
		}
	}
}

int main(){
	char a[100];
	printf("Enter the string to permute");
	scanf("%s",a);
	perm(a, 0, strlen(a));
	return 0;
}
