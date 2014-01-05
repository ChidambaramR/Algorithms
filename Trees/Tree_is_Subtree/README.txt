Objective:
==========
	Given two trees, find is one tree is the sub-tree of the other.

Logic:
======
	The logic is to find if a tree formed from each node of the main tree1 is identical to the second tree.

	Let Tree1 be 
		5
	       / \
	      2   7
	     / \ / \
	    1  4 6  9
	
	Let Tree2 be
		7
	       / \
	      6   9

	We start from root node of Tree1. We check if the entire Tree1 rooted at 5 is identical to the Tree2. 
	The is_identical method returns false. Then we check the entire Tree1 rooted at its left-subtree (2)
	and the entire Tree1 rooted at its right sub-tree (7) are identical to the second tree Tree2. In this case
	is_identical for the right subtree matches with the second tree. Hence the function is_subtree returns
	true.
