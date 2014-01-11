#include <stdio.h>
#define N 10

typedef enum {false, true} bool;

bool find_nextSquare(int a[][10], int *row, int *column){
	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(a[i][j] == 0){
				*row = i;
				*column = j;
				return true;
			}
		}
	}
	return false;
}


bool check_square(int a[][10], int row, int col, int num){
	int i,j;
	int Boxrow, Boxcol;
	
	/* 
	Check if the number is already present in this row
	*/
	for(col=0; col<N; col++)
		if(a[row][col] == num)
			return false;

	/*
	Check if the number is already present in this column
	*/
	for(row=0; row<N; row++)
		if(a[row][col] == num)
			return false;

	/*
	Check if the box has already this number
	If the square we have put is 0,4, then we have to check the box corresponding to it.
		In a 10*10 grid, box size is of 3. i.e 0,1,2 | 3,4,5 | 6,7,8
	*/
	Boxrow = row - row%3;
	Boxcol = col - col%3;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			if(a[i+Boxrow][j+Boxcol] == num)
				return false;

	// The number was not found anywhere in its row, in its column as well as in its box
	return true;
}


bool sudoku(int a[][10]){
	int row=0, column=0;
	int num=0;
	
	/*
	Base case. If we cant find any sqaure, then it means we have filled all the
	squares and hence we can return true.
	*/
	if(!find_nextSquare(a, &row, &column)){
		return true;
	}

	for(num=1; num<=9; num++){
		if(check_square(a, row, column, num)){
			a[row][column] = num;
		
		if(sudoku(a))
			return true;
	
		//Failure case
		a[row][column] = 0;
		}
	}

	// We ended up with a failure case
	return false;
	
}

/* A utility function to print grid  */
void printGrid(int grid[N][N])
{
    int row, col;
    for (row = 0; row < N; row++)
    {
       for (col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

int main(){
	   int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
        	              {5, 2, 0, 0, 0, 0, 0, 0, 0},
                	      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      	      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      	      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      	      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                              {1, 3, 0, 0, 0, 0, 2, 5, 0},
                              {0, 0, 0, 0, 0, 0, 0, 7, 4},
                              {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	    if (sudoku(grid) == true)
        	  printGrid(grid);
    	    else
         	  printf("No solution exists");

	return 0;
}
