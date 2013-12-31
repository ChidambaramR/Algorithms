Objective:
==========
	To understand object slicing in CPP.

Logic:
======
	In OOP, a subclass typically extends its superclass by adding additional member variables. If a superclass INSTANCE is assigned a value from a subclass INSTANCE, member variables defined in the subclass cannot be copied, since the superclass has no place to store them. This is because, when we pass by value, the whole object is passed and there is no space. Thus the object is sliced when passed as a value. This is avoided if we pass by reference.

