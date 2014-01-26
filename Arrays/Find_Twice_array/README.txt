Objective:
==========
	Given two lists, find the numbers that appear exactly twice if the two lists were merged.

Logic:
======
	Hash Table
	----------
	A simple, O(n) logic will be to use a hash table. During pass 1, increment the number's index in list 1.
	During the pass 2, increment the number's index in list 2.
	Now make a third pass through the hash table and print values equal to 2.

	No extra memory
	---------------
	In the case, sort the two lists. Have two pointers. Use the intersection of numbers in 2 arrays logic.
	If both the elements matches, then check if consecutive elements are same. Have a counter for it. If the 
	counter reads more than 2, then it means we will see the element for the 3rd time. So we have to ignore it.
