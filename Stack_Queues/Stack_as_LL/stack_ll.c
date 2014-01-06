#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

/*
This is similar to inserting a node at the begining of the list.
It is just a different perspective of viewing the list.

Example, if we push the following data into the stack (1,2,3,4,5)
	the stack will look like NULL<-1<-2<-3<-4<-5 (top)
	The TOP element will be pointing to 5.

This list can also be viewed like following. 
	(head/top)5->4->3->2->1->NULL
	If we insert 1, then insert 2, the element will be added at the
	begining of the list and 1 is pushed back.
*/
void push(struct node **top, int data){
	struct node *temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	/*
	Stack is initially empty
	*/
	if(!(*top)){
		temp->next = NULL;
		*top = temp;
		return;
	}

	temp->next = *top;
	*top = temp;
}


void display(struct node *top){
	while(top){
		printf("%d ",top->data);
		top = top->next;
	}
}

int pop(struct node **top){
	int val = 0;
	struct node *elem = *top;

	val = elem->data;
	*top = (*top)->next;
	free(elem);

	return val;
}


int main(){
	int ch;
	int no;
	int val;
	struct node *top = NULL;

	do{
		printf("\n\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("Enter the number: ");
				scanf("%d",&no);
				push(&top, no);
				break;

			case 2: val = pop(&top);
				printf("Value = %d\n",val);
				break;

			case 3: display(top);
				break;

			case 4: exit(0);
				break;
		
			default: printf("Enter a valid operation\n");
		}
	}while(1);

	return 0;
}
