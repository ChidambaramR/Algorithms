Objective:
==========
	Implement a normal stack as Linked List

Logic:
======
	Each entry of the stack is a node in the linked list. Top will always be pointing to the begining of the list.
	The stack is constructed like the following.
		Let us insert the following elements. 1,2,3,4,5
	1. Stack is empty. Insert 1
		NULL<-1(top)
	2. Insert 2
		temp->next = top	NULL<-1(top)
						^
						|
						2(temp)
		
		top = temp		NULL<---1
						^
						|
						2(top)
	3. Insert 3,4,5
		NULL<-1<-2<-3<-4<-5(top)

	Now we POP 5 from the stack
		temp = top	NULL<-1<-2<-3<-4<-5(top/temp)
		top = top->next 	NULL<-1<-2<-3<-4(top)<-5(temp)
		free temp		NULL<-1<-2<-3<-4(top)
		  
