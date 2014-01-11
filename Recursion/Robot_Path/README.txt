Objective:
==========
	A robot is standing at square 1*1. It needs to go square m*n. 

Logic:
======
	Recursive version
	-----------------
		We start at 0,0. xmax is the destination x square. ymax is the destination y square.
		We first traverse in the x direction and reach till the maximum x square. Once we hit
		this place, we traverse down and reach till maximum y square. Once we reach xmax and
		ymax we return the result as 1. Then we backtrack and return the result.

	DP
	--
		The possible way to reach a square is the square from the top or square from the left.
		i.e robot can move only right or down. So the number of ways the robot can reach the current
		square is the sum of number of ways it can reach the left square and the number of ways it
		can reach the top square.
