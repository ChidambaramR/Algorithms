#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node* next;
	int data;
} *tail = NULL;

int insert_begining(struct node **head, int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return 0;
	temp->data = data;
	/*
	If this is the 1st node in the LL
	*/
	if(!(*head)){
		temp->next = NULL;
		*head = temp;
		tail = *head;
		return 1;
	}

	temp->next = (*head);
	(*head) = temp;
	return 1;
		
}

int insert_after(struct node *head, int mid_data, int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	int ret=0;
	if(!temp)
		return 0;
	temp->data = data;

	/*
	If mid_data is actually the head's data
	*/
	if(head->data == mid_data){
		ret = insert_begining(&head, data);
		return ret;
	}

	while(head->next){
		if(head->next->data == mid_data){
			temp->next = head->next;
			head->next = temp;
			return 1;
		}
		head = head->next;
	}
	
	// Mid_data not found
	return 0;
}

int insert_end(struct node **head, int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return 0;
	temp->data = data;
	temp->next = tail->next;

	/*
	Use the tail pointer which is pointing to the end.
	*/
	if(!tail){
		*head = temp;
		tail = temp;
		return 1;
	}

	tail->next = temp;
	tail = temp;
}


int delete(struct node **head, struct node* elem){
	struct node *crawl = *head;

	if(!elem)
		return 0;
	/*
	When the element to be deleted is the head node.
	*/
	if(elem == *head){
		(*head) = (*head)->next;
		free(elem);
		// If no more element in the linked list, tail and head are NULL
		if(!(*head))
			tail = NULL;
		return 1;
	}	

	/*
	Search for the element
	*/
	while((crawl->next) && (crawl->next != elem)){
		crawl = crawl->next;
	}	

	/*
	If the element is not found, then return 0
	*/
	if(crawl->next == NULL)
		return 0;

	/*
	Element has been found
	*/
	crawl->next = elem->next;
	free(elem);
	/*
	If the element to be deleted is the last element, the update
	the tail pointer to the last node.
	*/
	if(crawl->next == NULL)
		tail = crawl;
	return 1;
}

/*
Just a wrapper function which sends the pointer to the element be deleted
to the main delete function.
*/
int del_node(struct node *head, int data){
	struct node *crawl = head;
	struct node *temp;
	int ret=0;

	while(crawl){
		if(crawl->data == data){
			temp = crawl;
		}
		crawl = crawl->next;
	}
	return delete(&head, temp);
}


void display(struct node *head){
	printf("\n");
	while(head){
		printf("%d -> ",head->data);
		head = head->next;
	}
	printf("\n");
}

int main(){
	int n, data, i=0, dnode;
	struct node *head = NULL;
  	printf("Enter the number of nodes: ");
  	scanf("%d",&n);
  	while(n--){
  		printf("Enter node %d: ",i++);
  		scanf("%d",&data);
  		//insert_begining(&head, data);
		insert_end(&head, data);
  	}
	display(head);
	printf("Enter the node you want to delete: ");
	scanf("%d",&dnode);
	if(!del_node(head, dnode))
		printf("Node to be deleted not found\n");
	display(head);
	return 0;
}
