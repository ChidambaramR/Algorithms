Objective:
==========
	To program a general singly linked list.

Logic:
======
	There are two pointers being maintained. One is the head pointer and other is the tail pointer.
	When there is a tail pointer, insertion at the end can easily be done.
	----------------------------------------------------------------------
		Lets take an example. 1->2->3->4->NULL.
		The tail pointer will be at 4. Now we are inserting 5.
		1. temp->next = tail->next		1->2->3->4->NULL
							             ^
 							             |
							             5 ( temp )
		
		2. tail->next = temp                    1->2->3->4(tail)    NULL
								 |           ^
								 |           |
								  -->-->-->->5

		3. tail = temp                          1->2->3->4    NULL
								 |    ^
								 |    |
								  --> 5 ( tail )

	When there is a head pointer, then insertion becomes easy while inserting at front.
	------------------------------------------------------------------------------------
		Lets take an example. 1 <--head
		The head pointer is at 1. We now insert 2.
		1. temp->next = head.                (head) 1 <-- 2  or 2 --> (head) 1 ( two representations )
		2. head = temp                        1 <-- 2 (head) or (head) 2 --> 1 ( two representations )	

	When the head element is deleted:
	---------------------------------
		Lets take the example. (head)1->2->3->4->NULL
		1. temp = head	       (head / temp)1->2->3->4->NULL
		2. head = head->next   (temp)1->(head)2->3->4->NULL
		3. free(temp)	       (head)2->3->4->NULL

	When the tail element is deleted:
	---------------------------------
		Lets take the example. (head)1->2->3->4(tail)->NULL
		1. Traverse till one element before tail. 1->2->(temp)3->(tail)4->NULL
		2. temp->next = tail->next 	1->2->(temp)3->NULL
								^
								|
								4(tail)
		3. free(tail)			1->2->(temp)3->NULL
		4. tail = temp			1->2->(tail)3->NULL 
			
