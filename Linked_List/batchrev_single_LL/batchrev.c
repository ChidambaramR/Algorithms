#include<stdio.h>
#include <stdlib.h>

struct node{
	struct node *next;
	int data;
};

#ifdef SPECIAL_INSERT

int insert_head(struct node **head, struct node **tail, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return -1;

	temp->data = data;
	if(!(*head)){
		// 1st node
		*head = *tail = temp;
		temp->next = NULL;
		return 0;
	}

	// We already have some valid LL
	temp->next = *head;
	*head = temp;
	return 0;
}

int insert_tail(struct node **tail, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return -1;

	(*tail)->next = temp;
	temp->data = data;
	temp->next = NULL;
	(*tail) = temp;
	return 1;
}

int insert_mid(struct node *crawl, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return -1;

	temp->data = data;
	temp->next = crawl->next;
	crawl->next = temp;
	return 1;
}

int insert(struct node **head, struct node **tail, int data){
	
	struct node *crawl = *head;
	if(!(*head) || data <= (*head)->data)
		return insert_head(head, tail, data);
	else if(data > (*tail)->data)
		return insert_tail(tail, data);
	else{
		while(crawl->next && (crawl->next->data < data))
			crawl = crawl->next;
		return insert_mid(crawl, data);
	}
}

#endif

#ifdef NORMAL_INSERT

int push(struct node **head, int data){
	struct node *temp;
	struct node *crawl;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return -1;
	temp->data = data;
	temp->next = NULL;

	if(!(*head)){
		*head = temp;
		temp->next = NULL;
		return 0;
	}

	crawl = *head;
	while(crawl->next)
		crawl = crawl->next;
	crawl->next = temp;

	
}

#endif

struct node* reverse(struct node *head, int k, int length){
        struct node *current = head;
	struct node *next = NULL, *prev = NULL;
        int tc = k;
	static int count = 0;

        if(length - count <= k){
          return head;
        }

        // Reverse small subsets of the linked list
	while(current != NULL && tc--){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

        /*
         * Lets assume the linked list is 1->2->3->4->5->6->7. Let count = 3
         * Initial function call
         * When the first 3 nodes are reversed, it will be NULL<-1<-2<-3 4->5->6->7
         *  Head will be 1, next will be 4, current or prev will be 3.
         * Recursive call 1
         *  When the second recurive call runs, the LL will be
            NULL<-1<-2<-3 NULL<-4<-5<-6 7
            Its head is 4, next = 7, PREV=6
          Recursice call 2
            The count condition is hit and 7 is returned.
          Tail of rec call 1
            The LL becomes 7<-4<-5<-6 (because, head->next = reverse(..) and head was 4, 7 was returned.
            It returns 6 (check the capitals in rec call 1)
          Tail of original function call
            The LL becomes 7<-4<-5<-6<-1<-2<-3
            3 is returned to main. Thus head becomes 3.
          Thus the LL is 7<-4<-5<-6<-1<-2<-3
            or
            3->2->1->6->5->4->7
         */
        head->next = reverse(next, k, length);
        return prev;
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
	struct node *head, *tail;
	int n, temp, data;
	printf("Enter the total number of nodes");
	scanf("%d",&n);
	temp = n;
	head = tail = NULL;
	while(n--){
		printf("Enter node %d", temp-n);
		scanf("%d",&data);
#ifdef SPECIAL_INSERT
		insert(&head, &tail, data);
#endif
#ifdef NORMAL_INSERT
		push(&head, data);
#endif
	}
	print(head);
	head = reverse(head, 3, temp);
	print(head);
	return 0;
}
