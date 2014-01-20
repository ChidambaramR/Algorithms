#include <sys/types.h>
#include <unistd.h>

void* malloc(int size){
  void *p;
 
  /*
  P stores the current break pointers value. sbrk(size) will now move the break
  pointer by size bytes indicating that, after this region it is free. Thus
  Eg: if sbrk(0) is 10, and size is 5,
  p = 10 (free memory's address) Break Pointer at 10
  sbrk(5) Break pointer at 15

  */
  p = sbrk(0);
  if(sbrk(size) == (void*)-1){
    return NULL;
  }

  return p;
}
