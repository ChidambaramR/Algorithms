Objective:
==========
	Given a rotated sorted array find the minimum element in it. i.e The initial array will be 10 12 14 16 17 18 19. We can rotate this by 2 positions. So the array becomes 18 19 10 12 14 16 17. In this new array, find the minium value.

Logic:
======
	This can be done by a binary search. The idea is that, if the middle element is greater than the element in the leftmost, then it means that the minimum element is somewhere in the range {middle+1, right}. If the middle element is lesser than the leftmost element then the miniumum element will be in the range {left, middle-1}. 
	In the above example, the middle element is 12 and is lesser than the leftmost element. So it is in the range {left, middle-1}, i.e it is in the range {18, ..., 10}. In this new list, middle element is 19 and is greater than the leftmost element. So the minimum element is in the range {middle+1, right}. Thus the minimum element is found to be 10.

Program:
========
	There are two break conditions.
	1. The min element can itself be the middle element. In this case, there is no point in proceeding forward. So we have to introduce a condition which checks if mid element is lesser than its previous element. In that case, we can find the answer.
	2. The min element is the last element. The binary search narrows to the last element and in this case, the left index is equal to the right index. So we can find the min element.
	Else, it is normal binary search. If the middle element is greater than the leftmost element, then the min element is in the range {middle+1, right}. If the middle element is lesser than the previous element, then the min element is in the range {left, middle-1} 
