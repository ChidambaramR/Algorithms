#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct node{
	int data;
	struct node *next;
};

bool push(struct node **head, int data){
	struct node *crawl = *head; // Crawler node
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(!temp){
		// Memory allocation failure
		return false;
	}

	// We are good
	temp->data = data;
	temp->next = NULL;
	if(!(*head)){
		/*
		This is the 1st element in the list.
		*/
		*head = temp;
		return true;
	}
	
	// Iterate till the end
	while(crawl->next)
		crawl = crawl->next;

	crawl->next = temp;
	return true;
}

void display(struct node *root){
	while(root){
		if(!root->next)
			printf("%d",root->data);
		else
			printf("%d ->",root->data);
		root = root->next;
	}
	printf("\n");
}

/*
Removes all the nodes in the linked list.
*/
bool remove_LL(struct node **head){
	struct node *crawl = *head;
	struct node *temp;

	if(!(*head))
		return true; // List is already NULL

	while(crawl){
		temp = crawl->next;
		free(crawl);
		crawl = temp;
	}

	*head = NULL;
	return true;
}

/*
Remove all occurences of a node in the linked list.
*/
bool remove_occurences(struct node **pHead, int data){
//	if((*head)->data == data){
	struct node *head = *pHead;
	struct node *temp;
	bool flag = false;

	if(!head) // List does not contain any data
		return 0;

	/*
	If the elements to be deleted occurs in the first
	*/
	while((*pHead)->data == data){
		temp = *pHead;
		*pHead = (*pHead)->next;	
		free(temp);
	}

	/*
	The 1st element is not the element to deleted.
	*/
	while(head->next){
		if(head->next->data == data){
			temp = head->next;
			head->next = head->next->next;
			free(temp);
			flag = true;
		}
		else{
			/*
			Tricky part. We need to advance the head only when the
			next element is not again the same element. For example, in the case
			10->20->20->20 and when we are in 10, head->next->data will be equal to 
			data. So we happily remove the second 20 and 10's next will be pointing to
			third 20. So if we advance the head pointer, the head will now go to thrid 20
			and will only check if 4th element is 20 or not. It will not check if the 3rd
			element is 20 as we are only checking head->next->data == data
			*/
			head = head->next;
		}
	}

	return flag;
}

bool remove_node(struct node **head, int data){
	struct node *temp, *del;
	bool flag = false;

	if((*head)->data == data){
		/*
		The data to be deleted is the head. 
		*/
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return true;	
	}

	// The element is somewhere in the list.
	temp = *head;
	while(temp->next){
		if(temp->next->data == data){
			/*	
			The next element is our data. 
			*/
			del = temp->next;
			temp->next = temp->next->next;
			free(temp);
			flag = true;
		}
		temp = temp->next;
	}

	return flag;
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

	// We are done inserting, now display it
	display(head);

	if(remove_occurences(&head, 20)){
		printf("\nAll occurences of 20 deleted successfuly\n");
		display(head);
	}
	else{
		printf("\n Element not found in the linked list\n");
	}


	if(remove_node(&head, 10)){
		printf("\nNode deleted successfuly\n");
		display(head);
	}
	else{
		printf("\nElement(10) not found in the linked list\n");
	}

	if(remove_LL(&head))
		printf("\nList deleted successfuly\n");

	return 0;
}
