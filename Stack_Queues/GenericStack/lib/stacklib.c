#include "genstack.h"

void newStack(struct stack *s, int size, void (*fp)(void*), void (*dp)(void*)){
	if(!s){
		// No memory
		return;
	}

	s->max = MAX;
	s->elems = malloc((s->elemSize)*(s->max));
	s->top = 0;
	s->elemSize = size;
	s->freeFn = fp;
	s->displayFn = dp;
}


void Push(struct stack *s, void* item){
	void *dstAddr;

	/*
	If the allocated length becomes equal to max length
	then we need to resize the stack. 
	*/
	if(s->top == s->max){
		s->max = (s->max)*2;
		s->elems = realloc(s->elems, (s->elemSize)*(s->max));
	}

	// We now have the memory
	dstAddr = (void*)((char*)s->elems + s->top*(s->elemSize));
	memcpy(dstAddr, item, s->elemSize);
	s->top++;
}


/*
Here we can also follow the approach of returning a void pointer to the client function.
In that case, we need to allocate memory in the library routine and pass that memory to the
client. Usually its not he job of the library to allocate memory for the client. The client
has to take care of it memory. So the client just passes the variable in which it wants the address
and the library returns the value at the stack in this variable.
*/
bool Pop(struct stack *s, void* item){
	if(s->top == 0){
		return 0;
	}

	/*
	We should not free the element soon after returning it.
	We are returning a pointer to that element and the client now has the
	ownership of the element. So if we free it here, the client will have a pointer
	to the element which is already free'd. It is the responsiility of the client
	to free the element since he has the pointer to the returned element.
	*/
	const void *srcAddr;
	s->top--;
	srcAddr = s->elems + s->top*(s->elemSize);
	memcpy(item, srcAddr, s->elemSize);
	return 1;
}


/*
The main challenge the display function is that it cannot display :)
This is because, it does not know what is the data-type to be typecasted.
So it fills the address of all the elements in its container (s->elems)
and returns an array of void pointers. It is the duty of the client
who calls this function to typecast it to whatever definition it wants
and display the result.
*/
void* display(struct stack *s){
	/*
	Fill the buffer with 0's. We are not giving the number of elements in the
	container to the client. Thus the client should determine when the loop has to
	be stopped.
	*/
	void *buf = calloc(s->top, sizeof(void*));
	int i=0;
	int cnt = s->top;
	void *dstAddr;
	void *srcAddr = (void*)((char*)s->elems + (s->top-1)*s->elemSize);

	while(cnt--){
		dstAddr = (void*)((char*)buf + i*s->elemSize);
		/*
		Copying the contents in the containter byte by byte to the buffer which
		is going to be passed to the user. 
		*/
		memcpy(dstAddr, (srcAddr - i*s->elemSize), s->elemSize);
		i++;
	}
	
	return buf;
}

void stackDisplay(struct stack *s){
	int i;
	if(s->displayFn != NULL){
		for(i=0; i<s->top; i++){
			s->displayFn((char*)s->elems + i*s->elemSize);
		}
	}
}


void disposeStack(struct stack *s){
	int i;
	if(s->freeFn != NULL){
		for(i=0; i<s->top; i++)
			s->freeFn((char*)s->elems + i*(s->elemSize));
	}

	s->top = 0;
	free(s->elems);
}


