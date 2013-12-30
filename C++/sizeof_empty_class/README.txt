Objective:
==========
	To understand how the size of empty class gets changed

Logic:
======
	The size of empty class is never 0. This is to prevent two addresses pointing to same object. If obj1 of empty class has address 0x100 and size is 0, then obj2 of empty class will also point to the same place. 
	Size of an empty class is not zero. It is 1 byte generally. It is nonzero to ensure that the two different objects will have different addresses
	For this reason, "new" always returns pointers to distinct objects. 
