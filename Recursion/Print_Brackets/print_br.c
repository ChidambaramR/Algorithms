#include <stdio.h>

void print(char* s, int l, int r, int count){

  if(l < 0 || r < l)
      return;  // Invalid state. 

  if(l==0 && r==0){
    printf("%s \n",s);
  }
  else{
    if(l > 0){
        s[count] = '(';
        print(s, l-1, r, count+1);
    }

    if(r > 0 && r > l){
        s[count] = ')';
        print(s, l, r-1, count+1);
    }
  }

//printf("\n");
}


int main(){
  int n;
  char s[100];
  printf("Enter the number of paranthesis");
  scanf("%d",&n);
  print(s, n, n, 0);
  return 0;
}
