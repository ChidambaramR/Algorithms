#include <stdio.h>

int arena[20][20];

// Recurisve logic
int path(int x, int y, int xmax, int ymax){
	int result = 0;

	// We have hit the destination
	if(x == xmax && y == ymax)
		return 1;

	// We can go in right direction
	if(x < xmax)
		result += path(x+1, y, xmax, ymax);

	// We can go in down direction
	if(y < ymax)
		result += path(x, y+1, xmax, ymax);

	// We are backtracking
	return result;
}

// DP Logic	
int path_DP(int x, int y){
	int i,j;
	arena[0][0] = 0;

	for(i=0; i<x; i++)
		arena[i][0] = 1;
	for(j=0; j<y; j++)
		arena[0][j] = 1;

	for(i=1; i<x; i++){
		for(j=1; j<y; j++){
			arena[i][j] = arena[i-1][j] + arena[i][j-1];
		}
	}

	return arena[x-1][y-1];
}


int main(){
 	int m,n;
  	printf("Enter m, n: ");
  	scanf("%d %d",&m,&n);
  	printf("No of paths: %d \n",path(0, 0, m, n));
  	printf("No of paths(DP): %d \n",path_DP(m+1, n+1));
  	return 0;
}
