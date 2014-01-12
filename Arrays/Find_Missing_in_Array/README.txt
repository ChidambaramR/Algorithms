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
	3. Since the numbers are sorted, we can exploit the binary search propery. The logic is simple.
		Consider the numbers 1,2,3,4,5,6,8,9.
		Initially low is 0, mid is 3, high is 7.
		Since the numbers appear consecutively, if all the numbers are present in a range, then
		the corresponding indices must also be consecutive. In the above example, since in the
		range 0 - 3, i.e 1 to 4 ( in the array ), no number is missing, the difference between the
		indices and the corresponding numbers should be same. 
		In case number 2 was missing, then the differences between the indices and the numbers will
		not be same. The difference in the numbers would be 5-1 = 4 and the difference in the indices
		will be 3. If this happens, we can conculde that the missing number is in the left range. 
		If this happens in the right hand side, then the missing number could be in the right hand side
		range. 
