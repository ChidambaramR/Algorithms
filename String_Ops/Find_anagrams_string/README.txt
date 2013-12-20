Objective:
==========
	Given two strings, find if they are anagram or not.

Logic:
======
	Have a hash which counts the number of occurrences in both the strings. When a new character is encountered in string1, increment the count of the characters by 1. When another character is encountered in string2, then decrement the corresponding count value in string 2. At the end of the program, all the values in the count array should be 0. If so, two strings are anagrams of each other. Else, they are not. 

Program:
========
	Count array keeps track of the number of occurrences of characters in both the string.
	If the length of the strings are not equal, then it means they are not anagrams.
	If the length of the strings are equal, then increment the count by 1 for characters in the 1st string and decrement the count by 1 for the characters in the second string.
	If the count value is not 0, after parsing through the strings, then the strings are not anagrams. 
