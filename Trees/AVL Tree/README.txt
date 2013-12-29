Objective:
==========
	Create an AVL tree and do basic operations on it.

Logic:
======
	Thought BST's are good for storing and searching, when a BST gets skewed, then the search operation
	can itself be O(n). So a self balancing BST ( known as AVL tree ) was invented. In an AVL tree, the
	heights of the two child subtrees of any node differ by at most one. If at anytime, the heights of
	the two subtrees differ by more than one, then a rotation operation is performed.
	
	Time Complexity:
	----------------
	Lookup, Insertion and  deletion all take O(log n) time in both average and worst cases. 
	The rotation operation in itself is a constant time operation since it involves just changing pointers.
