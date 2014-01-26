#include <stdio.h>

void getBreakPoint(int arr[], int length){
        int first = 0;
        int second = 0;
	int i;

        for(i=0; i<length; i++)
		  second += i; 

        for(i=0; i < length-1; i++) {
            first = first + arr[i];
            second = second - arr[i];
            if(first == second ) {
                printf("Break even point is: %d\n",i);
            }
        }
}

int main(){
	int arr[] = {1,-1,0,1,1};
	int length = (sizeof(arr)/sizeof(arr[0]));
	getBreakPoint(arr, length-1);
	return 0;
}

