Objective:
==========
	Given a string, print it after removing the duplicates.

Logic:
======
	To do it in place, we can use a hash table. Have two pointers. One which counts over the input string and other which counts over the resultant string. Both input and resultant strings are same. We just have two different pointers. Whenever we encounter a character in the input sting, increment its hash table location by 1. Now check if the hash table value for the current character is equal to 1. If there was already a character, then the hash value will contain a value greater than 1. So when the hash value is 1, it means that the character is so far unique. Thus we store this is character in the place pointed to by the second pointer and we advance both the pointers. We do this till we reach the end.
	Example: Let us consider the string "aaaboolean". Pointer 1 and Pointer 2 will be pointing to the second 'a'. Now we see that hash value is greater than 1. This means that 'a' is already present in the string. So we advance Pointer 1. Now we encounter 'b'. Hash value for 'b' is 1. Thus 'b' is appearing for the 1st time. Thus we store this value at Pointer 2 and increment both the pointers. The string now becomes "ababoolean". We do this till the end. Once Pointer 1 has come to the end, we store '\0' values from the Pointer 2 to the end and print it.

Program:
========
	res_ind is a pointer pointing to the 1st position of the string.
	ip_ind is a pointer pointing to the 1st position of the string and keeps incrementing for each loop.
	If a character is found to be new, we store in the place pointed by res_ind and increment both the pointers.
	The entire operation is in place.
	
