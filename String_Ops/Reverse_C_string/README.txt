Objective:
=========
	Print the reverse of a string in place. 

Logic:
======
	This can be done easily using a recursion. Recurse till the end of the string. When a NULL character is found, just backtrack and print the string. This does not work with spaces.
	When the string has to be reversed, care has to be taken while reversing. In the normal approach, 
	rev(char *str){
		...
		str[j] = ..
	}
	This wont work as down the recursion str will be changed. So when the recursion is at last character, str[2] will be NULL.
	So this cant be done without a second array where we have to store the reversed string and return this pointer to the main function.
