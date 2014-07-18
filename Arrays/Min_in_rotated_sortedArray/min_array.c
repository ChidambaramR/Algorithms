#include <stdio.h>

// 14 19 20 8 9 10 11

int min = 999;
int n;

int find_min(int *a, int start, int end){
  if(end <= start)
    return 0;

  int mid = (start + end)/2;

  if(a[mid] > a[mid+1])
      return a[mid+1];
  else if(a[mid] < a[mid-1])
      return a[mid-1];
  else if(a[start] > a[mid])
      return find_min(a, start, mid-1);
  else
      return find_min(a, mid+1, end);
}

int main(){
  int a[] = {7,8,9,1,2,3,4,5,6};
  printf("minimum number is %d\n",find_min(a, 0, sizeof(a)/sizeof(a[1])));
  return 0;
}
