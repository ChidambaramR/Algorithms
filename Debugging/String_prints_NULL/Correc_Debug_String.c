#include<stdio.h> 
#include<stdlib.h> 

void mystrcpy( char **string2 ,char *string1 ) 
{ 
  *string2 = malloc(20);
  /*
  Declaring a local variable here because,
  if we change string2, then when the loop exits its value
  will be NULL which is what the main function will see. So it
  will print NULL.
  */ 
  char *str = *string2;
  while( *string1 != '\0') {
    *str++ = *string1++; 
  } 


} 
int main() 
{ 
  printf("****************program starts*************************\n"); 
  char *str1 ="hello world"; 
  char *str2 =NULL; 
  mystrcpy( &str2,str1); 
  printf("string1 = %s string2 =%s \n",str1,str2) ; 
  return 0; 
} 
