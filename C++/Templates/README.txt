Objective:
==========
	Understand templates in C++

Logic:
======
	1. Templates is a way of making our class more abstract by letting us define the behavior of a class without actually knowing what datatype will be handled by the operation of the class.

	2. This is similar to generic programming. i.e A templated class does not depend on the datatype it deals with. 

	3. They can be used in conjunction with abstract datatypes in order to allow them to handle any type of data. 

	4. Eg: We can make a templated stack class that can handle a stack of any datatype, rather than having to create a stack class for every different data type for which we want the stack to function. 

	5. The ability to have a single class, that can handle several different data types means the code is easier to manage and it makes the classes more reusable. Without templates, we need to replicate the same code all over again and again.

	6.Templates are of two types. Function templates and class templates.

	7. Function templates: 
	void PrintTwice(TYPE data){
		// Actual TYPE would be deduced by the compiler depending on the argument passed to the function.
	}
	template<class T>
	T Add(T n1, T n2)
	{
	    T result;
	    result = n1 + n2;
	    return result;
	}

	8. The compiler actually duplicates the code. The advantage here is that, the programmer need not copy paste it everytime. He just needs to provide a template function and the rest would be managed by the compiler. 
	Another advantage is that, if we manually define 10 different overloads,then the code size would increase x + 10. In the case of template, only if we call the same function with 10 different types of parameters, the code will be increased in size. 

