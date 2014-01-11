Objective:
==========
	Implement the strcat function.

Logic:
======
	The strcat function concatenates two strings and returns the result.
	Two cases has to be taken care of. 
	1. The 1st string should have enough memory allocated. 
	2. Since the pointer to the original string should be modified, we should not change the pointer
		which we got as a parameter. So we keep a temporary pointer and do the operations with that
		pointer and return the original pointer.
