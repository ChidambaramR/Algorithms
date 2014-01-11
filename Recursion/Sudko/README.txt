Objective:
=========
	Write a program to solve the sudoku puzzle

Logic:
======
	The program can be broken into modules. 
	
	1. Find poisition to fit the number in
	--------------------------------------
		We need to find a square in which no number is present. We get the position of row and column.

	2. Try to assign a number to the empty sqaure
	----------------------------------------------
		We try to assign a number from 1 to 9 in this square. Once assigned a number we have to check
		for the validty of placing that number.

	3. Check validity
	------------------
		1. Check if the number is present in any position in the same row. If so return false.
		2. Check if the number is present in any position in the same column. If so return false.
		3. Check if the number if present in any position in the same sqaure. If so return false.
		4. If none of the above conditiosn were satisfied, then it means that the number can be
			placed in that sqaure.

	4. Recursion
	-------------
		If the number can be placed, then recursively try for all the sqaures.
