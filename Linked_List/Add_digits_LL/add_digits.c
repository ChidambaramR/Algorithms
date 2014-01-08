#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head_c;

void push(struct node **head, int data){
  struct node *temp, *crawl;
  crawl = *head;

  // Create a temporary node
  temp = (struct node*)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->data = data;

  if(!(*head)){
    *head = temp;
    return;
  }
  // Loop till the last node
  while(crawl->next)
    crawl = crawl->next;

  // Last node's next is newly created node as it is appending
  crawl->next = temp;
}

int recurse_sum(struct node *head_a, struct node *head_b){
	if(head_a == NULL && head_b == NULL)
		return 0;

	int carry =  0;
	int num;

	carry = recurse_sum(head_a->next, head_b->next);
	num = (head_a->data + head_b->data + carry);
	
	// Create the new node in the LL
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->next = head_c;
	head_c = temp;
	temp->data = num%10;
	
	if(num >= 10)
		return 1;
	else
		return 0;
		
		 
}

void add_digits(struct node *head_a, struct node *head_b, int len_a, int len_b){
	int carry = 0;
	/*
	We need this temporary variables because, we need to assign the head pointer
	of the new list as one of these head pointers. Because, we are just gonna
	append the bigger list. i.e If the list is 1->2->3->4 and other list is
	1->2,
	We calculate the difference in lengths and move the pointer in the bigger list
	to the same place where the second list is starting. Once the equal length list
	addition is made, we add the carry to left part of the bigger list and APPEND our
	new list to this list. Thus the list becomes 1->2->4->6. The 4->6 is the new list
	and it has been appended to our bigger list 1->2->3->4. Thus if we move the head
	pointer which we got, then we will loose track of the head pointers of the list
	to make the append operation and make the new head point to one of the heads which
	we received. 
	*/
	struct node *thead_a, *thead_b;
	thead_a = head_a;
	thead_b = head_b;
	if(len_a > len_b){
		while(len_a-1 > len_b){
			len_a--;
			thead_a = thead_a->next;
		}
		carry = recurse_sum(thead_a->next, thead_b);
		thead_a->data = carry + thead_a->data;
		thead_a->next = head_c;
		head_c = head_a;
		
	}
	if(len_b > len_a){
		while(len_b-1 > len_a){
			len_b--;
			thead_b = thead_b->next;
		}
		carry = recurse_sum(thead_a, thead_b->next);
		thead_b->data = carry + thead_b->data;
		thead_b->next = head_c;
		head_c = head_b;
	}
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
  head_a = head_b = NULL;

  printf("Enter the number of digits in No1: ");
  scanf("%d",&n);
  len_a = n;
  while(n--){
  printf("Enter digit %d: ",i++);
  scanf("%d",&data);
  push(&head_a, data);
  }

  printf("Enter the number of digits in No2: ");
  scanf("%d",&n);
  len_b = n;
  while(n--){
  printf("Enter digit %d: ",i++);
  scanf("%d",&data);
  push(&head_b, data);
  }

  add_digits(head_a, head_b, len_a, len_b);
  
  print(head_c);
  return 0;
}
