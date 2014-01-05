#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert(struct node* root, int data){
	if(!root){
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}

	if(data < root->data){
		root->left = insert(root->left, data);
	}
	else if(data > root->data){
		root->right = insert(root->right, data);
	}

	return root;
}

void display(struct node *root){
	if(root == NULL)
		return;

	display(root->left);
	printf("%d ",root->data);
	display(root->right);
}

/*
This is the usual logic to find if two trees are same. We have a pointer to both the roots.
If both the data in root are itself different, then we return false.
If data in both the root nodes are same, then we see if the left-subtree of both the trees
	are same or not by calling is_indetical(tree1->left, tree2->left).
Similarly we check if the right subtree of both the trees are identical by calling
	is_identical(tree1->right, tree2->right)
If all the three condition satisifes we return true to the previous level. 
If all the three conditions in the root node itself is satisified then it means that are the
	trees are identical and we return true.
*/
bool is_identical(struct node* tree1, struct node* tree2){
	if(tree1 == NULL && tree2 == NULL)
		return true;

	if(tree1 == NULL || tree2 == NULL)
		return false;

	return ((tree1->data == tree2->data) && is_identical(tree1->left, tree2->left) 
		&& is_identical(tree1->right, tree2->right));
}

/*
Consider the trees.
	TREE1:
	------
           26
          /  \
         10   3
        /  \   \
       4    6   3
        \
        30

	TREE2:
	------
     	 10  
        /  \ 
       4    6
        \
        30

Tree1 will be pointing to 26. Tree2 will be pointing to 10.
First we check if these two trees are identical. If not,
we check the left subtree of tree1 and tree2 are identical or
right subtree of tree1 and tree2 are identical. This continues till
we traverse all the nodes in tree1. 
*/

bool is_subtree(struct node *tree1, struct node *tree2){
	if(tree1 == NULL)
		return false;

	if(tree2 == NULL)
		return true;

	if(is_identical(tree1, tree2))
		return true;

	return (is_subtree(tree1->left, tree2) || is_subtree(tree1->right, tree2));
}

int main(){
	struct node *root = NULL;
	int n, no;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	while(n--){
		printf("Enter the number: ");
		scanf("%d",&no);
		root = insert(root, no);
	}
	display(root);
}
