#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// align to nearest 8
#define align8(x) (((((x)-1) >>2) <<2)+8)
typedef struct s_block* t_block;

/* 
Initial value to start with
They are similar to the head and the tail pointers of a singly LL.
The last enables quick insertion at the end of the linked list.
We will also be using last to keep track of the last place at which we
added a node
*/
t_block base=NULL;
t_block last=NULL;

/*
It might seem waste to use an int for storing free. But anyways the compiler
padding will not buy us much had we used bool
*/
struct s_block{
  t_block next;
  t_block prev;
  void *ptr;
  int free;
  int size;
  char data[0]; // Start of actual memory
};

#define BLOCK_SIZE (sizeof(struct s_block))

t_block find_block(t_block *last, int size){
	t_block b = base;
	/*
	While this block is free and the size of this block is greater
	than the size requested, go ahead and search. If this block is
	valid (not NULL) and this is free and this block's size is greater
	than the requested size, stop the while loop and return this block (b)
	*/
	while(b && !(b->free && b->size >= size)){
		*last = b;
		b = b->next;
	}
	return b;
}


void* extend_heap(t_block last, int size){
  t_block b;
  b = sbrk(0);
  if(sbrk(100*size) == (void*)-1){
    // No more space in heap
    return NULL;
  }

  /*
  We have extended the heap. The starting place was recorded in b
  */
  b->next = NULL;
  b->size = 100*size;
  b->ptr = b->data;
  /*
     This is similar to the tail pointer of a singly linked list
     which enables quick insertion at the end, without traversing
     the entire list
  */
  if(last){
    last->next = b;
    b->prev = last;
  }

  return b;
}

/*
  1. Initial block pointed to by b. Size is 20
  ---------------------------
  |Size: 1000               |
  |Next: NULL               |
  ---------------------------

  2. After split
     -------------------------
    |Size: 20   | Size: 980  |
    |Block B    | Block: NEW |
    |Next: NEW  | Next: NUKK |
    |Prev: X    | Prev: B    |
    --------------------------
*/

void split_block(t_block b, int size){
  t_block new;
  new = (t_block)((char*)b->data + size);
  new->size = b->size - size;
  new->next = b->next;
  new->free = 1;
  b->size = size;
  b->next = new;
  b->ptr = b->data;
  new->prev = b;
  new->ptr = new->data;
}


void* my_malloc(int size){
  t_block b;
  t_block last;
  size = align8(BLOCK_SIZE + size);

  if(base){
    // Heap already initialized
    last = base;
    /*
    We are passing the address of last here. When a memory was allocated, last
    will be pointing to the previous block which was NOT free.
    Similarly, if a block was not able to be located, then it will point to the
    last block in the heap and so this can be easily used for extending the heap.
    */
    b = find_block(&last, size);

    if(b){
      /*
         A matching block was found and we need to see if it is large enough so that
         it can be split into one block which is alomost as the size was requested
         and the other block can be donated back to the heap.
      */
        if((b->size - size) >= (BLOCK_SIZE+4))
          split_block(b, size);

        b->free = 0;
    }
    else{
    	b = extend_heap(last, size);
  	b->free = 0;
	split_block(b, size);
    }
  }
  else{
    // We are coming for the 1st time
    b = extend_heap(NULL, size);
    if(!b){
      /*
      We have exhausted our heap space. So Return NULL
      */
      return NULL;
    }
    b->free = 0;
    split_block(b, size);
    base = b;
  }
  
  return (b->data);
  
}

/*
This is called by the free function, to check if the pointer supplied
is actually allocated by malloc. It returns the starting of the block to which
this pointer belongs to.
*/
t_block get_block(void *p){
	char *tmp;
	tmp = p;
	tmp -= BLOCK_SIZE;
	return (t_block)tmp;
}

void my_free(void *p){
	/*
	The field ptr in meta-data of the block stores the starting value of the
	pointer. It checks if the input value and the pointer in the metadata are
	equal. If they are equal, then the pointer is the one which was returned by
	malloc
	*/
	if(p == (get_block(p))->ptr){
		((t_block)(p))->free = 1;	
	}
	else
		return;
}

int main(){
  int *a;
  int i=0;
  a = (int*)my_malloc(10);
  for(i=0; i<15; i++){
  	a[i] = i;
  }

  int *b = (int*)my_malloc(49);
  for(i=0; i<15; i++){
  	b[i] = i+20;
  }
  // display
  for(i=0; i<15; i++){
  	printf("%d\n",a[i]);
  }
  for(i=0; i<15; i++){
  	printf("%d\n",b[i]);
  }
  my_free(b);
  return 0;
}
