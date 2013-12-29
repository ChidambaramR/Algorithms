#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

void insert(struct node **root, int data){
	if(!(*root)){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	*root = temp;
	return;
	}

	if(data < (*root)->data)
		insert(&((*root)->left), data);
	else
		insert(&((*root)->right), data);
}

void print_tree(struct node* root){
	if(root == NULL)
		return;
	print_tree(root->left);
	printf("%d ",root->data);
	print_tree(root->right);	
}

/*
Function which find the minimum most
This goes to the lest most leaf
*/
struct node* findMin(struct node *root){
	struct node *current = root;
	while(current->left){
		current = current->left;
	}
	return current;
}


struct node* delete(struct node* root, int data){
	struct node *temp;

	if(data < root->data)
		root->left = delete(root->left, data);
	else if(data > root->data)
		root->right = delete(root->right, data);
	else{
	/* 
	Key values are same.
	There are three cases.
	1. The node to be deleted has no children.
	2. The node to be deleted has one children ( left or right )
	3. The node to be deleted has two children
	*/
		if(root->left != NULL && root->right != NULL){
			// Two children case
			temp = findMin(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
			/*
			The node to be deleted: 4
			-------------------------
					7
				       / \
				      4   9
				     / \
				    3   5
					 \
					  6
			Find Min: 5
			Root: 4
			Root->right = delete(root->right, 5)
			*/
			
		}
		else{
			// One child case
			temp = NULL;
			temp = root->left ? root->left : root->right;
			if(temp == NULL){
			// No child case
				temp = root;
				root = NULL;
			}
			else{
			/*
			The node to be deleted: 5
			-------------------------
					7
				       / \
				      4   9
				     / \
				    3   5
					 \
					  6
			Root: 5 
			Temp: root->right 6
			*root = *temp
				We are copying the contents of node 6 to node 5. So whatever is the
				tree following 6 will be replaced in 5. We will free node 6!!!!
				This is important, as we are not free'ng node 5. In that case we need to
				updated pointers in the parent node. 
			*/
				*root = *temp;
			}
			free(temp);
		}
	}
//	if(root == NULL)
		return root;
}


/*
Function to check if two given trees are same.
First check if the data at both the pointers are same. Then
we should also check if the left subtree and the right subtree
are equal. If everything is same, return TRUE to the parent node.
If one false is returned, then everything will be returned false
as we are using an && in the return statement.
*/
bool same_tree(struct node *root_a, struct node *root_b){
	if(root_a == NULL && root_b == NULL)
		return true;

	if((root_a != NULL) && (root_b != NULL)){
		return ((root_a->data == root_b->data)
			&& same_tree(root_a->left, root_b->left)
			&& same_tree(root_a->right, root_b->right));
	}
	else
		return false;
}

/*
Function which creates a new node and duplicates the value in the root.
It puts the new node as the left child. 
Just a pointer swap. 
Do the subtrees. 
When we are at the root node, create a new node. Assign its data to be 
 the value of root. Its left pointer will pointer to the root's left.
 Change root's left to point to the new node.
*/
void double_BST(struct node *root){
	if(root == NULL)
		return;

	struct node *temp;
	double_BST(root->left);
	double_BST(root->right);

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = root->data;
	temp->right = NULL;
	temp->left = root->left;
	root->left = temp;
}


/*
Function which mirrors the BST. i.e the left child now becomes
the right child and vice versa. Logic is simple. Do both the subtrees
and finally exchange the pointers
*/
void mirror_BST(struct node *root){
	if(root == NULL)
		return;
	
	struct node* temp;
	mirror_BST(root->left);
	mirror_BST(root->right);
	
	// Finish the sub-trees and then swap
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}


/*
Function which checks if a binary tree is BST or not
*/
bool is_BST(struct node* root, int min, int max){
	if(root == NULL)
		return 1;
	if(root->data < min || root->data > max)
		return 0;
	return (is_BST(root->left, min, root->data-1) &&
		is_BST(root->right, root->data+1, max));
}


/*
Function which checks if a particular path in the BST from the
root has the given sum.
*/
bool has_sum(struct node* root, int sum){
	bool found_L = 0;
	bool found_R = 0;
	
	if(root == NULL)
		return 0;
	
	if(sum - root->data == 0)
		return 1;

	found_L = (has_sum(root->left, sum - root->data));
	found_R = (has_sum(root->right, sum - root->data));

	return (found_L || found_R);
}


/*
Function to print all paths from root to a leaf.
Path is the array storing the values during recursive calls.
*/
int path[100];

void print_all_paths(struct node* root, int path_len){
	int i;
	
	if(root == NULL)
		return;

	path[path_len] = root->data;
	
	if(root->left == NULL && root->right == NULL){
		for(i=0; i <= path_len; i++)
			printf("%d ",path[i]);
		printf("\n");
	}	
	
	print_all_paths(root->left, path_len+1);
	print_all_paths(root->right, path_len+1);
}


/*
Function to find the number of nodes or size of a tree.
Find the number of nodes in the left sub tree.
Find the number of nodes in the right sub tree.
Add them.
Add 1 to the result for the root node and return
*/
int no_nodes(struct node* root){
	if(root == NULL)
		return 0;
	int left = no_nodes(root->left);
	int right = no_nodes(root->right);
	return 1+left+right;
}


/*
Normal Lookup
*/
bool lookup(struct node* root, int target){
	if(root == NULL)
		return false;
	
	if(target == root->data)
		return true;
	else{
		if(target < root->data)
			return (lookup(root->left, target));
		else
			return (lookup(root->right, target));
	}
}

/*
Function which calculates the maximum depth of the tree.
i.e A leaf in the tree which is deepest. 
Calculate the left sub-tree's depth.
Calculate the right sub-tree's depth.
Return the maximum of it plus one to the previous node.
*/
int max_depth(struct node* root){
	if(root == NULL)
		return 0;
	
	int left = max_depth(root->left);
	int right = max_depth(root->right);
	
	if(left > right)
		return 1+left;
	else
		return 1+right;
}


int main(){
	int n, no;
	struct node *root = NULL;
/*	root = (struct node*)malloc(sizeof(struct node));
	root->left = root->right = NULL;
	root->data = 20;
*/
	printf("Enter the size of input: ");
	scanf("%d",&n);
	while(n--){
		printf("Enter the number ");
		scanf("%d",&no);
		insert(&root, no);
	}
	printf("#################\n");
	printf("Contents \n");
	print_tree(root);
	printf("\n#################\n");
	printf("\n#################");
	printf("\nNo of nodes in the tree = %d \n",no_nodes(root));
	printf("\n#################\n");
	delete(root, 7);
	printf("#################\n");
	printf("Contents After deleting 7\n");
	print_tree(root);
	printf("\n#################\n");
	printf("\n###############\n");
	printf("\n#################\n");
	printf("Looking for sum 41 %d\n",has_sum(root, 41));
	print_all_paths(root, 0);
	printf("#################\n");
	printf("\n#################");
	printf("\nAfter mirroring the tree, BST looks like \n");
	mirror_BST(root);
	print_tree(root);
	printf("\n#################\n");
	printf("\n#################\n");
	printf("After doubling the tree, BST looks like \n");
	double_BST(root);
	print_tree(root);
	printf("\n#################\n");
	return 0;
}
