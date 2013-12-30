Objective:
==========
	Create a stack where operations PUSH, POP, TOP, MIN are O(1)

Logic:
======
	The logic is to keep an auxillary stack ( 2 stacks ). Keep pushing all the elements in the stack 1. Initially push the 1st element in the stack 2 and then push into stack 2, only when the next element to be inserted is less than the top element of the stack. In this case, the minimum within the stack can be immediately obtained in O(1) time.

