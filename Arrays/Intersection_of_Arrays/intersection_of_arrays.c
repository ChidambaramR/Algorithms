#include <stdio.h>

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


/*
We first sort both the arrays. We now have two pointers
initialized to start. Both of them traverse till either one of them
reaches end. In the process, if a[i] == b[j], it means we have found
a matching element. So print it. 
If a[i] < b[j], then increment i. Since a[i]<a[j], anyways, till the value
of a[i] becomes bigger than a[j] there can be no intersecting element.
Similarly if a[i] > b[j], then increment j as no element can intersect till
a[i] value equals b[j]. So keep incrementing j in this case.
*/
void intersect(int a[], int b[], int len_a, int len_b){
  quickSort(a, 0, len_a-1);
  quickSort(b, 0, len_b-1);

  int i=0, j=0;
  // Arrays are now sorted
  while((i < len_a) && (j < len_b)){
    if(a[i] == b[j]){
      printf("%d ",a[i]);
      i++;
      j++;
    }
    else if(a[i] < b[j])
      i++;
    else
      j++;
  }
}

int main(){
  int a[]={1,4,2,5,10,32,9,4};
  int b[]={32,31,90,34,1};
  int len_a = 8;
  int len_b = 5;
  intersect(a, b, 8, 5);
  return 0;
}
