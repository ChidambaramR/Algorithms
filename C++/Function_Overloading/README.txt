Objective:
==========
	To understand function overloading.

Logic:
======
	The following types of functions cannot be overloaded.
	1. Functions which differ only with return type.
		Eg: int foo() {} and char foo() {}
		The compiler will get confused on what to return when foo() is called.

	2. Member functions with the same name and same parameter-type list cannot be overloaded if anyone of them is static.
		Eg: Class test{
			static void fun(int i){}
			void fun(int i) {}

	3. Parameter declarations which differ only in pointer adjustment types.
		Eg: void h(int *arr) {}
		    void h(int arr[]) {}

	4. Parameter declarations which differ only by a pointer type.
		Eg: void f( int () ) // F is a function whose arg is a function pointer of a function which received nothing, returns int.
		    void f( int (*)() ) // F is same as above, except it is a pointer to such a function

	5. Parameter declarations which differ only by a const/volatile.	
		Eg: int f(int x) {}
		    int f(const int x) {}
	   But function overloading will be allowed when a const reference/pointer is passed as an argument. The reason is, when just a const
	   value is passed, there is no sense making overloading. We are just passing by value from main. So the changes in main will not be
	   reflected. So there is no purpose of making function overload with const.
           But const pointer can make a difference. Because, the changes in the pointer can be reflected in main. So function overload can be
	   permitted depending on the value of const to a reference/pointer

	6. Parameter declarations which differ only by default arguments.
		Eg: int f(int a, int b=0) {}
		    int f(int a) {}
		The compiler will get confused, when called f(10), since default argument is there for 1st f().
