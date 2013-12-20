#include <stdio.h>
#include <stdlib.h>

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
  struct node* crawl = head->next;
  int i=1;
  while(crawl){
    printf("Node %d: %d  ",i++,crawl->data);
    crawl = crawl->next;
  }
}

struct node* find_mid(struct node *head){
	struct node *fast, *slow;
	slow = fast = head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

void del_mid(struct node* mid){
	struct node *tmp;
	while(mid->next){
		mid->data = mid->next->data;
		tmp = mid->next;
		mid->next = mid->next->next;
		mid = mid->next;
		free(tmp);	
	}
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
	printf("LL before deleting mid: \n");
	print(head);
	mid = find_mid(head);
	del_mid(mid);
	printf("\nLL atfer deleting mid\n");
	print(head);
	printf("\n");
	return 0;
}
