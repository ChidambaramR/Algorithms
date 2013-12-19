Objective:
=========
	Given a Singly LL, find whether there is a loop or not

Logic:
======
	We will have two pointers. Slow pointer and the fast pointer. The slow pointer increments by 1. The fast pointer increments by 2. If the slow pointer and fast pointer meet before either of them becoming NULL, then a loop is found. If either of them become NULL before meeting then there is no loop in the Linked List.

Program:
========
	Slow and fast are the pointers. Both are initialized to starting node. 
	slow = slow -> next increments the slow pointer by 1.
	fast = fast -> next -> next increments the fast pointer by 2.
	the while loop checks for ( slow && fast && fast->next ). Here fast->next is checked because, it increments by 2. So in the legitimate case, the fast pointer will be pointing to NULL, one element from the last. Hence it might dereference a NULL pointer if only 'fast' is checked.
