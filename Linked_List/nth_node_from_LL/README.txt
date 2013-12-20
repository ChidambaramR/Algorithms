Objective:
==========
	Given a singly linked list, find the nth node from the last.

Logic:
======
	Iterative Logic:
	----------------
	The idea is to have to two pointers. Move the 1st pointer till a count of 'n' from the starting. When it has counted till 'n', increment the second pointer and the first pointer, till the first pointer reaches the end. The place at which the second pointer stands is the 'n'th node from the last.
	Recursive Logic:
	----------------
	We recurse till the end of the list. When the end of the list is reached, return NULL. Now when backtracking, reduce the count by 1. If count becomes 0, then return the pointer to that node. When returning back, if the pointer to the 'n'th node from the last is found, keep returning that pointer else return NULL.


Program:
========
	main_p and ref are the two pointers. 'ref' is incremented till a count of 'n' is reached. Now till ref->next reaches end, main_p is incremented. When ref->next reaches NULL, the place at which the main_p stays is the 'n'th node from the last.
	rec_find_nth:
	-------------
		if(ref != NULL)
			return ref;
		This if loop checks if the reference pointer has been found. If found, then return this pointer to the previous function. In each recursive call, ref = rec_find_nth() will be returning the pointer to the 'n'th node from the last once this node has been found. Else we return NULL.
		We also first decrement the counter and then make the check. Since the counter is being checked with 0, this has to be done. 
