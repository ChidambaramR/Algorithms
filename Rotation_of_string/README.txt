Objective:
==========
	To check if two strings are rotations of each other.

Logic:
======
	Take the two strings. Take another temp string. Concatentate the 1st string to the temp string so that the temp string contains the 1st string twice. Now check if the second string is a substring of the 1st string. If so, the strings are rotation of each other. Else they are not.

Program:
========
	strcat - concatenates two string.
	strstr - check if one string is substring of the other.
