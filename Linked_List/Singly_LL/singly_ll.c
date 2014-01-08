#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct node{
	struct node* next;
	int data;
} *tail = NULL;

int insert_begining(struct node **head, int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return 0;
	temp->data = data;
	/*
	If this is the 1st node in the LL
	*/
	if(!(*head)){
		temp->next = NULL;
		*head = temp;
		tail = *head;
		return 1;
	}

	temp->next = (*head);
	(*head) = temp;
	return 1;
		
}

int push(struct node **head, int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return 0;
	temp->data = data;
	temp->next = tail->next;

	/*
	Use the tail pointer which is pointing to the end.
	*/
	if(!tail){
		*head = temp;
		tail = temp;
		return 1;
	}

	tail->next = temp;
	tail = temp;
}


int delete(struct node **head, struct node* elem){
	struct node *crawl = *head;

	if(!elem)
		return 0;
	/*
	When the element to be deleted is the head node.
	*/
	if(elem == *head){
		(*head) = (*head)->next;
		free(elem);
		// If no more element in the linked list, tail and head are NULL
		if(!(*head))
			tail = NULL;
		return 1;
	}	

	/*
	Search for the element
	*/
	while((crawl->next) && (crawl->next != elem)){
		crawl = crawl->next;
	}	

	/*
	If the element is not found, then return 0
	*/
	if(crawl->next == NULL)
		return 0;

	/*
	Element has been found
	*/
	crawl->next = elem->next;
	free(elem);
	/*
	If the element to be deleted is the last element, the update
	the tail pointer to the last node.
	*/
	if(crawl->next == NULL)
		tail = crawl;
	return 1;
}

/*
Just a wrapper function which sends the pointer to the element be deleted
to the main delete function.
*/
int del_node(struct node *head, int data){
	struct node *crawl = head;
	struct node *temp;
	int ret=0;

	while(crawl){
		if(crawl->data == data){
			temp = crawl;
		}
		crawl = crawl->next;
	}
	return delete(&head, temp);
}


void display(struct node *head){
	printf("\n");
	while(head){
		if(!(head->next))
			printf("%d",head->data);
		else
			printf("%d -> ",head->data);
		head = head->next;
	}
	printf("\n");
}

/*
Returns the number of nodes in the Linked List
*/
int count(struct node *head){
	int count;
	while(head){
		count++;
		head = head->next;
	}
	return count;
}

/*
Returns the 'n'th node from the start of the linked list
*/
int nth_LL(struct node *head, int n){
	while(--n){
		head = head->next;
	}
	return head->data;
}

/*
Deletes a singly linked list. Gets a reference to the head pointer
because, we need to tell the caller about the change in the value of the head.
*/
void delete_full(struct node **head){
	struct node *cur = *head;
	struct node *temp;
	while(head){
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	tail = NULL;
	*head = NULL;
}

/*
Returns if a list is empty or not.
*/
bool is_empty(struct node *head){
	if(head == NULL)
		return true;
	else
		return false;
}

/*
Deletes the 1st element of the list and returns it data. It is just like a stack's POP operation.
*/
int pop(struct node **head){
	int data;
	struct node *temp = *head;
	data = temp->data;
	*head = (*head)->next;
	free(temp);
	if(*head == NULL)
		tail = NULL;
	return data;
}

/*
Insert into a linked list, after n positions. i.e If the user says insert into the LL after 3rd position
then a new node has to be inserted into the third position.
*/
void insert_nth(struct node **head, int pos, int data){
	struct node *crawl = *head;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	// Head case
	if(pos == 1){
		temp->next = *head;
		*head = temp;
	}
	else{
		while(--pos && crawl->next){
			crawl = crawl->next;
		}
		if(!crawl){
			/*
			Position greater than list length. So inserting at the end.
			*/
			push(head, data);
		}
		else{
			temp->next = crawl->next;
			crawl->next = temp;
		}
	}
}

/*
Inserts the list in sorted order. 
Case 1:
First checks if there is any head node. If there is no head node, then create a node
update the head and tail pointer.

Case 2:
If the node to be inserted is less than the head node, then insert it straight
away as the begining node.

Case 3:
If the node to be inserted is greater than the tail node, then insert it straight
away as the last node

Case 4:
The worst case, traverse the list and find the node which is lesser than the node to
be inserted.
*/
void sorted_insert(struct node **head, int data){
	struct node *crawl = *head;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;

	if(!(*head)){
		temp->next = NULL;
		*head = temp;
		tail = temp;
		return;
	}

	if(data <= (*head)->data){
		temp->next = *head;
		*head = temp;
	}
	else if(data >= tail->data){
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
	else{
		while(crawl->next && (data >= crawl->next->data)){
			crawl = crawl->next;
		}
		temp->next = crawl->next;
		crawl->next = temp;
		if(temp->next == NULL)
			tail = temp;
	}
}


/*
Given a Linked List, split it into two separate lists.
Use the traditional slow and fast pointer logic. Go to the middle of the linked
list. Then do the updations.
Handle separately for list length = 1 and length = 2
*/
void list_split(struct node *head, struct node **newRef){
	struct node *slow, *fast;

	/*
	Length = 1 case
	*/	
	if((head->next == NULL)){
		*newRef = NULL;	
	}
	/*
	Length = 2 case
	*/
	else if(head->next->next == NULL){
		*newRef = head->next;
		head->next = NULL;
	}
	/*
	For all other lengths
	*/
	else{
	slow = fast = head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	*newRef = slow->next;
	slow->next = NULL;
	}
}

void MoveNode(struct node **tail, struct node **list_node){
	(*tail) = (*list_node);
	(*list_node) = (*list_node)->next;
	(*tail)->next = NULL;
}


/*
We are creating a new list and put the contents of both the lists in this
new list in an alternating manner. i.e If the list a contains 1->2->5->6
and the ilst b contains 3->4, then the new list contains
1->2->3->4->5
dummy is a temporary node created in the stack which points to null.
Initially it will be dummy->NULL.
We are adding the elements at the end of the dummy node. So in the 1st case when we add
1 from list 1, the new list will be dummy->1->NULL
When we add all the elements, the list will contains dummy->1->2->3->4->5->6->NULL
We return dummy.next
*/
struct node* sorted_merge(struct node *a, struct node *b){
	struct node dummy={0,0};
	struct node *tail = &dummy;

	while(1){
		if(a == NULL){
			/*
			If one of the list runs out, then make the next pointer of the last node
			in the list to the next list.
			*/
			tail->next = b;
			break;
		}
		else if(b == NULL){
			/*
			If one of the list runs out, then make the next pointer of the last node
			in the list to the next list.
			*/
			tail->next = a;
			break;
		}
		else if(a->data <= b->data){
			MoveNode(&(tail->next), &a);
		}
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}

	return dummy.next;
}



/*
Shuffle Merge
Given two lists, merge them in an alternating fashion. 
*/

struct node* shuffleMerge(struct node *a, struct node *b){
	struct node dummy={0,0};
	struct node *tail = &dummy;

	while(1){
		if(a == NULL){
			/*
			If one list runs out, make the next pointer point to the
			other list.
			*/
			tail->next = b;
			break;
		}
		if(b == NULL){
			/*
			If one list runs out, make the next pointer point to the
			other list.
			*/
			tail->next = a;
			break;
		}
		else{
			tail->next = a;
			a = a->next;
			tail = tail->next;
			/*
			tail->next = NULL statement is redundant because, for the intermediate
			time tail->next will be NULL. Immediately, it is going to add b's pointer
			to tail->next. So we can leave tail->next to point to a's next node for a 
			while.
			i.e If the list is 1->3->5 and 2->4->6
			After the 1st step, the new list will be 1->3->5 and the initial 'A' list
			will be 3->5 due to a=a->next. Putting tail->next = NULL will make the new
			list 1->NULL. This is correct. But even if the new list was 1->3->5 when tail
			is pointing at 1, when b's pointer is added, the new list becomes as
			1->2->4->6. Had we enabled the tail->next = NULL, it would have been
			1->2->NULL
			*/
//			tail->next = NULL;

			tail->next = b;
			b = b->next;
			tail = tail->next;
//			tail->next = NULL;
		}
	}

	return dummy.next;
}


void reverse_LL(struct node **head){
	struct node *back = NULL;
	struct node *middle = *head;
	struct node *front;

	while(middle){
		front = middle->next;
		middle->next = back;
		back = middle;
		middle = front;
	}

	*head = back;
}

int main(){
	int n, data, i=0, dnode;
	struct node *head = NULL;
	struct node *newRef = NULL;
  	printf("Enter the number of nodes: ");
  	scanf("%d",&n);
  	while(n--){
  		printf("Enter node %d: ",i++);
  		scanf("%d",&data);
  		//insert_begining(&head, data);
		//push(&head, data);
		sorted_insert(&head, data);
  	}
	list_split(head, &newRef);
	display(head);
	
	/*printf("Enter the node you want to delete: ");
	scanf("%d",&dnode);
	if(!del_node(head, dnode))
		printf("Node to be deleted not found\n");
	*/
	display(newRef);
	head = shuffleMerge(head, newRef);
	display(head);
	reverse_LL(&head);
	display(head);
	return 0;
}
