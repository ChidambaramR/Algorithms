Objective:
==========
	Give a binary tree / BST, find the maximum value of sum from root to leaf.

Logic:
======
	We recurse down to the leaf. The idea is to find the sum from the left child to its leaf, and the sum from the right child to its leaf.
	Return the max of it. Consider the tree.

		7
	       / \
	      4   8
             / \
            3   5
                 \
		  6

	In this tree, we first go to node 3. Node 3 returns sum 3 to node 4. Node 4 recursively calls for its right subtree. So Node 6 returns
	6 to node 5. Node 5 add its own value to this sum and returns 11 to node 4. Now node 4's left child's sum is 3 and right child's sum is
	11. It compares and finds that sum 11 is bigger and it adds its value to this and returns the sum as 15 to node 7. For node 7, left
	child's sum is 15 and right child's sum is 8. It takes the bigger of two (15) and add its own value and returns the final result as
	22 
