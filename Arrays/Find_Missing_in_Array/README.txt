Objective:
==========
	Given a set of consecutive integers from 1 to n, find the missing number in it.

Logic:
======
	The logic works for only one missing number. If more than one numbers are missing it wont work.
	1. Use XOR. XOR'ng a number two times to a number x wont make any difference to x. 
		So XOR all the elements of the array. Then XOR this result with all numbers from 1 to n.
		The remaining value is the missing number.
	2. Find the sum of numbers from 1 to n. Subtract the array elements. The remaining value is the
		missing number.
