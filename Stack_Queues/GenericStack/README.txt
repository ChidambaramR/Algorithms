Objective:
==========
	Design a generic Stack which can take any values (i.e int/float etc)

Logic:
======
	This can be the basic structure of the stack
	struct stack{
		void *elems; // Generic pointer to elements
		int elemSize; // Size of the type the stack is going to hold
		int counter; // Length of the stack so far
		int max; // Maximum length;
	};

	Whenever we insert a new element, the counter is incremented by 1.
	If the counter equals max, then we have to expand the
	stack by allocating more memory for the area pointed to by the void*.
	For displaying the stack, we need to fill the address of the values in a
	void buffer and send them to the client program becuase we will not know
	what data type it should be typecasted to while printing. So it is the duty of
	the client program to receive the void* buffer and print the data.
