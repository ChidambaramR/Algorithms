Objective:
==========
	Given a 2D sorted array, where each row is sorted in ascending order from left to right,
	and each column is sorted in ascending order from top to bottom, find an element.

Logic:
======
	Let us consider the following 2D array.
		1,   2,  3,  4,  5,  6
		7,   8,  9, 10, 11, 12
		13, 14, 15, 16, 17, 18

	We start the logic with row being 0 and col being last column (i.e N-1). Thus the element with
	which we begin is 6 (i.e matrix[0][5] // row = 0, col = N-1 = 5)
	1. Check if this element is equal to the element we are looking for. If so, return TRUE
	2. If the element is bigger, then we can eleminate this column as, the column is already sorted
		in ascending order and the 1st element in the column is bigger than the element we are
		looking for. Thus there is no way, the target element will be in this column. So
		decrement the column. 
	3. If the element is lesser than the target element, then increment the row. Since the row is
		already sorted in ascending order, and the current element is less than the target, there
		is no way, the target element can be in this row since we are already at the end of the row.
		So increment the row.
	4. Proceed with this logic, till row < M and col >= 0
