#include <stdio.h>

/*
Let a number be x. If we xor a number y to x two times, then
it makes no difference to the number x. So the logic is to 
xor all elements of the array.
The take the result and xor with all numbers from 1 to n. 
If the list is 1,2,3,4,6
XOR all these numbers. 
Take the result and xor with 1,2,3,4,5,6.
Since 1,2,3,4 and 6 are being xor'd two times, all wil cancel out.
Only 5 will be remaining.
*/
int missing_xor(int a[], int n){
	int x1=a[0];
	int i;

	for(i=1; i<n; i++)
		x1 = x1^a[i];

	for(i=1; i<=(n+1); i++)
		x1 = x1^i;

	return x1;
}

int missing_sum(int a[], int n){
    	int i, total;
	/*
	Sum of 1st n numbers. its (n+1)*(n+2) because, one number is missing.
	So it is not n*(n+1)/2.
	*/
    	total  = (n+1)*(n+2)/2;  
    	for ( i = 0; i< n; i++)
       		total -= a[i];
    	return total;
}

int missing_sum_bsearch(int a[], int length){
	int low = 0;
	int high = length-1;
	int mid = (low+high)/2;

	while(low < high){
		if((mid - low) != (a[mid] - a[low])){
			if(mid - low == 1)
				return a[mid]-1;
			high = mid ;
		}
		else if((high-mid) != (a[high] - a[mid])){
			if(high - mid == 1)
				return a[mid]+1;
			low = mid ;
		}
		mid = (high+low)/2;
	}
}

int missing_sum_bsearch_rec(int a[], int low, int high){
	if(low > high){
		printf("Elements are in sorted order only\n");
		return -1;
	}
	
	int mid = (low+high)/2;

	if((mid-low) != (a[mid]-a[low])){
		if(mid-low == 1)
			return a[mid]-1;
		missing_sum_bsearch_rec(a, low, mid);
	}
	else if(high-mid != (a[high]-a[mid])){
		if(high-mid == 1)
			return a[mid]+1;
		missing_sum_bsearch_rec(a, mid, high);	
	}
	else{
		/*
		If the difference in the indexes are same, then possibly,
		the array is in sorted order.
		*/
		printf("All elements are in sorted order\n");
		return -1;
	}
		
}

int main(){
	int a[]={1,2,3,4,5,6,7,8,9};
	printf("Missing number: %d\n",missing_xor(a, 9));
//	printf("Missing number1: %d\n",missing_sum(a, 8));
	printf("Missing number1: %d\n",missing_sum_bsearch_rec(a, 0, 8));
	return 0;
}
