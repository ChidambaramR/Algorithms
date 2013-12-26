Objective:
==========
	Given an array and a target sum, find if any two pairs of elements add upto the sum. 

Logic:
======
	This can be done in O(nlogn) time and no extra space using the following approach. 
	1. Sort the array
	2. Initialize the left pointer to the start of the array and initialize the right pointer
		to the end of the array.
	3. At each step check if the sum of the elements pointer to by the left and right pointer is
		equal to the target sum.
	4. If the sum is less then the target sum, then increment the left pointer.
	5. If the sum is greater than the target sum, then decrement the right pointer.


	This can be done in O(n) time and O(n) space by using a hash table.
	While scanning the array check the following.
	1. If hash[sum - a[i]] == 1, then print the pair (a[i], x-a[i])
	2. Set hash[a[i]]
	Let us consider the array as 1,3,4,7,9 and the sum to be searched is 7.
	1. if(hash[7-a[0]] == 1? No. Set hash[a[0]]=1, i.e hash[1]=1
	2. if(hash[7-a[1]] == 1? No. Set hash[a[1]]=1, i.e hash[3]=1
	3. if(hash[7-a[2]] == 1? Yes. Print the pair (a[i], sum-a[i]), i.e (4,3)
	4. if(hash[7-a[3]] == 1? No. Set hash[a[3]]=1, i.e hash[7]=1
	5. if(hash[7-a[4]] == 1? No. Set hash[a[4]]=1, i.e hash[9]=1
	In this method, if there are negative number, then we have to add the absolute value of the smallest
	negative number to all the number. 
	If the array has -9,-1,2,3,4,5,8 and target sum is 7.
	Change the array as followy by adding 9 to all numbers.
	So the array becomes, 0,8,11,12,14,15,17. This can be used as index to the hash. 
	But the sum values should be compared with original numbers.

