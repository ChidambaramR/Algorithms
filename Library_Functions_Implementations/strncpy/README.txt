Objective:
==========
	Implement the string library's strcpy function.

Logic:
======
	There are problems with the crude implementation of the strcpy which follows.
		void strcpy(char *dst, char *src){
			while(*dst++ = *src++);
		}

	But there are two problems in this approach.
	1. There is a possibility of buffer overlap. Meaning, the destination buffer can overlap the source buffer
		while copying the data. To avoid this, we are using src as pointer to constant char ( const chat *src).

	2. Second problem is the buffer overlow. The destination buffer can be small. But the size of the source buffer
		can be big. In this case, the copy will start writing outside the destination buffer. To avoid this,
		we pass the length so that, only 'n' bytes the source string are copied. This prevents overflow because
		the programer should know how much length he should pass.
