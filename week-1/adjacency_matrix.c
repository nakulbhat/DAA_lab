#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Enter number of Vertices\n");
	int N;
	scanf("%d",&N);
	int mat[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mat[i][j] = 0;
		}
	}
	printf("Enter the edges. Enter 0 and 0 to exit.\n");
	int x = 1, y = 1;
	while(x != 0 && y != 0){
		printf("Enter one vertex\n");
		scanf("%d",&x);
		printf("Enter other vertex\n");
		scanf("%d",&y);
		mat[x-1][y-1] = 1;
		mat[y-1][x-1] = 1;
	}

	printf("Printing matrix\n");
		for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d  ", mat[j][i]);
		}
		printf("\n");
	}
	return 0;
}