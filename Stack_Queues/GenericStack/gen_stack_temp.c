#include <stdio.h>
#include "lib/genstack.h"

void test_intStack(){
	struct stack intStack;
	int x, n;
	int i=0;
	int *buf;

	newStack(&intStack, sizeof(int), NULL, NULL);
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

void stringFree(void *elem){
	free(*((char**)elem));
}

void stringDisplay(void *elem){
	char *temp = *((char**)elem);
	printf("Friends name: %s\n",temp);
}

void test_stringStack(){
	struct stack stringStack;
	int i=0;
	char *friends[] = {"Alis", "Bob", "Michael"};
	char *temp;
	
	newStack(&stringStack, sizeof(char*), stringFree, stringDisplay);
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

	stackDisplay(&stringStack);

	disposeStack(&stringStack);

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
