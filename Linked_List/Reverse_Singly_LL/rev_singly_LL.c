
#include <stdio.h>
#include <stdlib.h>

struct node *new_head;

struct node{
	int data;
	struct node* next;
};

void push(struct node **head, int data){
	struct node *crawl, *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data = data;

        if(!(*head)){
          *head = temp;
          return;
        }

	crawl = *head;
	while(crawl->next)
		crawl = crawl->next;

	crawl->next = temp;
}

void print(struct node*head){
  	struct node* crawl = head;
  	int i=1;
  	while(crawl){
                if(crawl->next)
    		  printf("%d -> ",crawl->data);
                else  
                  printf("%d",crawl->data);
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


struct node* rev_LL(struct node *head){
	struct node *first, *rest;
	
	if(head == NULL)
		return NULL;

	first = head;
	rest = head->next;
	
	if(rest == NULL){
		return head; // new head of the linked list
	}
	head = rev_LL(rest);
	rest->next = first;
	first->next = NULL;
        return head;

}

int main(){
  	int n,data;
  	int i=1;
  	struct node* head, *mid;
  	printf("Enter the number of nodes: ");
  	scanf("%d",&n);
  	while(n--){
  		printf("Enter node %d: ",i++);
  		scanf("%d",&data);
  		push(&head, data);
  	}
	print(head);
        printf("\n");
	head = rev_LL(head);
	print(head);
        printf("\n");
	return 0;
}
