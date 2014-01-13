Objective:
==========
	Implement run time polymorphism in C.

Logic:
======
	This feature can be achieved by emulating the vtable mechanism in C. This is how vtable works. 
	If any function of a class is declared as virtual, a v-table is constructed which stores address of
	virtual functions of this class. The compiler also adds a hidden vptr variable in all such classes
	which points to the vtable. 
	If a virtual function is not over-ridden in the derived class, the vtable of the derived class stores
	the address of the functions in the parent class. The vtable is only used to resolve the address of a
	function whenever a virtual function is called. Dynamic binding in C++ is therefor performed through
	vtable mechanism. 
	In C++, non-virtua function calls are resolved using compile time with static binding, while virtual
	functions are resolved at run time with dynamic binding. 
