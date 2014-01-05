Objective:
==========
	Find the least common ancestor, given a parent pointer to the node.

Logic:
======
	When a parent pointer is given, the logic is to simply find the intersection of the two nodes.
	1. Calculate the height of the node1 by traversing the parent pointer upto NULL.
	2. Calculate the height of the node2 by traversing the parent pointer upto NULL.
	3. When we have the two counts, get the difference of the count ( left - right ).
		If the difference is greater than 0, then it means the left node is deeper than the right
		node. 
		If the difference is less than 0, then it means that right node is deeper than the left
		node.
		Thus is difference is greater than 0, move the left node's pointer till the difference becomes 0.
		If the difference is lesser than 0, move the right node's pointer till the difference becomes 0.
		After this traversal, both the pointers will be in the same level.
		Now traverse both the pointers till they become equal. The point where they become equal is LCA.

Objective1:
===========
	Find the least common ancestor, when there is no parent pointer in a BST.

Logic:
======
	When there is no parent pointer, then we can solve this by traversal. From the root node, check if both the
	nodes N1 and N2 are less than the root. If so, LCA is on the left sub-tree of the root.
	If both nodes N1 and N2 are greater than the root, LCA is on the right sub-tree of the root.
	The point where the current node becomes less greater than N1 and less than N2, is the LCA of the nodes.		
 
