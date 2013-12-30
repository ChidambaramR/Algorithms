Objective:
==========
	Build a TRIE and do basic operations on it.

Logic:
======
	TRIE is sometimes called a prefix tree and is an ordered data structure where keys are usually strings. Unlike a BST, no node in a TRIE stores the key associated with that node. All the descendants of a node belong to a common prefix of the string associated with that node and the root is associated with an empty string. 

Time Complexity:
================
	Looking up in a TRIE is much faster as it takes only O(m), where m is the length of the search string. 	
	
Advantages:
===========
	There are no collisions in a trie. 
	No need of a hash function.
	A big application of the trie is storing the autocomplete feature in a text editor of a phone. 

