#include<stdio.h>
#include <stdlib.h>

struct node{
	struct node *next;
	int data;
};

#ifdef SPECIAL_INSERT

int insert_head(struct node **head, struct node **tail, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return -1;

	temp->data = data;
	if(!(*head)){
		// 1st node
		*head = *tail = temp;
		temp->next = NULL;
		return 0;
	}

	// We already have some valid LL
	temp->next = *head;
	*head = temp;
	return 0;
}

int insert_tail(struct node **tail, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return -1;

	(*tail)->next = temp;
	temp->data = data;
	temp->next = NULL;
	(*tail) = temp;
}

int insert_mid(struct node *crawl, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return -1;

	temp->data = data;
	temp->next = crawl->next;
	crawl->next = temp;
}

int insert(struct node **head, struct node **tail, int data){
	
	struct node *crawl = *head;
	if(!(*head) || data <= (*head)->data)
		return insert_head(head, tail, data);
	else if(data > (*tail)->data)
		return insert_tail(tail, data);
	else{
		while(crawl->next && (crawl->next->data < data))
			crawl = crawl->next;
		return insert_mid(crawl, data);
	}
}

#endif

#ifdef NORMAL_INSERT

int push(struct node **head, int data){
	struct node *temp;
	struct node *crawl;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return -1;
	temp->data = data;
	temp->next = NULL;

	if(!(*head)){
		*head = temp;
		temp->next = NULL;
		return 0;
	}

	crawl = *head;
	while(crawl->next)
		crawl = crawl->next;
	crawl->next = temp;

	
}

#endif

void reverse(struct node **head, int k){
	struct node *current = *head;
	struct node *next;
	struct node *prev = NULL;
	int count = 0;

	while(current != NULL && count < k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

}


void print(struct node *head){
	while(head){
		if(head->next)
			printf("%d -> ",head->data);
		else
			printf("%d",head->data);
		head = head->next;
	}
	printf("\n");
}

int main(){
	struct node *head, *tail;
	int n, temp, data;
	printf("Enter the total number of nodes");
	scanf("%d",&n);
	temp = n;
	head = tail = NULL;
	while(n--){
		printf("Enter node %d", temp-n);
		scanf("%d",&data);
#ifdef SPECIAL_INSERT
		insert(&head, &tail, data);
#endif
#ifdef NORMAL_INSERT
		push(&head, data);
#endif
	}
	print(head);
	reverse(&head, 3);
	print(head);
	return 0;
}
