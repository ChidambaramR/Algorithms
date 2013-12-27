#include <stdio.h>
#include <stdlib.h>
#define MAX 99

typedef enum { false, true } bool;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node_LL{
  int data;
  struct node_LL *next;
};

struct node* queue[100];
int front, rear;

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
    printf("Queue is EMPTY\n");
    return;
  }
  
  front++;
  return queue[front-1];
}

void push(struct node_LL *head, int data){
  struct node_LL *crawl, *temp;
  crawl = head;
  temp = (struct node_LL*)malloc(sizeof(struct node_LL));
  temp->data = data;
  temp->next = NULL;
    
  while(crawl->next)
    crawl = crawl->next;

  crawl->next = temp;
  return;
}

struct node* new_binaryNode(int data){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->left = temp->right = NULL;
  temp->data = data;
  return temp;
}

void convert_list2Binary(struct node_LL *head, struct node **root){
  if(head == NULL){
    root = NULL;
    return;
  }

  /*
  First node is always the root node. So add it to the queue.
  */
  *root = new_binaryNode(head->data);
  q_push(*root);

  // Go to the next node
  head = head->next;

  while(head){
    /*
    Take the parent node from the Q and remove it.
    */
    struct node* parent = q_pop();
    
    /*
    Take the next two nodes from the LL. We add them as children 
    to the current parent node. Push them in the Q so that they
    will be the parent for the future nodes.
    */
    struct node* left_child = NULL;
    struct node* right_child = NULL;
    left_child = new_binaryNode(head->data);
    q_push(left_child);
    head = head->next;
    if(head){
      right_child = new_binaryNode(head->data);
      q_push(right_child);
      head = head->next;
    }
  
    parent->left = left_child;
    parent->right = right_child;

  }
}

void print(struct node* root){
  if(root == NULL)
    return;
  
  print(root->left);
  printf("%d ",root->data);
  print(root->right);
  return;
}

int main(){
  struct node *root;
  struct node_LL *head;
  int n, no;
  head = (struct node_LL*)malloc(sizeof(struct node_LL));
  printf("Enter the size of input: ");
  scanf("%d",&n);
  while(n--){
    printf("Enter the number ");
    scanf("%d",&no);
    push(head, no);
  }
  convert_list2Binary(head->next, &root);
  print(root);
  printf("\n");
  return 0;
}
