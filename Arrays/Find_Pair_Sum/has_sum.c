#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
 
int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;
 
    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}
 
/* Implementation of Quick Sort
A[] --> Array to be sorted
si  --> Starting index
ei  --> Ending index
*/
void quickSort(int A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}

bool hasArrayTwoCandidates(int *A, int len, int target){
    int l,r;

    // Sort the array
    quickSort(A, 0, len-1);

   // Set left to 0 and right to the last element
    l = 0;
    r = len-1;

    // Traverse till left and right meet
    while(l<r){
      /*
      If sum of elements pointed to by left and right are
      equal, then we have found a pair. Output it. Increment
      the left pointer and decrement the right pointer.
      */
      if( (A[l] + A[r]) == target){
        printf("%d %d\n",A[l],A[r]);
        l++;
        r--;
      }
      else if((A[l] + A[r]) < target){
      /*
      If the sum of both the elements is small, then increment
      the left pointer. There is no point in decrementing the right
      pointer because, the sum is anyways lower and the array is sorted.
      */
        l++;
      }
      else{
        /*
        If the sum is greater, then we have to decrement the right pointer.
        */
        r--;
      }
    }

}


int main(){
    int A[] = {-9,-1,2,3,4,5,8};
    int n = 7;
    int arr_size = 7;
    
    if( hasArrayTwoCandidates(A, arr_size, n))
        printf("\nArray has elements with sum 16");
    else
        printf("\nArray doesn't have elements with sum 16 ");
  return 0;
}
