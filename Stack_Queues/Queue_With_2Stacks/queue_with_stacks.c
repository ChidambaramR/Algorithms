#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

struct stack{
	int data;
	struct stack *next;
};

struct queue{
	struct stack *stack1;
	struct stack *stack2;
	struct stack *s1_root;
	struct stack *s2_root;
};

void push(struct stack **s1, int data){
	struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
	if(temp == NULL){
		printf("Stack overflow");
		exit(0);
	}

	/*
	We are creating a reversed linked list here. Since all operations on stack
	happen at the top pointer, it is beneficial to have a reversed linked list.
	*/
	if((*s1) == NULL)
		temp->next = NULL;
	else
		temp->next = *s1;
	
	temp->data = data;
	*s1 = temp;
}

int pop(struct stack **s){
	struct stack *temp;
	int x;

	temp = *s;
	*s = (*s)->next;
	x = temp->data;
	free(temp);
	return x;
}


void enqueue(struct queue *q, int data){
	push(&q->stack1, data);
}

bool is_empty(struct stack *s){
	if(s == NULL)
		return true;
	else
		return false;
}

int dequeue(struct queue *q){
	int x;

	/*
	If stack 2 is empty, pop all elements from stack1 and push it on to stack2
		and pop the element off the stack2 and return it.
	If stack 2 is not empty, then pop the element off the stack2 and return it.
	*/
	if(q->stack2 == NULL){
		while(!is_empty(q->stack1)){
			x = pop(&(q->stack1));
			//printf("Popping %d\n",x);
			push(&(q->stack2), x);
		}
	}

	x = pop(&(q->stack2));
	return x;
}

void display_q(struct queue *q){
	struct stack *crawl;

	crawl = q->stack2;
	if(crawl == NULL)
		crawl = q->stack1;

	while(crawl != NULL){
		printf("%d ",crawl->data);
		crawl = crawl->next;
	}
	printf("\n");
}


int main(){
	struct queue *q;
	q = (struct queue*)malloc(sizeof(struct queue));
	if(q == NULL){
		printf("Queueu cannot be created as no memory\n");
		exit(0);
	}
	q->stack1 = NULL;
	q->stack2 = NULL;

	enqueue(q, 5);
	enqueue(q, 15);
	enqueue(q, 25);
	display_q(q);
	printf("\n\nDequeue %d\n\n",dequeue(q));
	display_q(q);
	return 0;
}
