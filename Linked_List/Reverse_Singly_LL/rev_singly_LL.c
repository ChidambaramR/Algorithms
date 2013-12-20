
#include <stdio.h>
#include <stdlib.h>

struct node *new_head;

struct node{
	int data;
	struct node* next;
};

void push(struct node *head, int data){
	struct node *crawl, *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data = data;

	crawl = head;
	while(crawl->next)
		crawl = crawl->next;

	crawl->next = temp;
}

void print(struct node*head){
  	struct node* crawl = head;
  	int i=1;
  	while(crawl){
    		printf("Node %d: %d  ",i++,crawl->data);
    		crawl = crawl->next;
  	}
}

void iter_rev_LL(struct node** head){
	struct node *prev, *crawl, *temp;
	crawl = *head;
	prev = NULL;
	while(crawl){
		temp = crawl->next;
		crawl->next = prev;
		prev = crawl;
		crawl = temp;
	}
	*head = prev;
}


void rev_LL(struct node **head){
	struct node *first, *rest;
	
	if(*head == NULL)
		return ;

	first = *head;
	rest = (*head)->next;
	
	if(rest == NULL){
		new_head = first; 
		return;
	}
	printf("head before rev_LL for node %d is %p\n",first->data, *head);
	rev_LL(&rest);
	printf("head after rev_LL for node %d is %p\n",first->data, *head);
	first->next->next = first;
	first->next = NULL;		

}

int main(){
  	int n,data;
  	int i=1;
  	struct node* head, *mid;
  	head = (struct node*)malloc(sizeof(struct node));
  	head->next = NULL;
  	printf("Enter the number of nodes: ");
  	scanf("%d",&n);
  	while(n--){
  		printf("Enter node %d: ",i++);
  		scanf("%d",&data);
  		push(head, data);
  	}
	iter_rev_LL(&head);
	printf("After reversing LL\n");
	print(head);
	return 0;
}
