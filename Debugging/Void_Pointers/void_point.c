#include <stdio.h>

int main(){
  float i=10, *j;
  void *k;
  k = &i;
  j = k;
  k++;
  printf("\n%f",*j);
  printf("\n %c", 7["Sundaram"]);
//  printf("\n%d %d",sizeof(NULL), sizeof(""));
  return 0;
}
