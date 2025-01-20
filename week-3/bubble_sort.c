#include <stdio.h>
#include <stdlib.h>

void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bubble_sort(int* array, int N)
{
    int opcount = 0;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-i-1; j++)
        {
            opcount++;
            if (array[j] > array[j+1])
            {
                swap(array, j, j+1);
            }
        }
    }
    printf("%d\t%d\n", N, opcount);
}

void printarray(int *array, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main()
{
    // Set a random seed
    srand(42);  // Fixed seed for reproducibility (can be changed)

    // Test with different sizes of arrays
    int sizes[] = {48,444,844,3564,4758,7754,9542};  // Different array sizes to test
    
    for (int k = 0; k < 7; k++)
    {
        int N = sizes[k];
        
        // Dynamically allocate memory for the array
        int *arr = (int*) malloc(N * sizeof(int));

        // Fill the array with random numbers
        for (int i = 0; i < N; i++)
        {
            arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
        }
        bubble_sort(arr, N);
        free(arr);
    }
    
    return 0;
}
