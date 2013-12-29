#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
/*
Structure of an AVL TREE
*/
struct node{
  int data;
  struct node *left;
  struct node *right;
  int height;
};

int max(int a, int b){
  return ((a > b)?a:b);
}

struct node* FindMin(struct node *root){
	struct node *current = root;
	while(current->left)
		current = current->left;
	return current;
}
/*
Here we dont use a recurisve call to find the height.
This is because we already have the height of a node stored
in the structure of the node.
*/
int height(struct node *root){
  if(root == NULL)
    return 0;

  return root->height;
}


/*
Function which returns the balance factor for a node.
It gets the height of the left sub tree. It gets the height
of the right sub tree. It returns the difference.
*/
bool getBalance(struct node* root){
  if(root == NULL)
    return 0;

  int lh = height(root->left);
  int rh = height(root->right);

  return lh-rh;  
}

/*
  RIGHT ROTATE
  ============

  Input Tree:
  -----------
          z
         / \
        y  T1
       / \
      x  T2
     / \
    T3 T4

  Rotation:
  ---------
  left = y
  right = T1
  root = z

  root->left = left->right
    i.e z->left = y->right ( z->left = T2 )
  
  left->right = root
    i.e y->right = root ( y->right = z )

  Output Tree:
  ------------
          y
         / \
        x   z
       / \ / \
      T3 T4T2 T1
*/

struct node* right_rotate(struct node *root){
  struct node *left = root->left;
  struct node *right = root->right;

  // Do the rotations
  root->left = left->right;
  left->right = root;

  // Update the pointers
  root->height = max(height(root->left), height(root->right))+1;
  left->height = max(height(left->left), height(left->right))+1;

  // Return new root y(root->left)
  return left;
}

/*
  LEFT ROTATE
  ===========

  Input Tree:
  -----------
            z
           / \
          T1  y
             / \
            T2  x
               / \
              T3  T4

  Rotation:
  ---------
  Root = z
  Left = T1
  Right = y 

  Root->right = right->left
    i.e z->right = y->left ( z->right = T2 )
  
  Right->left = root
    i.e y->left = root ( y->left = z ) 
  
  
  Output Tree:
  ------------
            y          
           / \
          z   x
         / \ / \
       T1 T2 T3 T4 

*/

struct node* left_rotate(struct node* root){
  struct node *left = root->left;
  struct node *right = root->right;

  root->right = right->left;
  right->left = root;

  root->height = max(height(root->left), height(root->right))+1;
  right->height = max(height(right->left), height(right->right))+1;
  
  return right; 
}


/*
This function does the insert. 
Till the updation of height of the paretn / root node, everything is same.
Now after finishing this, root will be pointing to the parent of its left and right child.
Now we find the nalance of this node. 
If balance > 1 and data < root->left->data
  This is the left left case. So we need to do a right rotation and change the root

If balance > 1 and data > root->left->Data
  This is Left right case.
  Do a left rotation 1st. This changes the root->left pointer.
  Do a right rotatio next.
*/
struct node* insert(struct node *root, int data){
  if(root == NULL){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
  }

  if(data < root->data)
    root->left = insert(root->left, data);
  else
    root->right = insert(root->right, data);

  // Update the height of the root
  root->height = max(height(root->left), height(root->right)) + 1;

  int balance = getBalance(root);

  // left left case
  if((balance > 1) && (data < root->left->data))
    return right_rotate(root);

  // Right Right case
  if((balance < -1) && (data > root->right->data))
    return left_rotate(root);

  //Left Right case
  if((balance > 1) && (data > root->left->data)){
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }

  //Right Left case
  if((balance < -1) && (data < root->right->data)){
    root->right = right_rotate(root->right);
    return left_rotate(root);
  }

  return root;
}

void print(struct node* root){
  if(root == NULL)
    return;
  
  print(root->left);
  printf("%d ",root->data);
  print(root->right);
}

struct node* delete(struct node *root, int key){
  struct node *temp;  

  if(root == NULL)
    return 0;

  if(key < root->data)
    root->left = delete(root->left, key);

  else if(key > root->data)
    root->right = delete(root->right, key);

  else{
  // We have found the data
  // This is normal BST delete. 
    if(root->right && root->left){
      // The node to be deleted has two children
      temp = FindMin(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
    else{
      // The node to be deleted has one child
      temp = NULL;
      temp = (root->left ? root->left : root->right);
      if(temp == NULL){
        // The node to be deleted has no chilren
        temp = root;
        root = NULL;
      }
      else{
        /*
        We are overwriting the node to be deleted with the contents of its
        children. If we delete this node, then changes has to be made to parent 
        node also. Since we dont have a parent pointer, that is not possible.
        So we copy the contents of the child to this node and delete that node instead.
        This is simple as we dont need to make any pointer modifications.
	Eg:
			7
		       / \
                      4   8
                     / \
                    3   5
                         \
			  6

	Here, instead of deleting the node, we copy the contents of node 6 to node 5. So
	after the 1st pass, the tree becomes,
			7
		       / \
                      4   8
                     / \
                    3   6 <== The node has been copied.
                         \
			  6

	Now we actually delete the 6 in the bottom. So the tree becomes

			7
		       / \
                      4   8
                     / \
                    3   6
        */
        *root = *temp;
      }
      free(temp);
    }
  }
  

  /*
  If root is NULL, there is no point in checking for balance factor
  in the trees. So we return here. Elese we proceed forward.
  */
  if(root == NULL)
    return root;

  root->height = max(height(root->left), height(root->right)) + 1;

  int balance = getBalance(root);

  /*
  Left Left case
  --------------
  We are using getBalance(root->left) and not checking if key < root->left->data
  as in the insert case because, while in insert, we knew the value of key which was
  inserted. But in the case of delete, we are removing the node with that key. So
  we cant check with the old key value as it will not be in the tree any more.
  */
  if(balance > 1 && (getBalance(root->left) >= 0))
    return right_rotate(root);

  // Left right case
  if(balance > 1 && (getBalance(root->left) < 0)){
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }

  // Right Right case
  if(balance < -1 && (getBalance(root->right) <=0 ))
    return left_rotate(root);

  if(balance < -1 && (getBalance(root->right)) > 0){
    root->right = right_rotate(root);
    return left_rotate(root);
  }

  /*
  If no balancing was needed and the node that was deleted was the one which had atleast one child,
  then return the root.
  */
  return root;
}

int main(){
  int n, no;
  struct node *root;

  printf("Enter the size of input: ");
  scanf("%d",&n);
  while(n--){
    printf("Enter the number: ");
    scanf("%d",&no);
    root = insert(root, no);
  }
  
  printf("\nIn order traversal of the tree: ");
  print(root);
  printf("\n");

  /*
  We need to update the root pointer. Since we are just passing the pointer value of
  root, and the root itself can be changed in the deletion, we must receive the value of
  new root.
  */
  root = delete(root, 10);
  printf("\nIn order traversal of the tree: ");
  print(root);
  printf("\n");

  return 0;
}
