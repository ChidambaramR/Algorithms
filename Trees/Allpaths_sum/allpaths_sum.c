#include <stdio.h>
#include <stdlib.h>

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

	if(data < root->data)
		root->left = insert(root->left, data);
	else if(data > root->data)
		root->right = insert(root->right, data);

	return root;
}

int path[100];

void print_sum(struct node*root, int sum, int level){
	int tmp=0;
	int i,j;

	if(root == NULL)
		return;

	path[level] = root->data;

	for(i=level; i>=0; i--){
		tmp = tmp + path[i];
		if(tmp == sum){
			for(j=level; j>=0; j--)
				printf("%d ",path[j]);
			printf("\n");
		}
	}

	print_sum(root->left, sum, level+1);
	print_sum(root->right, sum, level+1);
}

int main(){
	struct node* root = NULL;
	int no, n;
	int sum;

	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	while(n--){
		printf("Enter the number: ");
		scanf("%d",&no);
		root = insert(root, no);
	}
	printf("Enter the target sum: ");
	scanf("%d",&sum);
	print_sum(root, sum, 0);
	return 0;
}
