#include <stdio.h>

void bin_search(int a[], int low, int high, int target){
//	printf("Low = %d, high = %d\n",low, high);
	if(low > high){
		// Item not found
		printf("Item Not Found\n");
		return;
	}

	int mid = (low+high)/2;

	if(a[mid] > target){
		// Element found in left part of the array
		bin_search(a, low, mid-1, target);
	}
	else if(a[mid] < target){
		// Element found in right part of the array
		bin_search(a, mid+1, high, target);
	}
	else{
		printf("Element found\n");
		return;
	}
}

void iter_bin_search(int a[], int length, int val){
	int low = 0;
	int high = length;
	int mid = (high+low)/2;

	while((low < high) && (a[mid] != val)){
//		printf("Low %d High %d\n",low,high);
		if(a[mid] < val)
			low = mid+1;
		else if(a[mid] > val)
			high = mid-1;
		mid = (low+high)/2;
	}	

	if(low >= high){
		printf("Element not found");
		return;
	}

	printf("Element Found");
	return;
}

int main(){
	int a[] = {1,2,3,6,7,8,23,78,89,103};
	bin_search(a, 0, ((sizeof(a)/sizeof(a[0]))-1), 189);
	iter_bin_search(a, ((sizeof(a)/sizeof(a[0]))-1), 189);
	printf("\n");
}
