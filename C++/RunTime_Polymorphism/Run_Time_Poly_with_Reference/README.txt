Objective:
==========
	To understand untime polymorphism in C++

Logic:
======
	We define a function which gets an object of the base class as the parameter. The expectation is that, if a base class object is passed as a paramater, it should call the method of the base class. Whereas, if it is called with the object of the derived class, then it should call the methods of the derived class. This is called as run time polymorphism since at run time, the type is determined. 
	The 1st program doesnt work because of Object Slicing. When a derived class instance is assigned to a superclass instance, then the passed object is sliced or not copied to the super class instance.
	The correct_ program passes the arguments by reference and hence object slicing is not done.
