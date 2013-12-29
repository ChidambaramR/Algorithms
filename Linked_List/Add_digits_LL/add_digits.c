#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head_c;

void push(struct node *head, int data){
  struct node *temp, *crawl;
  crawl = head;
  // Create a temporary node
  temp = (struct node*)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->data = data;

  // Loop till the last node
  while(crawl->next)
    crawl = crawl->next;

  // Last node's next is newly created node as it is appending
  crawl->next = temp;
}

int recurse_sum(struct node *head_a, struct node *head_b){
	if( head_a == NULL || head_b == NULL)
		return 0;

	int carry =  0;
	int num;

	carry = recurse_sum(head_a->next, head_b->next);
	num = (head_a->data + head_b->data + carry);
	if(num >= 10){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num-10;
		temp->next = head_c->next;
		head_c->next = temp;
		return 1;
	}
	else{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->next = head_c->next;
		head_c->next = temp;
		return 0;
	}	
		
		 
}

void add_digits(struct node *head_a, struct node *head_b, int len_a, int len_b){
	if(len_a == len_b)
		recurse_sum(head_a, head_b);
}

void print(struct node *root){
	struct node *crawl;
	crawl = root;
	while(crawl){
		printf("%d",crawl->data);
		crawl = crawl->next;
	}
	printf("\n");
}

int main(){
  int n,data;
  int i=1;
  int len_a, len_b;
  struct node *head_a, *head_b;
  // Create node 1
  head_a = (struct node*)malloc(sizeof(struct node));
  head_a->next = NULL;

  // Create node 2
  head_b = (struct node*)malloc(sizeof(struct node));
  head_b->next = NULL;

  // Resultant Node
  head_c = (struct node*)malloc(sizeof(struct node));
  head_c->next = NULL;

  printf("Enter the number of digits in No1: ");
  scanf("%d",&n);
  len_a = n;
  while(n--){
  printf("Enter digit %d: ",i++);
  scanf("%d",&data);
  push(head_a, data);
  }

  printf("Enter the number of digits in No2: ");
  scanf("%d",&n);
  len_b = n;
  while(n--){
  printf("Enter digit %d: ",i++);
  scanf("%d",&data);
  push(head_b, data);
  }

  add_digits(head_a->next, head_b->next, len_a, len_b);
  
  print(head_c->next);
  return 0;
}
