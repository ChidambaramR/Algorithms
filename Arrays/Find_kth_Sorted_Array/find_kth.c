#include <stdio.h>

int find_kth_smallest(int a[], int b[], int len_a, int len_b, int k){
	int i=0, j=0;
	int curr;
	int counter = 0;

	while((i < len_a) && (j < len_b)){
		if(a[i] < b[j])
			curr = a[i++];
		else if(b[j] < a[i])
			curr = b[j++];
		counter++;

		if(counter == k)
			return curr;
		
	}

	//Either of the array's length fell short
	// B's length was shorter than A. So just traverse A till we count k.
	while(i < len_a){
		curr = a[i++];
		counter++;
		if(k == counter)
			return curr;
	}

	// A's length was shorter than B. So just traverse B till we count k.
	while(j < len_b){
		curr = b[j++];
		counter++;
		if(k == counter)
			return curr;
	}
}

int main(){
	int a[] = {4,6,7,8,10,23,56,84};
	int b[] = {24, 26, 29, 34, 36, 37, 39, 49, 94, 104, 120};
	printf("Kth smallest element in both arrays = %d\n",find_kth_smallest(a, b, (sizeof(a)/sizeof(a[0])), (sizeof(b)/sizeof(b[0])), 11));
	return 0;
}

