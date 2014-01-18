#include <stdio.h>

typedef enum {false, true} bool;

bool find(int a[][4], int M, int N, int elem){
	int row = 0, col = N-1;

	while(row < M && col >= 0){
		if(a[row][col] == elem)
			return true;
		else if(a[row][col] > elem)
			col--;
		else
			row++;
	}

	//Elem not found
	return false;
}


int main(){
	int a[3][4] = { {1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
			};
	if(find(a, 3, 4, 19)){
		printf("Element found\n");
	}
	else
		printf("Element not found\n");
	return 0;
}
