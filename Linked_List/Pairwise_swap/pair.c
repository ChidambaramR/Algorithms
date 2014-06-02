#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

/*
 * Recursively swap two two nodes.
 * Let the list be 1->2->3->4->5
 * Initiall call
 *  Head is 1, current is 2, temp is 3
 *  current->next = head, makes 2's next to be 1.
 *  Now 1's next should be 4. The next is set by the return of the next recurisve call
 *  List is 1<-2 3->4->5
 *  current is 2 and head is 1
 * Rec call 1
 *  Swap is made as above and list is
 *  1<-2 3<-4
 *  current is 4 and head is 3
 * Rec call 2
 *  5's next is NULL. so 5 is returned
 * Tail call 1
 *  head (3)->next is 5. 4 is returned. The list is
 *  5<-3<-4 or 4->3->5
 * Tail initial call
 *  5<-3<-4<-1<-2 or 2->1->4->3->5 (since 4 is returned)
 *  Now 2 ( current ) is returned as the new head. Voila!
 */
struct node* pair(struct node *head){
    struct node *temp;
    struct node *current;
    struct node *prev = head;

    if(!head)
        return NULL;

    if(!head->next)
        return head;

    current = head->next;
    temp = current->next;
    current->next = head;
    head->next = pair(temp);
    return current;

}

void push(struct node **head, int data){
    struct node *temp;
    struct node *crawl;

    temp = (struct node*)malloc(sizeof(struct node));
    if(!temp)
        return;
    temp->data = data;
    temp->next = NULL;

    if(!(*head)){
        *head = temp;
        return;
    }

    crawl = *head;
    while(crawl->next)
        crawl = crawl->next;
    crawl->next = temp;
    return;
}

void print(struct node *head){
    while(head){
        if(head->next)
            printf("%d -> ",head->data);
        else
            printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
  struct node *head = NULL;
  int n, data;
  printf("Enter the total number of nodes: ");
  scanf("%d",&n);
  while(n--){
      printf("Enter value for node: ");
      scanf("%d",&data);
      push(&head, data);
  }
  print(head);
  head = pair(head);
  print(head);
  return 0;
}
