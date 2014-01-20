Malloc is a standard C library routine that allocates / reserves memory chunks. 
It follows the prototype void *malloc(size_t);

Each process has its own address space dynamically mapped into physical pages. Heap is a virtuall continuous space
  of memory in the process address space, that has a starting point, a limit and an end point called break.
  Break marks end of the mapped space. In order to code an malloc we need to know where the heap begins and the break
  positions. 


brk - Places the break pointer at the given address and returns 0 if successful and -1 if otherwise. 
sbrk - Move the break pointer / increment it by given bytes.
  sbrk(0) returns the current break point. Break may not be on page boundaries. 

mmap - In anonymous mode, it can allocate a specific amount of memory (by page granularity) and munmap can free it.
  Many malloc implementations use mmap for larger allocations.  

Managing Heap:
  We need a small block at the begining of each chunk containing the extra information called the meta-data. This block 
  contains a pointer to the next free block and the size of the data of this chunk. This block of information is before
  the pointer returned by malloc. Thus, there is a meta-data followed by block of data. 
