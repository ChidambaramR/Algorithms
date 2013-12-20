#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

remove_dup(struct node* head){
	struct node *out_crawl, *in_crawl, *dup;
	out_crawl = head;
	while(out_crawl->next){
		in_crawl = out_crawl;
		while(in_crawl->next){
			if(in_crawl->next->data == out_crawl->data){
				dup = in_crawl->next;
				in_crawl->next = in_crawl->next->next;
				free(dup);
			}
			else
				in_crawl = in_crawl->next;
			/*
			Only in Else, the in_crawl is moved because, when there is a duplicate
			entry, the in_crawl->next is automatically change as above. The in_crawl
			remains same, but in_crawl->next changed. Consider the case of
			12->43->43->43->23
			When in_crawl and out_crawl are pointing to 43, in_crawl->next points to 2nd 43.
			They are equal and hence the list now becomes
			12->43->43->23.
			Now if in_crawl = incrawl->next, in_crawl will be pointing to 3rd 43 and in_crawl->next
			will be 23 and out_crawl will be 43. So the program will consider they are not equal and
			continue with the loop.
			*/
		}
		out_crawl = out_crawl->next;
	}
}

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

void print_LL(struct node* head){
	struct node* crawl;
	crawl = head->next;
	while(crawl){	
		printf("%d -> ",crawl->data);
		crawl = crawl->next;
	}
	printf("\n");
}

int main(){	
	struct node* head;
	int n,i=1,data;

  	head = (struct node*)malloc(sizeof(struct node));
  	head->next = NULL;
  	printf("enter the number of nodes: ");
  	scanf("%d",&n);
  	while(n--){
  		printf("Enter node %d: ",i++);
  		scanf("%d",&data);
  		push(head, data);
  	}
	printf("LL before Deleting: \n");
	print_LL(head);
	remove_dup(head);
	printf("LL after Deleting: \n");
	print_LL(head);
	return 0;
}
