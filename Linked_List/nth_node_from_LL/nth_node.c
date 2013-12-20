#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void push(struct node* head, int data){
	struct node *crawl, *temp;
	crawl = head;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data = data;
	
	while(crawl->next)
		crawl = crawl->next;
	crawl->next = temp;
}

struct node* rec_find_nth(struct node* head, int *n){
	struct node* ref;
	if(head == NULL)
		return NULL;
	else{
		ref = rec_find_nth(head->next, n);
		if(ref != NULL)
			return ref;
		*n = *n - 1;
		if(*n == 0)
			return head;
		return NULL;
	}
}

struct node* find_nth(struct node* head, int n){
	struct node *main_p, *ref;
	int i=1;
	main_p = ref = head;
	
	// Make the 1st pointer to point to 'n'th node from begining.
	while(i<n){
		ref = ref->next;
		i++;
	}
	
	// Increment till 1st pointer reaches end. 
	while(ref->next){
		ref = ref->next;
		main_p = main_p->next;
	}
	return main_p;
}

int main(){
  	int n,data;
  	int i=1;
  	struct node* head, *ans;
  	head = (struct node*)malloc(sizeof(struct node));
  	head->next = NULL;
  	printf("enter the number of nodes: ");
  	scanf("%d",&n);
  	while(n--){
  		printf("Enter node %d: ",i++);
  		scanf("%d",&data);
  		push(head, data);
  	}
	n = 3;
	ans = rec_find_nth(head, &n);
  	printf("Nth node from last = %d\n",ans->data);
	return 0;
}
		
