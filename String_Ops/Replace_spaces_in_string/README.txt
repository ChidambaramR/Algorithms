Objective:
==========
	Given a string, replace the white spaces in the string with %20

Logic:
======
	We first make a pass in the string and count the number of whitespaces. 
	We then extend the length of the string including the white spaces. Example, if the string is
	"a b c". Initial length is 5. The new string should be "a%20b%20c". The new length is 9. 
	For %20 we should add 3 characters extra. But instead of a space we are going to replace this.
	Hence just two characters is enough. Thus the new length is going to be, length + 2*no_of_whitespaces.
	Now we start from the newLength. This is to ensure we dont need to shift any existing characters.
	We just keep adding from the end.
	Consider the string "a b c".
	We start putting the characters from newLength 8. "a b c    "
	Initially c is encountered. So we just copy the character. "a b c   c"
	Now space is encountered. "a b c%20c"
	Now b is encountered. "a b b%20c"
	Now space is enountered. "a%20b%20c"
	Now a is encountered. So a is copied in the same place.
	
	
