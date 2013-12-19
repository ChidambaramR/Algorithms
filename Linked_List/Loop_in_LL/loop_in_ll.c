#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void push(struct node *head, int data){
  struct node *temp, *crawl;
  crawl = head;
  // Create a temporary node
  temp = (struct node*)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->data = data;

  // Loop till the last node
  while(crawl->next)
    crawl = crawl->next;

  // Last node's next is newly created node as it is appending
  crawl->next = temp;
}

void detectLoop(struct node *head){
  struct node *slow, *fast;
  slow = fast = head->next;
  int found = 0;
  while( slow && fast && fast->next ){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      printf("Loop is detected!! at node %p %d\n",slow,slow->data);
      found = 1;
      break;
    }
  }
  if(!found)
    printf("No Loop\n");
}


void print(struct node*head){
  struct node* crawl = head->next;
  int i=1;
  while(crawl){
    printf("Node %d: %d\n",i++,crawl->data);
    crawl = crawl->next;
  }
}

int main(){
  int n,data;
  int i=1;
  struct node* head;
  head = (struct node*)malloc(sizeof(struct node));
  head->next = NULL;
  printf("enter the number of nodes");
  scanf("%d",&n);
  while(n--){
  printf("Enter node %d",i++);
  scanf("%d",&data);
  push(head, data);
  }
  print(head);
  detectLoop(head);
  printf("\n");
  head->next->next = head->next;
  printf("\n");
  detectLoop(head);
  return 0;
}
