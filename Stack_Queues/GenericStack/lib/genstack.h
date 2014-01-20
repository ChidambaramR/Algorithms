#ifndef _GENSTACK_H_
#define _GENSTACK_H_

#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef enum {false, true} bool;

struct stack{
	void *elems;
	int elemSize;
	int top;
	int max;
	void (*freeFn)(void *);
	void (*displayFn)(void *);
};

void newStack(struct stack *, int, void (*)(void*), void (*)(void*));
void Push(struct stack*, void*);
bool Pop(struct stack*, void*);
void* display(struct stack*);
void disposeStack(struct stack*);
#endif
