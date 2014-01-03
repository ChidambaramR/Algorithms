Objective:
==========
	Implement a normal stack as Linked List

Logic:
======
	Each entry of the stack is a node in the linked list. There are two pointers root and top. Top will always be pointing to the
	last node in the stack. Root will be pointing to the first node in the linked list. 
	Add operation is just O(1) since we already have a pointer to the last node and we dont want to traverse from the root of the
	node to the node one before the last.
	Similarly operation pop is O(1) due to the pointer to the last element.
