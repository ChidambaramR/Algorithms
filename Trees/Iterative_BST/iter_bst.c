#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct tNode{
	int data;
	struct tNode* left;
	struct tNode* right;
};

/*
Our stack. The stack is going to store pointers to tree structures.
Thus, instead of usual int data, we have pointers to tree structures.
*/
struct sNode{
	struct tNode* t;
	struct sNode* next;
};

/* Function to push an item to sNode*/
void push(struct sNode** top_ref, struct tNode *t)
{
  	/* allocate tNode */
  	struct sNode* new_tNode =
            (struct sNode*) malloc(sizeof(struct sNode));
 
  	if(new_tNode == NULL){
     		printf("Stack Overflow \n");
     		exit(0);
  	}           
 
  	/* put in the data  */
  	new_tNode->t  = t;
 
  	new_tNode->next = (*top_ref);  
 
  	/* move the head to point to the new tNode */
  	(*top_ref)    = new_tNode;
}
 

/* The function returns true if stack is empty, otherwise false */
bool isEmpty(struct sNode *top){
   	return (top == NULL)? 1 : 0;
} 

/* Function to pop an item from stack*/
struct tNode *pop(struct sNode** top_ref)
{
  	struct tNode *res;
  	struct sNode *tempp;
 
  	/*If sNode is empty then error */
  	if(isEmpty(*top_ref)){
     		printf("Stack Underflow \n");
     		exit(0);
  	}
  	else{
     		tempp = *top_ref;
     		res = tempp->t;
     		*top_ref = tempp->next;
     		free(tempp);
     		return res;
  	}
}

/*
Normal BST insert
*/
struct tNode* insert(struct tNode* root, int data){
	if(!root){
		struct tNode* temp = (struct tNode*)malloc(sizeof(struct tNode));
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

void in_order(struct tNode *root){
	struct tNode* current = root;	
	/*
	Initialization of the stack to NULL.
	*/
	struct sNode* s = NULL;
	/*
	Similar to our recursive call
	*/
	while(1){
		if(current != NULL){
			push(&s, current);
			current = current->left;
		}
		else{
			/*
			We have pushed all the left sub-tree elements. Now 
			*/
			if(!isEmpty(s)){
				current = pop(&s);
				printf("%d ", current->data);
				/*
				The left sub-trees we taken care of by the 1st iterative call 
				So we need to take care of the right subtree of each node.
				*/	
				current = current->right;
			}
			else
				break;
		}
	}
	
}


int main(){
	int n, no;
	struct tNode *root = NULL;

	printf("Enter the size of input: ");
	scanf("%d",&n);
	while(n--){
		printf("Enter the number ");
		scanf("%d",&no);
		root = insert(root, no);
	}

	in_order(root);
	return 0;
}
