Objective:
==========
	Given a string, reverse the words in the string and not the entire string.

Logic:
======
	If the string is "I love my country", the output should be "country my love I". The logic is to, reverse the words in the string 1st and then reverse the entire string.
	1. After the 1st pass, the string will be "I evol ym yrtnuoc"
	2. Now reverse the entire string. So after the 2nd pass, "country my love I"

Program:
========
	Pass 1:
	start and end - Pointers to the string.
	Keep incrementing the end pointer till the end. Whenever we encounter a ' ' we reverse the word whose starting is pointed to by start.
	Eg, in the sentence "Hello world", when end comes to ' ', start will be 'H' and end-1 will be 'o'. Now we reverse this word. The string 		becomes "olleH world" and now, start is made to point to 'end+1'. i.e start of the next word since end is pointing ' '. Thus
		start is pointing to 'w' and end is pointing to ' '. This continues till end reaces '\0'. Now start is 'w' and end-1 is 'd'.
		After reversing, the string becomes "olleH dlrow".

	Pass 2:
	Pass 2 is trivial and this is just reversing the string.
	Thus the output is "world Hello"
