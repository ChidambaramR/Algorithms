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
		temp->left = temp->right = NULL;
		temp->parent = NULL;
		(*root) = temp;
		return;
	}

	if(data < (*root)->data){
		insert(&((*root)->left), data);
		(*root)->left->parent = *root;
	}
	else{
		insert(&((*root)->right), data);
		(*root)->right->parent = *root;
	}
}

/*
This method can be applied to any binary tree. Not only binary search tree.
This method is very efficient when applied to any binary trees. It tries to search
for both the nodes. When one of the node is found, it starts returning the pointer
to the node which was found. Similarly when other node is found it starts returning
the pointer. The point where both left and right pointers are not null, we have found
the root and we will return the pointer to that node. 
*/
struct node* lca_efficient(struct node *root, int n1, int n2){
	struct node *left, *right;
	
	if(root == NULL)
		return NULL;

	if(root->data == n1 || root->data == n2)
		return root;

	left = lca_efficient(root->left, n1, n2);
	right = lca_efficient(root->right, n1, n2);
	
	if(left && right)
		return root;

	return (left ? left : right );
}


struct node* lca(struct node *root, int n1, int n2){
	if(root == NULL)
		return NULL;

	/*
	If the node's data is greater than n1 and n2, then it means
	the LCA for n1 and n2 must be in node's left subtree.
	*/
	if((root->data > n1) && (root->data > n2))
		return lca(root->left, n1, n2);
	
	/*
	If the node's data is less than n1 and n2, then it means the
	LCA for n1 and n2 must be in the right subtree of node.
	*/
	if((root->data < n1) && (root->data < n2))
		return lca(root->right, n1, n2);

	/*
	The point at which one of the node is less than the current node and the other
	node is greater than the current node is the LCA of the two nodes.
	*/
	return root;
}

/*
This method can be applied to any binary tree, given a parent pointer.
*/
struct node* lca_parent(struct node *nd1, struct node *nd2){
	struct node *cur1 = nd1;
	struct node *cur2 = nd2;

	int nd1_height = 0;
	while(cur1->parent != NULL){	
		nd1_height++;
		cur1 = cur1->parent;
	}

	int nd2_height = 0;
	while(cur2->parent != NULL){
		nd2_height++;
		cur2 = cur2->parent;
	}

	int diff = nd1_height - nd2_height;
	cur1 = nd1;
	cur2 = nd2;

	if(diff > 0){
		while(diff--){
			cur1 = cur1->parent;
		}
	}
	else{
		diff = -diff;
		while(diff--){
			cur2 = cur2->parent;
		}
	}

	while(1){
		if((cur1 == NULL) || (cur2 == NULL))
			break;
		if(cur1 == cur2)
			return cur1;
		cur1 = cur1->parent;
		cur2 = cur2->parent;
	}

	return NULL;
}

struct node* search(struct node *root, int data){
	if(root == NULL)
		return NULL;

	if(root->data == data)
		return root;
	else if(data < root->data)
		return search(root->left, data);
	else if(data > root->data)
		return search(root->right, data);
}

int main(){
	struct node *root = NULL;
	struct node *lca_bst;
	struct node *n1, *n2;
	struct node *lca_parent_node;
	int no, n;
	int nd1, nd2;

	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	while(n--){
		printf("Enter the number: ");
		scanf("%d",&no);
		insert(&root, no);
	}
	printf("Enter the two nodes: ");
	scanf("%d %d",&nd1,&nd2);
	lca_bst = lca(root, nd1,nd2);
	printf("\nLCA = %d\n",lca_bst->data);

	n1 = search(root, nd1);
	n2 = search(root, nd2);
	printf("%d %d\n",n1->data, n2->data);

	lca_parent_node = lca_efficient(root, nd1, nd2);
	printf("LCA with parent = %d\n",lca_parent_node->data);
	return 0;
}
