#include <stdio.h>
#include <stdlib.h>

int opcount = 0;
int isSubsetSum(int* array, int N, int sum)
{
    opcount++;
    if (N == 0)
        return 0;
    int totalSum = 0;
    for (int i = 0; i < N; i++)
        totalSum += array[i];
    if(totalSum == sum)
        return 1;
    else
        return isSubsetSum(array, N-1, sum) || isSubsetSum(array, N-1, sum - array[N-1]);
    
}

void partitionProblem(int *array, int N)
{
    opcount = 0;
    int totalSum = 0;
    for (int i = 0; i < N; i++)
    {
        ++opcount;
        totalSum += array[i];
    }
    if (totalSum%2 == 0)
        isSubsetSum(array,N, totalSum/2);
    printf("%d\t%d\n", N, opcount);
}
int main()
{
  // Fixed seed for reproducibility (can be changed)

    // Test with different sizes of arrays
    int sizes[10]; // Different array sizes to test
    for (int i = 1; i < 11; i++)
        sizes[i-1] = 4*i;
    for (int k = 0; k < 10; k++)
    {
        int N = sizes[k];
        
        // Dynamically allocate memory for the array
        int *arr = (int*) malloc(N * sizeof(int));

        // Fill the array with random numbers
        for (int i = 0; i < N; i++)
        {
            arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
        }
        partitionProblem(arr, N);

        free(arr);
    }
}