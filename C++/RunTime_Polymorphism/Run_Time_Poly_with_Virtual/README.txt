Onjective:
==========
	Achieve runtime polymorphism with the help of virtual keyword.

Logic:
======
	Initially, when there is no virtual keyword, "compile time binding is done". This is also called "static resolution" or static linkage. The function call is fixed before the program is executed. This is also called "Early binding". 
	When we add the 'virtual' keyword for a method, the compiler looks at the contents of the pointer instead of its type. 
	A virtual function is function in the base class, that is declared using the keywork virtual. Defining in a base class, a virtual function, signals to the compiler that we do not need static linkage for this function. We tell the compiler that the selection of the function to be called, is based on the kind of the object for which it is called. This is called dynamic linkage or late binding. 

	In the main function, we actually declare two objects for Rect and Triangle and assign the references to the base class. So ideally, what we would expect is that, Shape->area is equal to calling rec.area when Shape = &rect and Shape->area is equal to calling tri.area when Shape = &tri. But because, both the type of Shape is pointer to Shape and not a pointer to rect or tri ( becuase we declare Shape is a pointer to Shape class and then we assign the ref of rec/tri to it ), only the members from base class can be called. This is because the compiler just looks at the type of the pointer and not the contents in the pointer.
