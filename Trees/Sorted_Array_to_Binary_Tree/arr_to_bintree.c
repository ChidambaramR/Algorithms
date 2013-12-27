#include <stdio.h>
#include <stdlib.h>
#define MAX 99

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* queue[MAX];
int front, rear;

struct node* new_binaryNode(int data){
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void q_push(struct node* data){
  if(rear >= MAX){
    printf("Queue is FULL\n");
    return;
  }

  queue[rear] = data;
  rear++;
}

struct node* q_pop(){
  if(front == rear){
    printf("Queue is empty\n");
    return;
  }

  front++;
  return queue[front - 1];
}


void convert_binaryTree(int *a, int len, struct node **root){
  int i=0;

  if(len == 0){
    *root = NULL;
    return;
  }

  *root = new_binaryNode(a[0]);
  q_push(*root);
  i = 1;

  while(i < len){
    struct node *parent = q_pop();
    struct node* left_child = NULL;
    struct node* right_child = NULL;

    left_child = new_binaryNode(a[i++]);
    q_push(left_child);
    if(i < len){
      right_child = new_binaryNode(a[i++]);
      q_push(right_child);
    }

    parent->left = left_child;
    parent->right = right_child;
  }
  return;
}

void print(struct node *root){
  if(root == NULL)
    return;

  print(root->left);
  printf("%d ", root->data);
  print(root->right);
}

int main(){
  struct node *root;
  int n, no, n1;
  int i=0;
  int a[MAX];

  printf("Enter the size of input: ");
  scanf("%d",&n);
  n1 = n;
  while(n--){
    printf("Enter the number ");
    scanf("%d",&a[i++]);
  }

  convert_binaryTree(a, n1, &root);
  print(root);
  return 0;
}
