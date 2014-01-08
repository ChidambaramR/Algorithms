Objective:
==========
	Given two linked lists, add the digits and print the new result.

Logic:
=====
	The point here is that the length of the two lists can be different. If the length of the
	two lists are same, then this can be done by a simple recursion. Go to the end of the list,
	add the two digits. Create a new linked list by inserting in the front. The data of the new 
	list will be the mod of the sum and if the value is greater than 10, then a carry of 1 is
	returned else, a carry of 0 is returned to the previous level.
	The sum now is carry + both node's data. Do the same mod and return the carry and this goes on.

	If the length of the lists are different, then move the bigger list till both the lists start at
	the same point. Calculate the sum as mentioned above. Add the carry with the last node in the bigger
	list and append the new list to the bigger node at the point where the length of both the lists became
	equal.
