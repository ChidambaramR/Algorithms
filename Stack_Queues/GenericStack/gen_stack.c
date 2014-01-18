#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef enum {false, true} bool;

struct stack{
	void *elems;
	int elemSize;
	int top;
	int max;
};

void newStack(struct stack *s, int size){
	if(!s){
		// No memory
		return;
	}

	s->max = MAX;
	s->elems = malloc((s->elemSize)*(s->max));
	s->top = 0;
	s->elemSize = size;
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

void test_intStack(){
	struct stack intStack;
	int x, n;
	int i=0;
	int *buf;

	newStack(&intStack, sizeof(int));
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		/*
		While pushing, we are sending the address of the variable x. This is because
		if we are to send the value of x directly, then the prototype of the function
		which does the push should be Push(struct stack *s, int item) in the case we
		are pushing ints. If we are pusing char then the prototype should change to
		char item. So to avoid this, we are passing the address of x so that it can be
		received as void*
		*/
		Push(&intStack, &x);
	}

	// Display stack
	buf = (int*)display(&intStack);
	while(buf[i]){
		printf("%d ",buf[i]);
		i++;
	}
	free(buf);
}

void test_stringStack(){
	struct stack stringStack;
	int i=0;
	char *friends[] = {"Alis", "Bob", "Michael"};
	char *temp;
	
	newStack(&stringStack, sizeof(char*));
	for(i=0; i<3; i++){
		char *copy = strdup((const char*)friends[i]);
		/*
		Reason why we should pass &copy and not just copy:
		If we pass just copy, then the memcpy in the push function will
			write into s->elems array, the value pointed to by the string.
		x /10wx s->elems
		0x602060:       0x73696c41      0x00000000      0x00000000      0x00000000
		0x602070:       0x00000000      0x00000000      0x00000000      0x00000000
		If you see, the 1st element should ideally contain the pointer to the string
			"Alis". Instead it has stored the value(string) in the stack. Our
			stack now contains Alis in its 1st element. The free function will now
			try to free 0x73696c41 which is an invalid address.

		Thus we should pass &copy and the elems will look like
		(gdb) p item // item is the pointer to char* of Alis.
		$2 = (void *) 0x7fffffffdfe8
		(gdb) x /10wx s->elems

		0x602060:       0x00602440      0x00000000      0x00000000      0x00000000
		0x602070:       0x00000000      0x00000000      0x00000000      0x00000000
		
		i.e 0x7fffffffdfe8 points to 0x00602440 which points to "Alis"
		the memcpy will store the value at 0x7fffffffdfe8 to the 1st element in the stack which
			is 0x00602440
		*/
		Push(&stringStack, &copy);
	}

	/*
	Here again we should pass the address of the character pointer temp. If we just pass the value of temp,
	then the memcpy in the POP function, will try to write the value in the stack to the value pointer to 
	by this array. Currently, temp is not pointing to anything and it is not the duty of the stack to fill in 
	the value. It is just going to return the address of the value in the stack in this variable.
	*/
	for(i=0; i<4; i++){
		if(Pop(&stringStack, &temp)){
			printf("\nString is %s\n",temp);
			free(temp);
		}
		else{
			printf("\nStack is Empty\n");
			return;
		}
	}
}

int main(){
//	test_intStack();
	test_stringStack();
	return 0;
}
