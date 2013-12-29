Objective:
==========
	Given a binary tree, check if it is balanced or NOT.

Logic:
======
	A tree is balanced if, for any node,
	1. Left sub-tree is balanced
	2. Right sub-tree is balanced
	3. Abs difference between left and right subtree is not more than 1.

Program:
========
	The program starts with a root node. It calculates the height of the root's left subtree.
	It then calculates the height of the root's right subtree. 
	1. It checks if the absolute difference is less than or equal to 1.
	2. It then chekcs if the left subtree is balanced.
	3. It then checks if the right subtree is balanced.
	If all the three conditions are TURE, it returns TRUE. Else it returns FALSE.
