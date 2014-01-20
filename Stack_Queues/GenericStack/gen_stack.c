#include <stdio.h>
#include "lib/genstack.h"

struct temp{
	int id;
	char *name;
};

void structFree(void *elem){
}


void structDisplay(void *elem){
	struct temp *ptr;
	ptr = (struct temp*)(*((char**)elem));
	printf("Id = %d, Name = %s\n",ptr->id, ptr->name);
}


void test_structStack(){
	struct stack structStack;
	newStack(&structStack, sizeof(struct temp), structFree, structDisplay);
	struct temp *ptr;
	struct temp obj[5];

	obj[0].id = 1;
	obj[0].name = "Chid";
	ptr = &obj[0];
	Push(&structStack, &ptr);

	obj[1].id = 2;
	obj[1].name = "EMC";
	ptr = &obj[1];
	Push(&structStack, &ptr);

	obj[2].id = 3;
	obj[2].name = "Nutanix";
	ptr = &obj[2];
	Push(&structStack, &ptr);

	stackDisplay(&structStack);
}



int main(){
	test_structStack();
	return 0;
}
