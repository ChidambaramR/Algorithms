#include <stdio.h>

// 14 19 20 8 9 10 11

int min = 999;
int n;

void find_min(int *a, int left, int right){
	int mid = (left + right)/2;
	
	// Special case where min element is in last
	/*if(right - left == 1){
		if(a[right] > a[left])
			min = a[left];
		else
			min = a[right];
		return;
	}*/
	if(left == right){
		min = a[left];
		return;
	}

	// If middle element itself is the min element
	if(a[mid] < a[mid-1]){
		min = a[mid];
		return;
	}

	if(a[left] < a[mid])
		find_min(a, mid+1, right);
	else if(a[left] > a[mid])
		find_min(a, left, mid-1);
	else{
		min = a[mid];
		return;
	}
}

int main(){
	int i;
	int a[100];
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the array in sorted order\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	if(a[0] < a[n-1])
		printf("Min value = %d\n",a[0]);
	else{
		find_min(a, 0, n-1);
		printf("Min value = %d\n",min);
	}
}
