Objective:
==========
	Given an array, implement 2 stacks in it.

Logic:
======
	Take two variables top1 and top2. Top1 points to the begining of the array and Top2 points to the end of the array.
	Both the arrays grow dynamically, and overflow is detected only when one pointer meets the array.
	This is a space optimized version of having the array divided into two halves and detecting a stack overflow by
	checking if Top1 has reached half of the array. Thus in this case, one stack will overflow even if other stack has not been
	filled at all.
