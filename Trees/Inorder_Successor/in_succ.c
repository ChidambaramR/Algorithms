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

	if(data < (*root)->left)
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

	// Min value in the right sub tree
	if(temp->right){
		current = temp->right;
		while(current->left)
			current = current->left;
		return current;
	}

	current = temp->parent;
	while((current != NULL)
}

int main(){
	return 0;
}
