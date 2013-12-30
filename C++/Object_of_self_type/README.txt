Objective:
==========
	To define a non-static object of same type within a class

Logic:
======
	1. A class/struct is complete only after closing braces (}), till that point any attempt to define that class/struct will be an error. It is because the declaration is incomplete and compiler can’t assume class size. 
	
	2. We can have a pointer to same class/struct inside the class. Since pointer occupies unique size irrespective of data type it is going to point, (i.e. it is the pointer going to occupy space in the class/struct not the object what it is pointing which is incomplete at that instance). Such structures, we call as self-referrential structrues in C/C++, useful for linked lists, trees, etc
	
	3. In case of C++, a static member will be intialized (defined) outside the class. Hence a calss can have static member of same class. More specifically the static member will not contribute to class’s size. In C it is not possible to place static inside struct. The following example will clarify these.

	4. A static data member is not part of the subobjects of a class. There is only one copy of a static data member shared by all the objects of the class. In C++, static members don't belong to the instances of class. they don't increase size of instances and class even by 1 bit!

	struct A
	{
    		int i;
    		static int j;
	};
	struct B
	{
    		int i;
	};
	std::cout << (sizeof(A) == sizeof(B)) << std::endl;

Output of the program will be 1.
