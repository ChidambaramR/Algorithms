#include <stdio.h>

typedef enum {false, true} bool;
/*
Returns power of 2 plus 1.
*/
int pow2plus1(int x){
	return ((1<<x)+1);
}

/*
Use dmorgans law. 
~(A uni B) = ~A int ~B
Therefor ~(~A uni ~B) = A int B
In bit language, ~(~A | ~B) = A&B
*/
int bitAnd(int x, int y){
	return ~(~x | ~y);
}


/*
Given a number x, copy its LSB to all the bit positions.
Eg, copyLSB(5) = 0xFFFFFFFF ( all 1's because LSB is 1 )
copyLsb(6) = 0x00000000 ( all 0's because LSB is 0 )
2 Approaches:
1. My approach: Get the number and do a logical and with 1.
	So if the number is 5 (0x0101), logical and results in 1.
	If the result is 1, return ~0
	If the resule is 0, return 0

2. Efficient Approach
	Left shift the number by 31 times. This will make the LSB
	as the MSB. Now right shift the number 31 times.
	Eg: Number 5. 0x0101. Left shift by 31 gives 0x80000000 ( MSB is 1 ).
	i.e the LSB got shifted to the MSB. Now right shift by 31 times.
	On a right shift, the sign bit is extended. 
	Thus if the LSB is 1, it goes to the MSB and due to the MSB extension,
	it fills 1 in all places.
	If LSB is 0, right shifting will only result 0's.
*/

int copyLSB_mine(int x){
	if(x&1)
		return ~0;
	else
		return 0;
}


int copyLSB(int x){
	return ((1<<31)>>31);
}


/*
Return the least set bit position
Two's compliment of a number will give turn on the least significant bit.
i.e If the number is 10, i.e 1010. Its 2's complement is 0110. If we see,
all positions after the least set bit are inverted. Thus a logical and 
will just give the least set bit's position. However this might not directly
give us the position. We have to loop through the resulting number to get the
value.
*/
int least_setbit(int x){
	return (x & (~x + 1))-1;
}

int least_setbit_mine(int x){
	int count=0;
	while(x){
		count++;
		if(x & 1)
			break;
		x = x>>1;
	}
	// Zero indexed
	return count-1;
}

int highest_setbit(int x){
	int count=0;
	while(x){
		count++;
		x = x >> 1;
	}
	// Zero indexed
	return count-1;
}


/*
Checks the sign bit. If the sign bit is 0, return true.
*/
int is_negative(int x){
	return !(x>>31);
}

/*
Returns the absolute value of a number.
*/
int absValue(int x){
	int negmask = x >> 31;
	// Take 1s complement. If positive number this is unchanged
	x = x + negmask;
	return x ^ negmask;
}

/*
x-1 flips the least significant bit to 0
*/
int isPower2(int x){
	return (x & (x-1));
}

/*
Runs only till the number of set bits
*/
int count_setbits(int x){
	int count = 0;
	while(x & (x-1)){
		count++;
		x = x >> 1;
	}
	return count;
}

void print_bin(unsigned int x){
	if(!x)
		return;
		
	print_bin(x>>1);
	printf("%d",x%2);
}

/*
Convert to 1's between MSB and LSB
*/
int convert_to_1(int x){
	int lsb = least_setbit(x);
	int msb = highest_setbit(x);
	int max = ~0;
	
	/*
	The left mask puts all 1's before the highest set bit
	*/
	int left = max - ((1 << (msb+1))-1);
	/*
	The right mask puts all 1's after the least set bit
	*/
	int right = ((1 << lsb)-1);
	/*
	The final mask will have zeros in the bit positions of the number.
	i.e If the number is 00110010, then the mask will be 11000001.
	If we see, the the corresponding bit positions in the mask is turned off.
	Now we and this mask with the number and OR it with the negation of the mask.
	Actually a negation of the mask is sufficient.
	*/
	int mask = left | right;
	
	return ((x&mask) | ~mask);
}

/*
Returns if two numbers have opposite signs.
We XOR both the numbers. If both numbers have the same sign, then the leading
bit in the XOR will be 0. If both numbers have different sign, then the leading
bit in the XOR will be 1. Now we right shift this by 31 and find the MSB is 1 or 0.
*/
bool oppositeSigns(int x, int y){
    return ((x ^ y) >> 31);
}


/*
Find the next highest number with same number of 1's
Source: http://www.slideshare.net/gkumar007/bits-next-higher-presentation
Source: http://www.geeksforgeeks.org/next-higher-number-with-same-number-of-set-bits/
*/



/*
The logic is to right shift all even bits by one position and left shift all odd bits by
one position. 
We can get all the even bits by doing a logical and with 0xAAAAAAAA (i.e 1010 .. 1010). 
We can see that the even bits have 1 and the odd bits have 0.
Similarly we can get all the odd bits by doing a logical and with 0x5555555 (i.e 0101 ... 0101)
We can see that all the odd bits have 1 and the even bits have 0.
*/
int swap_odd_even(unsigned int x){
	int even = x&0xAAAAAAAA;
	int odd = x&0x55555555;
	return ((even>>1) | (odd<<1));
}

int main(){
	printf("Convert: %d",swap_odd_even(58));
	return 0;
}
