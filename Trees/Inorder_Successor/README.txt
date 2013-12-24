Objective:
==========
	Given a BST, find the in-order successor a node.

Logic:
=======
	The user just gives the search key to find the in-order successor. Thus we have to first call a lookup function which will return the pointer to that node. Once this pointer is received, we call the function which finds the in-order successor. There are two cases.
	1. If the node has a right child:
		In this case, the left most child in the right child's subtree is the in-order successor.
		If there is no left child, for the node's right-child, then the right child is the in-order successor.
	2. If the node does NOT have a right child:
		In this case, we have to traverse up the tree. We have to find a node such that, it is the left child of its parent. Once such a child is found, its parent is the in-order successor for the node we are looking for.

Program:
========
	The case where there is a right-child is simple. 
	When there is no riht child, we have to go to a node which is the left child of its parent.

	current = root->parent; // Gets the parent of the current node

	while((current != NULL) && (root == current->right)) // Loop till or traverse the tree
				// till we find a node which is the left child of its parent.
