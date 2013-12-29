#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void insert(struct node **root, int data){
	if(!(*root)){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->left = temp->right = NULL;
		temp->data = data;
		(*root) = temp;
		return;
	}

	if(data < (*root)->data)
		insert(&((*root)->left), data);
	else
		insert(&((*root)->right), data);
		
}

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}


int height(struct node *root){
	if(root == NULL)
		return 0;

	return (1 + max(height(root->left), height(root->right)));
}

bool is_balanced(struct node *root){
	if(root == NULL)
		return 1;

	int lh,rh;
	// Get the height of left tree and right tree
	lh = height(root->left);
	rh = height(root->right);

	if( (abs(lh-rh) <= 1) && is_balanced(root->left)
		&& is_balanced(root->right) )
		return 1;

	return 0;
}

void print(struct node *root){
	if(root == NULL)
		return;

	print(root->left);
	printf("%d ",root->data);
	print(root->right);
}


int main(){
	int n, no;
	struct node *root;
	root = (struct node*)malloc(sizeof(struct node));
	root = NULL;

	printf("Enter the size of input: ");
	scanf("%d",&n);
	while(n--){
		printf("Enter the number ");
		scanf("%d",&no);
		insert(&root, no);
	}
	
	if(is_balanced(root))
		printf("Tree is height balanced\n");
	else
		printf("Tree is not balanced\n");
	//print(root);
}
