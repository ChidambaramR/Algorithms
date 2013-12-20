Objective:
==========
	Given a singly LL, reverse it.

Logic:
======
	Recursive:
	----------
	We maintain two pointers. 'first' and 'rest'. i.e We split the LL into two parts. One pointed to by 'first' and the other pointer to by 'rest'. 'rest' pointer is the next pointer to the 'first'. Until 'rest' becomes NULL, we keep recurisvely calling. Once 'rest' is NULL, i.e we are in the last node, we store the address of this node, in a global variable which denotes the head of the new list. We then modify the pointers such that the LL is reversed.

	Iterative:
	----------
	We again maintain two pointers here. 'prev' and 'temp'. The 'prev' pointer is used to keep track of the previous node visited. This is because, we have to change a node's next pointer to the previous node. The 'temp' pointer is used to keep track of the next node. This is because we are changing a node's next pointer to the previous node in the LL. So node->next will be pointing to the previous node and we cant use node = node->next. Thus we store node->next in a variable called 'temp' and keep track of the next node with this.

Program:
========
	The two important lines are 
	1. first->next->next = first
		At this place, 'first' is the last but one node. Thus first->next->next will be NULL. We are overwriting this pointer to be the value of 'first' pointer. i.e Consider the case 1->2->3->4. When the 1st time this line executes, 'first' is pointing to 3, 'rest' is pointing to 4. Thus first->next->next references the 'next' value of node 4. Thus is set to node 3 through first->next->next = first. Now the list is like this 1->2->3<--4. But still node 3 is pointing to node 4. We have to change this. So we do the next line.
	2. first->next = NULL
		After execution of this step, the LL becomes as follows. 1->2->3-->NULL
									       ^
									       |
									       4

	This goes on. After the second time those statements execute, the LL becomes 1->2-->NULL
											^
											|
											3 <-- 4 
