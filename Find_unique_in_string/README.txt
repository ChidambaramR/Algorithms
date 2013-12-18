Objective:
==========
	Given a string, find whether it contains unique characters or not.

Logic:
======
	There are several approaches to do this.
	1. Quadriatic time: O(n^2):
	---------------------------
		Just iterate through the string. Take a character and compare with all other characters. If some combination is equal, then we can determine that the string contains duplicate characters.
		As an optimization we can reduce the number of characters being compared. For the inner 'j' loop, check from the place where the 'i' loop begins. For eg, "ABCD", in this string, in a naive way, we check A with B,C,D, then in the second loop, check B with A,C,D. We are having redundant comparisons. Thus, for A, we can check B,C,D. For B, we can check C,D and for C, we can check with D.
	2. Linear time, O(n) space:
	---------------------------
		Construct a hash table. Update true if a particular character is found. Next time, check for this true value.
	3. Linear time, O(n logn) space:
	--------------------------------
		Use any inplace sorting algorithm and then iterate through the string comparing the next character.
	4. Linear time, O(1) space:
	---------------------------
		Have a bit mask for each character. If only alphabets are given, a 32 bit integer will suffice. 

Progam:
=======
	There is a 32 bit mask. The program works only with 'lower case' alphabets. 
	As and when a character is found, the mask is updated. Next time, a bit arithmetic is performed to see if the mask contains this value. If the mask contains a true value, then duplicate is found. Essentially same as a hash map. This uses bit map.
