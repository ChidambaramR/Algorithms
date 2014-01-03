Objective:
==========
	Create a stack where operations PUSH, POP, TOP, MIN are O(1)

Logic:
======
	The logic is to keep an auxillary stack ( 2 stacks ). Keep pushing all the elements in the stack 1. Initially push the 1st element in the stack 2 and then push into stack 2, only when the next element to be inserted is less than the top element of the stack. In this case, the minimum within the stack can be immediately obtained in O(1) time.
	
	Let us consider the example. Push elements in the order: 5,25,15,8,1,45,2
	Now the stack will grow as follows.
	Stack S1:	Stack S2:
	5		5
	25		1 <-- 1 is inserted after 1 is inserted in the 1st stack. Top of stack2
	15
	8
	1
	45
	2 <--Top of stack 1
	
	Now let us pop 3 elements from stack 1. 
	While popping, we check if the popped value is the min value in the auxillary stack. If so, then pop the element from the auxillary stack too. This way we can reach the second min too.
	Once 1 has been popped off the secondary stack, then the top of the second stack is pointing to 5 which is the min in the 1st stack.
