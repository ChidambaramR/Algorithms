#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

/*
This follows a logic similar to binary search.
For getting a balanced binary tree the best element which can be root
is the middle element.
So each time we pick the middle element and make it as the root
and we add left and right nodes to it.
*/
struct node* arr_to_BST(int *a,int start,int end){
	if(start > end)
		return NULL;

	int mid = (start + end)/2;
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = a[mid];
	new->left = arr_to_BST(a,start,mid-1);
	new->right = arr_to_BST(a,mid+1,end);
	return new;
}


void print(struct node *root){
	if(root == NULL)
		return;

	print(root->left);
	printf("%d ",root->data);
	print(root->right);
}


int main(){
	int a[] = {1,3,5,7,8,9,12,14};
	struct node *root = arr_to_BST(a,0,7);
	print(root);
	return 0;
}
