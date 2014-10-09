#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

/*
   void MoveNode(struct node **dst, struct node **src) {
      tmp = *src;
      *src = (*src)->next;
      tmp->next = *dst;
      *dst = temp;
   }
   */
void alt_split(struct node *source, struct node **aList, struct node **bList) {
  struct node *temp;
  while (source != NULL) {
    // MoveNode(aList, &source);
    temp = source;
    source = source->next;
    temp->next = *aList;
    *aList = temp;
    if(source != NULL) {
      // MoveNode(bList, &source);
      temp = source;
      source = source->next;
      temp->next = *bList;
      *bList = temp;
    }
  }
}

void put_in_front(struct node **head, int data) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->next = *head;
  temp->data = data;
  *head = temp;
}

void push(struct node **head, int data){
  struct node* crawl;
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  if(!temp)
    return;

  temp->data = data;
  temp->next = NULL;

  if (!(*head)) {
    *head = temp;
    return;
  }

  crawl = *head;
  while(crawl->next)
    crawl = crawl->next;

  crawl->next = temp;
  return;
}

struct node* merge(struct node *a, struct node *b) {
  if(a == NULL)
      return b;
  else if(b == NULL)
      return a;
  else {
      if(a->data <= b->data) {
          a->next = merge(a->next, b);
          return a;
      }
      else {
          b->next = merge(a, b->next);
          return b;
      }

  }
}

void display(struct node *head) {
  while(head) {
    if(head->next)
      printf("%d -> ", head->data);
    else
      printf("%d",head->data);
    head = head->next;
  }
}

int main() {
  struct node *root = NULL;
  struct node *newList = NULL;
  struct node *a = NULL, *b = NULL;
  int n, data;
  printf("Enter total number of nodes ");
  scanf("%d",&n);
  while(n--) {
    scanf("%d",&data);
    //push(&root, data);
    put_in_front(&root, data);
  }

  display(root);
  printf("\n\n");
  alt_split(root, &a, &b);
  display(a);
  printf("\n\n");
  display(b);
  printf("\n\n");
  newList = merge(a, b);
  display(newList);
  printf("\n\n");
  return 0;
}
