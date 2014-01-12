#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

bool push(struct node **head, int data){
	struct node *crawl;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(!temp){
		// Memory cannot be allocated
		return false;
	}
	temp->data = data;
	temp->prev = temp->next = NULL;

	if(!(*head)){
		// If this is the 1st node
		*head = temp;
		return true;
	}

	crawl = *head;
	while(crawl->next)
		crawl = crawl->next;

	crawl->next = temp;
	temp->prev = crawl;
	return true;
}

bool del_node(struct node **head, int data){
	struct node *temp;
	struct node *del;
	if((*head)->data == data){
		// The node to be deleted is the head
		temp = *head;
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
		return true;
	}

	temp = *head;
	while(temp){
		if(temp->data == data){
			// We have found the element to be deleted
			if(temp->next)
				temp->next->prev = temp->prev;
			
			if(temp->prev)
				temp->prev->next = temp->next;

			free(temp);
		}
		temp = temp->next;
	}
}



void display(struct node *head){
	struct node *last_node;

	printf("\nList in forward direction \n");
	while(head){
		if(!(head->next)){ // Last node
			printf("%d",head->data);
			last_node = head;
		}
		else
			printf("%d -> ",head->data);

		head = head->next;
	}

	printf("\nList in forward direction \n");
	while(last_node){
		if(!(last_node->prev)) // First node
			printf("%d",last_node->data);
		else
			printf("%d <- ",last_node->data);

		last_node = last_node->prev;
	}
	printf("\n");
}


int main(){
	int no, n;
	struct node *head = NULL;
	printf("Enter the number of elements: ");
	scanf("%d",&no);
	while(no--){
		printf("Enter the number: ");
		scanf("%d",&n);
		if(!push(&head, n))
			printf("Cannot insert elements in the LL");
	}

	display(head);
	del_node(&head, 30);
	display(head);
	return 0;
}
