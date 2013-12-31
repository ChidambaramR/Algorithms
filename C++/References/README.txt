Objective:
==========
	To understand references in CPP

Logic:
======
	Both references and pointers can be used to change local variables of one function inside another function. Both of them can also be used to save copying of big objects when passed as arguments to functions or returned from functions, to get efficiency gain.

	Despite the above similarities, there are certain differences:
	1. Once a reference is created, it cannot be made to refer another object. It cannot be reseated. This can be done with pointers.
	2. References cannot be NULL while pointers can be. 
	3. A reference must be initialized when declared. 

	Advantages of references:
	1. Safe: Since references must be initialized, there is no chance of NULL crash
	2. Easy: References dont need de-referencing to access value. & operator is needed only at the time of declaration. 	
