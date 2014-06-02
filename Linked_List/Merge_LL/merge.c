#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};


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

// Iterative merge
void merge(struct node* head1, struct node *head2){
    struct node *lhead1, *lhead2;
    while(1){
        if(head1->next == NULL){
            head1->next = head2;
            return;
        }
        else if(head2 == NULL)
            return;
        else{
        lhead1 = head1->next;
        lhead2 = head2->next;
        head2->next = head1->next;
        head1->next = head2;
        head1 = lhead1;
        head2 = lhead2;
        }
    }
}

// Recursive merge
struct node* rec_merge(struct node *a, struct node *b){
    struct node *t_a, *t_b;
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    else{
        /*
         * We need temporary storage because, after assigning
         * a->next = b, we will loose the old value of a->next
         * for sending in the recurisve call.
         */
        t_a = a->next;
        t_b = b->next;
        a->next = b;
        b->next = rec_merge(t_a, t_b);
        return a;
    }
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
  struct node *head = NULL, *head1 = NULL;
  int n, data;
  // LL 1
  printf("Enter the total number of nodes for LL1: ");
  scanf("%d",&n);
  while(n--){
      printf("Enter value for node: ");
      scanf("%d",&data);
      push(&head, data);
  }

  // LL 2
  printf("Enter the total number of nodes for LL2: ");
  scanf("%d",&n);
  while(n--){
      printf("Enter value for node: ");
      scanf("%d",&data);
      push(&head1, data);
  }
  print(head);
  //head = rec_merge(head, head1);
  merge(head, head1);
  print(head);
  return 0;
}
