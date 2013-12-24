#include <stdio.h>
#include <stdlib.h>

struct node_LL{
	int data;
	struct node_LL *next;
};

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void push(struct node *root, int data){
	struct node_LL *crawl;
	struct node_LL *temp;
	crawl = root;
	while(crawl->next)
		crawl = crawl->next;

	temp = (struct node_LL*)malloc(sizeof(struct node_LL));
	temp->next = NULL;
	temp->data = data;
	crawl->next = temp;

}

void print(struct node_LL *root){
	struct node_LL *crawl = root;
	while(crawl){
		printf("%d-> ",crawl->data);
		crawl = crawl->next;
	}
}

struct node* ll_to_bst(struct node_LL *list, int start, int end){
	if(start > end)
		return NULL;

	int mid = (start+end)/2;
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = 
	new->left = ll_to_bst(list, start, mid-1);
	list = list->next;
	new->right = ll_to_bst(list, mid+1, end);
	return new;
}

int main(){
	struct node_LL *root;
	root = (struct node_LL*)malloc(sizeof(struct node_LL));
	root->next = NULL;
  	printf("enter the number of nodes");
  	scanf("%d",&n);
  	while(n--){
 		printf("Enter node %d",i++);
  		scanf("%d",&data);
  		push(head, data);
  	}
  	print(root->next);
	ll_to_bst(root->next);
	return 0;
}
