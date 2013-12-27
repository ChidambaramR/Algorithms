#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99

typedef enum { false, true } bool;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct stack_t{
  struct node* stack[MAX];
  int top;
};

struct node* queue[MAX];
int front, rear;

void q_push(struct node* data){
  if(rear >= MAX){
    printf("Queue if FULL\n");
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
  return queue[front - 1];
}

void s_push(struct stack_t* s, struct node *root){
  if((s->top + 1) >= MAX){
    printf("Stack is FULL\n");
    return;
  }

  s->stack[s->top++] = root;
}

struct node* s_pop(struct stack_t *s){
  if(s->top < 0){
    printf("Stack is EMPTY\n");
    return;
  }
  
  return s->stack[--s->top];
}

bool s_empty(struct stack_t *s){
  if(s->top <= 0)
    return true;
  else
    return false;
}

void init_stack(struct stack_t *s){
  memset(s->stack, 0, MAX*sizeof(struct node));
  s->top = 0;
}

struct node* new_binaryNode(int data){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->left = temp->right = NULL;
  temp->data = data;
  return temp;
}


void convert_binaryTree(int *a, int len, struct node **root){
  int i=0;

  if(len == 0){
    *root = NULL;
    return;
  }

  *root = new_binaryNode(a[0]);
  q_push(*root);
  i++;

  while(i < len){
    struct node *parent = q_pop();
    struct node *left_child = NULL;
    struct node *right_child = NULL;

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

/*
Main logic is to use two stacks. One stack for traversing in one
direction. Other stack for traversing in the opposite direction.
When we are at the root, push it to stack S1.
Now run a while loop ill both the stacks are empty.
If one of the stack is not empty means, some node has yet to be printed.
While stack S1 is not empty, push all the children of nodes in stack S1
into stack S2 with right being pushed first and then left. In this case
it is printed from Left - Right.
Now, while stack S2 is not empty, push all the children of it in stack S1
with left being pushed first and right being pushed second. Thus when
taking our of the stack, the right node comes 1st and hence it prints in the
Right - Left direction.
*/
void print_zigzag(struct node* root){
    if(root == NULL)
      return;
  
    struct stack_t s1, s2;
    init_stack(&s1);
    init_stack(&s2);
    // Push the 1st level to stack 1
    s_push(&s1, root);

    // Print while any of the stack has some nodes
    while( (!s_empty(&s1)) || (!s_empty(&s2))){
      // Print nodes of current lebel from s1 and push next level nodes to s2      
      while((!s_empty(&s1))){
        struct node *temp;
        temp = s_pop(&s1);
        printf("%d ",temp->data);
        
        // Push right before left
        if(temp->right)
          s_push(&s2, temp->right);
        if(temp->left)
          s_push(&s2, temp->left);
      }

      // Push left before right
      while((!s_empty(&s2))){
        struct node *temp;
        temp = s_pop(&s2);
        printf("%d ",temp->data);

        if(temp->left)
          s_push(&s1, temp->left);
        if(temp->right)
          s_push(&s1, temp->right);
      }
    }

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
  print_zigzag(root);
  return 0;
}
