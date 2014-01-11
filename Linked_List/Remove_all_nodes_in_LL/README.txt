Objective:
==========
	Incorporate all forms of delete in a singly linked list.

Logic:
======
	For any kind of delete operations, carefully consider special cases like deleting the head node.
	
	1.Delete all occurences of a node
	----------------------------------
	For example, when a list like 20->20->20->10->20 is given and it is asked to delete all occurences
	of 20, care has to be taken since the 1st element itself 20. Our delete operation usually checks if
	head->next->data == data. So in this case, first 20 will not be checked. 
	So write 2 parts. If the 1st element is the data to be deleted, then in a while loop keep deleting the
	head element, if it is the actual element to be deleted. Make the head element such that, it is not the
	element to be deleted. So in the case of the above example, the list will be 10->20 after deleting the
	initial 20's.
