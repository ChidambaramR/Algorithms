Objective:
==========
	Understand a ternary search tree

Logic:
======
	1. Ternary search trees are efficient for queries like “Given a word, find the next word in 
	dictionary(near-neighbor lookups)” or “Find all telephone numbers starting with 9342 or “typing few starting 
	characters in a web browser displays all website names with this prefix”(Auto complete feature)”.
	
	2. Used in spell checks: Ternary search trees can be used as a dictionary to store all the words. 
	Once the word is typed in an editor, the word can be parallely searched in the ternary search tree to 
	check for correct spelling.

	3. One of the advantage of using ternary search trees over tries is that ternary search trees are a 
	more space efficient (involve only three pointers per node as compared to 26 in standard tries). 
	Further, ternary search trees can be used any time a hashtable would be used to store strings.

	4. Tries are suitable when there is a proper distribution of words over the alphabets so that spaces 
	are utilized most efficiently. Otherwise ternary search trees are better. Ternary search trees are 
	efficient to use(in terms of space) when the strings to be stored share a common prefix.
