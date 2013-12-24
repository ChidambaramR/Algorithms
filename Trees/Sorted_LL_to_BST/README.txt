Objective:
==========
	Given a sorted LL, convert into to a balanced BST.

Logic:
======
	LL: 1->2->3->4->5->6->7
	BST:  4
	     / \
	    2   6
	   / \ / \
	  1  3 5  7

	If we observe, the root node is the middle of the LL. Thus, we need to find the middle of the LL and make it the root. Now divide the list into two halves. Take the root of the left half (Node: 2) and make it the left child of the main root. Take the root of the right half (Node: 6) and make it the right child of the main root. Similarly do this recursively until the list ends.
	1) Get the Middle of the linked list and make it root.
	2) Recursively do same for left half and right half.
       		a) Get the middle of left half and make it left child of the root
          	   created in step 1.
       		b) Get the middle of right half and make it right child of the
          	   root created in step 1.
