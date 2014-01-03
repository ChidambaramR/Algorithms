#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top1=0, top2=MAX-1;

void push1(int x){
	if(top1 < top2-1){
		top1++;
		stack[top1] = x;
	}
	else{
		printf("Stack 1 overflow\n");
		exit(0);
	}
}

void push2(int x){
	if( top1 < top2-1){
		top2--;
		stack[top2] = x;
	}
	else{
		printf("Stack 2 overflow\n");
		exit(0);
	}
	
}

int pop1(){
	if(top1 >= 0)
		return stack[top1--];
	else{
		printf("Stack 1 is empty\n");
		return -1;
	}
}

int pop2(){
	if(top2 < MAX)
		return stack[top2++];
	else{
		printf("Stack 2 is empty\n");
		return -1;
	}
}

int main(){
	push1(5);
	push2(6);
	push2(7);
	push1(8);
	return 0;
}
