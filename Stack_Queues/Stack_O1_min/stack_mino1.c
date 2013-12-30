#include <stdio.h>
#include <string.h>
#define MAX 99

typedef enum { false, true } bool;

struct stack{
  int a[MAX];
  int top;
} s1, s2;

bool is_empty(struct stack *s){
  if(s->top <= -1)
    return true;
  else
    return false;
}

bool is_full(struct stack *s){
  if((s->top + 1) > MAX)
    return true;
  else
    return false;
}


int pop(struct stack *s){
  if(is_empty(s)){
    printf("Stack is empty\n");
    return 0;
  }

  return s->a[s->top--];
}

void push(struct stack *s, int data){
  if(is_full(s)){
    printf("Stack is FULL\n");
    return;
  }
  s->top++;
  s->a[s->top] =  data;
  return;
}

int top(struct stack* s){
  return s->a[s->top];
}

/*
Find MIN in the auxillary stack. 
*/
int FindMin(struct stack *s){
  return s->a[s->top];
}

void pushS(struct stack *s1, struct stack *s2, int data){
  
  /*
  If the auxillary stack is empty, then it means we are inserting first time
  So we can insert into both the stacks. 
  */
  if(is_empty(s2)){
    push(s1, data);
    push(s2, data);
  }
  else{
    int y = top(s2);
    if(data < y)
      push(s2, data);
    push(s1, data);
  }
}

void init_stack(struct stack *s1, struct stack *s2){
  memset(s1->a, 0, sizeof(s1->a));
  memset(s2->a, 0, sizeof(s2->a));
  s1->top = s2->top = -1;
}

int main(){
    struct stack s1, s2;
    init_stack(&s1, &s2);
    pushS(&s1, &s2, 5);
    pushS(&s1, &s2, 25);
    pushS(&s1, &s2, 15);
    pushS(&s1, &s2, 8);
    pushS(&s1, &s2, 2);
    pushS(&s1, &s2, 45);
    printf("Min in O(1) time is %d\n",FindMin(&s2));
   return 0;
}
