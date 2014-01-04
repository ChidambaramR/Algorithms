Objective:
==========
	To implement a queue with two stacks

Logic:
======
	Let us take two stacks s1 and s2. 
	Initially we push all the elements into s1 until a dequeue operation is done.
	When a dequeue operation is done, we pop all elements off stack 1 and push elements into stack2
		and then pop an element off stack 2 and return it. If any push is made in this time, it 
		is enqueued into stack 1 again. Now all dequeues is just made by popping off last element
		from stack 2. Again when stack 2 becomes empty, we push all elements into stack 1 and
		do the same operation.

	Let us take an example. Let the elements be 1,3,4,5,6,8,9,12,31

	1. Initially 1,3,4,5,6 are pushed.
	Stack1:		Stack2:
	6 <-- top
	5
	4
	3
	1
	
	2. Now one element is popped off. We should get opt as 1. But top is at 6. So we push all elements
	   in stack 1 to stack 2. The stack will look like this. i.e Pop elements one by one from stack1
	   and push it on to stack2. The value returned is 1
	   			     ------------------------
	Stack1:		Stack2:
			3 <-- top
			4
			5
			6

	3. Now we enqueue 8,9,12
	Stack1:		Stack2:
	12 <--top	3 <-- top
	8		4
	9		5
			6

	4. We do a dequeue. The value returned is 3
			    ------------------------
	Stack1:		Stack2:
	12 <-- top	4 <--top
	8		5
	9		6

	5. We do a dequeue. The value returned is 4
			    ------------------------
	Stack1:		Stack2:
	12 <-- top	5 <-- top
	8		6
	9

	6. We now enqueue 31
	Stack1:		Stack2:
	31 <--top	5 <--top
	12		6
	8

	7. We do a dequeue. The value returned is 5
			    -----------------------
	Stack1:		Stack2:
	31 <--top	6 <-- top	
	12
	8

	8. We do a dequeue. The value returned is 6
			    -----------------------
	Stack1:		Stack2:
	31 <--top	
	12
	8

	9. We do a dequeue again. The value returned is 8 ( we shifted the stacks )
				  ------------------------
	Stack1:		Stack2:	
			12 <-- top
			31

	So, 
	The enqueued order is 1,3,4,5,6,8,9,12,31
	The dequeued order is 1,3,4,5,6,8
	Thus FIFO is maintained.
