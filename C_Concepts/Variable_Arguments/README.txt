Objective:
==========
	Understand the working of variable arguments parameter passing in C.

Logic:
======
	Every function which accepts variable arguments, accepts two parameters. One is the variable argument
	and another argument. This another argument will be the last on the stack and mostly it is a char* in the
	case of printf. So the function knows what is the last argument and how much big it is. With this information
	it gets to the start of the variable argument.

	So we have a pointer to the begining of the variable argument data. How will we know how big it is or what did
	the caller pass in. There should be something to tell this information. In the case of printf, the 1st character 
	pointer tells this. i.e "Hello world %d". This says that there is one argument after this. For example, if the
	argument is %l or %d, we can know that the next variable argument waiting for us is a 32 bit signed integer.
	We can fetch this data and move the pointer 4 bytes ahead. The pointer now moves to the next variable argument. 

	Thus we see how arguments were pushed onto the stack. GCC provides helper macros to traverse this variable
	argument list. 

	va_start sets arg_ptr (variable argument pointer: our own variable) to the start of the parameter list.
	arg_ptr should be of the type va_list.

	va_arg is the important routine. It retrieves the argument from the argument list of the required type.
	i.e va_arg(arg_pte, int), va_arg typecasts the value starting at arg_ptr as an integer and returns the result
	back. 
	The above is used for char also because C standard mentions that when arguments of type char are passed as
	variable arguments, it is promoted to type integer. It then increments the arg_ptr by using the size of the element
	that was passed onto va_arg.

	va_end resets the pointer to be NULL 

	Implications
	It is upto the caller to ensure that the format string matches the data that is passed in. If the format string
	says the 1st argument is a string (i.e %s) and we pass an integer, the called function will only interpret it as
	a string and not an integer. The called function has no way to type check it as there is nothing to check against.
