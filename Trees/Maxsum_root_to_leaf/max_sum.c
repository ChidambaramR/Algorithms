#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void insert(struct node **root, int data){
	if(!(*root)){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->left = temp->right = NULL;
		(*root) = temp;
		return;
	}

	if(data < (*root)->data)
		insert(&((*root)->left), data);
	else
		insert(&((*root)->right), data);
}

int max(int a, int b){
	return (a>b)?a:b;
}

int max_sum(struct node *root){
	if(root == NULL)
		return 0;

	int l_sum = max_sum(root->left);
	int r_sum = max_sum(root->right);
	return (max(l_sum, r_sum) + root->data);
}

void print(struct node *root){
	if(root == NULL)
		return;

	print(root->left);
	printf("%d ",root->data);
	print(root->right);
}

int main(){
	struct node *root;
	int n, no;
	root = NULL;

  	printf("Enter the size of input: ");
  	scanf("%d",&n);
  	while(n--){
    		printf("Enter the number: ");
    		scanf("%d",&no);
    		insert(&root, no);
  	}

	printf("\n Contents of Tree: ");
	print(root);
	printf("\n");
	printf("Max sum from the root = %d\n",max_sum(root));
	return 0;
}
