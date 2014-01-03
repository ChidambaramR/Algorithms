#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
} *root = NULL;


void push(struct node **top, int data){
	struct node *temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data = data;
	
	if((*top) == NULL){
		root = temp;
	}
	else{
		(*top)->next = temp;
	}

	(*top) = temp;
}


void display(struct node *root){
	struct node *crawl = root;
	while(crawl){
		printf("%d ",crawl->data);
		crawl = crawl->next;
	}
}

int pop(struct node **top){
	int val = 0;
	struct node *crawl = root;

	while(crawl->next != *top)
		crawl = crawl->next;

	val = (*top)->data;
	*top = crawl;
	(*top)->next = NULL;	
	free(crawl->next);

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

			case 3: display(root);
				break;

			case 4: exit(0);
				break;
		
			default: printf("Enter a valid operation\n");
		}
	}while(1);

	return 0;
}
