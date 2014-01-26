#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}

void check_consec(int a[], int ind, int *count){
	int i = ind;
	while(a[i] == a[i+1]){
		i++;
		(*count)++;
	}
}


void print_twice(int a[], int b[], int len_a, int len_b){
/*
11 11 20 20 22 23 34 35 45 45 54 66 223 

22 23 34 34 56 66 67 78 88 90 99 99 223 

*/
	int i=0,j=0;
	int k,l;
	int count_i, count_j;
	while(i<len_a && j<len_b){
		//k=i, l=j;
		count_i=0;
		count_j=0;

		if(a[i] == b[j]){
		/*
		If two numbers(a[i], b[j]) are equal, then we should check if they occur
		more than two times. So we go through the A list to see if the consecutive elements
		are same as the a[i]. 
		Similarly we go through the B list to see if the consecutive elements are same as b[j]
		If we so, we increment the count by number of times they are equal and finally i and j
		will point to the element in which a[i] and b[j] are not equal and leave the job to be
		taken care in the next iteration.
		In the above example, in the case of 34: i and j will initially meet at 1st 34. Now j
		will be incremented and moved to 56. count_j will be 1. So the printf statement will not
		be executed. In the next iteration, we check b[j] i.e 56 with the  element 34
		*/
			check_consec(a, i, &count_i);
			check_consec(b, j, &count_j);

			if(!count_i && !count_j){
				printf("%d\n",a[i]);
			}
			i += (count_i+1);
			j += (count_j+1);
		}
		else{
			count_i = 1;
			count_j = 1;
			if(a[i] < b[j]){
				check_consec(a, i, &count_i);
				if(count_i == 2){
					printf("%d\n",a[i]);
				}
				i++;
			}
			else{
				check_consec(b, j, &count_j);
				if(count_j == 2){
					printf("%d\n",b[j]);
				}
				j++;
			}
		}

	}
	if(i < len_a){
		// List B was of shorter length
		count_i = 1;
		while(i < len_a){
			if(a[i] == a[i+1]){
				check_consec(a, i, &count_i);
				if(count_i == 2){
					printf("%d\n",a[i]);
				}
			}
			i++;
		}
	}
	if(j < len_b){
		// List A was of shorter length
		count_j = 1;
		while(j < len_b){
			if(b[j] == b[j+1]){
				check_consec(b, j, &count_j);
				if(count_i == 2){
					printf("%d\n",b[j]);
				}
			}
			j++;
		}
	}
	
}


int main(){
	int a[] = {20,45,11,35,22,34,66,223,54,23,20,11,45};
	int b[] = {99,99,78,56,23,66,34,22,34,67,88,90,167,190,223};
	int len_a = (sizeof(a)/sizeof(a[0]));
	int len_b = (sizeof(b)/sizeof(b[0]));
	char temp = 2;
	qsort(a, len_a, sizeof(int), cmp);
	qsort(b, len_b, sizeof(int), cmp);

	int i=0,j=0;
	while(i < len_a)
		printf("%d ",a[i++]);
	
	printf("\n\n");

	while(j < len_b)
		printf("%d ",b[j++]);

	fflush(stdout);
	printf("\nOutput:\n");	
	print_twice(a, b, len_a, len_b);
	return 0;
}
