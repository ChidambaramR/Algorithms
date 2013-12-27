Objective:
==========
	Given a binary tree, make a spiral traversal. i.e the traversal should be zig-zag.

Logic:
======
	This program can be solved by using 2 stacks. Let us consider the following tree.
		1
	       / \
	      2   3
	     / \ / \	
	    4  5 6  7

	1. Push 1 to stack S1.
	2. While stack S1 or S2 is not empty, proceed with the loop
	3. Pop from Stack S1 until it is empty. Push its children onto the second stack. Push right 1st and then left. So while popping out, lef		t will come out and then right. This is left-right traversal.
	4. Pop from stack S2 until it is empty. Push its children onto the first stack. Push left 1st and then right. So while popping out, righ		t will come first and then left. This is right-left traversal.
	5. This forms a zig-zag traversal of a tree.
