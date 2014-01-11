Objective:
==========
	Given two arrays, print the common elements in the arrays without printing the duplicates.

Logic:
=======
	Sorting
	-------
		Sort both the arrays. 
		Have one pointer each for the arrays. 
		if(a[i] == a[j])
			print the common values
			increment the pointer for both a and b

		if(a[i] < a[j])
			increment the pointer of 'a' alone. Since the value of a[i] is less
			the value at b[j] we have to increment the value of i and move the pointer ahead.

		if(b[j] < a[i])
			increment the pointer of 'b' alone. Since the value of b[j] is less than
			the value at a[i], we have to increment the value of j and move the pointer ahead. 
