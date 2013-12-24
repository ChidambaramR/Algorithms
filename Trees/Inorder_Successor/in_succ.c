#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

void insert(struct node **root, int data){
	if(!(*root)){
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->right = temp->left = NULL;
		temp->parent = (*root);
		(*root) = temp;
		return;
	}

	if(data < (*root)->data)
		insert(&((*root)->left), data);
	else
		insert(&((*root)->right), data);
}

void print_tree(struct node *root){
	if(root == NULL)
		return;

	print_tree(root->left);
	printf("%d ",root->data);
	print_tree(root->right);
}

struct node* lookup(struct node *root, int target){
	if(root == NULL)
		return 0;
	
	if(target == root->data)
		return root;
	else{
		if(target < root->data)
			return lookup(root->left, target);
		else
			return lookup(root->right, target);
	}	
}
struct node* inorder_succ(struct node *root, int target){
	struct node* temp = lookup(root, target);
	struct node* current;

	if(temp == NULL)
		return 0;

	/*
	If right sub tree is not NULL, then the left most child
	in the right sub-tree is the in-order successor.
	If the right child does not have a left child, then the 
	right child is the in-order successor.
	*/
	if(temp->right){
		current = temp->right;
		while(current->left)
			current = current->left;
		return current;
	}

	/*
	1. If right sub-tree is NULL, then get the parent pointer
	of the current node, traverse up the tree, till the node we
	are visiting is the left child of its parent. If one such node is found
	its parent is the in-order successor.
	*/
	current = temp->parent;
	while((current != NULL) && root == current->right){
		root = current;
		current = current->parent;
	}
	
	return current;
}



int main(){
	int n, no;
	struct node *root, *in_suc;
	root = (struct node*)malloc(sizeof(struct node));
	root->left = root->right = NULL;
	root->data = 20;

	printf("Enter the size of input: ");
	scanf("%d",&n);
	while(n--){
		printf("Enter the number ");
		scanf("%d",&no);
		insert(&root, no);
	}
	printf("Enter the no for which you want to find inorder_succ ");
	scanf("%d",&n);
	in_suc = inorder_succ(root, n);
	printf("In order successor of %d is %d\n",n,in_suc->data);
	return 0;
}
