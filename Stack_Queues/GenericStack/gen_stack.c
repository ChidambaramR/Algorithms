#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

struct stack{
	void *elems;
	int elemSize;
	int counter;
	int max;
};

void newStack(struct stack *s, int size){
	if(!s){
		// No memory
		return;
	}

	s->max = MAX;
	s->elems = malloc((s->elemSize)*(s->max));
	s->counter = 0;
	s->elemSize = size;
}

void Push(struct stack *s, void* item){
	void *dstAddr;

	/*
	If the allocated length becomes equal to max length
	then we need to resize the stack. 
	*/
	if(s->counter == s->max){
		s->max = (s->max)*2;
		s->elems = realloc(s->elems, (s->elemSize)*(s->max));
	}

	// We now have the memory
	dstAddr = s->elems + s->counter*(s->elemSize);
	memcpy(dstAddr, item, s->elemSize);
	s->counter++;
}

void Pop(struct stack *s, void* item){
	const void *srcAddr;
	s->counter--;
	srcAddr = s->elems + s->counter*(s->elemSize);
	memcpy(item, srcAddr, s->elemSize);
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
	void *buf = calloc(s->counter, sizeof(void*)*(s->counter));
	int i=0;
	int cnt = s->counter;
	void *dstAddr;

	while(cnt--){
		dstAddr = buf + i*s->elemSize;
		/*
		Copying the contents in the containter byte by byte to the buffer which
		is going to be passed to the user. 
		*/
		memcpy(dstAddr, (s->elems + i*s->elemSize), s->elemSize);
		i++;
	}
	
	return buf;
}


int main(){
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
	return 0;
}
