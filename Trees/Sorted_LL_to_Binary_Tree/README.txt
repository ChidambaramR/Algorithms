Objective:
==========
	Given a singly linked list, form a binary tree from it.

Logic:
======
	The nodes in the linked list has to be inserted into the binary tree. We can use a queue for this. To start with the Queue is empty.
Push the head node of the linked list into the queue. Remove the front pointer in the queue and make it the parent node. The next node and node after next is going to be the left child and the right child of this node. Push them in the queue and make them the left child and the right child of the parent respective. Next time, this element is popped from the queue and its left child and right child are added and pushed into the queue and this goes on till the list is empty.
	For example, consider the list 1->3->5->7-9->11->13->15.
	Q: Queue in the program, LLH: Linked list head
	1. Push the node 1 in the queue. Q: 1, LLH: 1
	Loop:
	-----
	2. Pop the 1st element from the queue. Q: NULL
	3. Create left and right child for node 1 from the linked list and push them in the queue. Q: 3,5, LLH: 7
	4. Make them left and right child for 1. ( Root: 1, Left: 3, Right: 5 )

	5. Pop the 1st element from the queue. Q: 5
	6. Create left and right child for node 3 from the linked list and push them in the queue. Q: 5,7,9, LLH: 11
	7. Make them left and right child for 3. ( Root: 3, Left: 7, Right: 9 )

	8. Pop the 1st element from the queue. Q: 7,9
	9. Create left and right child for node 5 from the linked list and push them in the queue. Q: 7,9,11,13, LLH: 15
	10. Make them left and right child for 5 ( Root: 5, Left: 11, Right: 13 )

	11. Pop the 1st element from the queue. Q: 9,11,13
	12. Create left node ( NO Right node as LL ends ) and push them in the queue. Q: 9,11,13,15, LLH: NULL
	13. Make them left child for 7 ( Root: 7, Left 15 )

	14. Other node's left and right child are NULL.
