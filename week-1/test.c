#include<stdio.h>
int main(int argc, char const *argv[])
{
    int N=5;
    int mat[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mat[i][j] = 0;
		}
	}
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < N; k++)
        {
            mat[i][k] = 1;
        }
        
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
