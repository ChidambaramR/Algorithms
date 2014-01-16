#include <stdio.h>
#include <stdlib.h>

int main(){
	int rows = 4;
	int columns = 8;
	int i;

	/*
	Normal version of malloc where, malloc is called many times.
	*/
	int **a = (int**)malloc(sizeof(int*) * rows);
	for(i=0; i<rows; i++)
		a[i] = (int*)malloc(sizeof(int) * columns);

	/*
	The above version can be optimized. We dont need so many malloc's
	for allocating memory for the column types.
	*/
	int header = rows * sizeof(int*);
	int data = rows * columns * sizeof(int);
	int **b = (int**)malloc(header + data);
	int *buf = (int*)(b + rows);
	int k;
	for(k=0; k<rows; k++){
		b[k] = buf + k*columns;
	}
	return 0;
}
