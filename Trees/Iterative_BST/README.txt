Objective:
==========
	To perform BST operations in an interative manner.

Logic:
======
	To simulate recursion we will be using a stack here. 
	Let us consider the following tree.
			5
		       / \
		      3   7
		     / \   \
		    2   4   9

	INORDER TRAVERSAL:
	------------------
	1) Create an empty stack S.
	2) Initialize current node as root
	3) Push the current node to S and set current = current->left until current is NULL
	4) If current is NULL and stack is not empty then 
     		a) Pop the top item from stack.
     		b) Print the popped item, set current = current->right 
     		c) Go to step 3.
	5) If current is NULL and stack is empty then we are done.

	The inorder traversal of this tree is: 2 3 4 5 7 9
	The program consists of a while 1 loop. When the current node is not NULL, it pushes into the stack.
	1. Node 5: push(5) , Goto Left
	2. Node 3: push(3) , Goto Left
	3. Node 2: push(2) , Goto Left || Stack: (top)2 -> 3 -> 5
	4. Node NULL: pop(2), print (2) , Goto Right || Stack (top)3 -> 5
	5. Node NULL: pop(3), print (3) , Goto Right || Stack (top)5
	6. Node 4: push(4) , Goto Left || Stack (top)4 -> 5
	7. Node NULL: pop(4), print(4) , Goto Right || Stack (top)5
	8. Node NULL: pop(5), print(5) , Goto Right || Stack Empty
	9. Node 7: push(7), Goto Left || Stack (top)7
	10. Node NULL: pop(7), print(7), Goto Right || Stack Empty
	11. Node 9: push(9) , Goto Left || Stack (top)9
	12. Node NULL: pop(9), print(9), Goto Right || Stack Empty
	13. Node NULL and Stack is NULL so break

