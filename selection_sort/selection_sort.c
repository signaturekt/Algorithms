#include <stdio.h>
#include <stdlib.h>

int *selection_sort(int *A, int n);

int main() {
    // Init pointer array and assign random numbers in each element
    int size = 5;
    int *A = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        A[i] = rand() % 10;
    }

    // Print unsorted array
    printf("Unsorted Array: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d", A[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("\n");

    
    selection_sort(&*A, size);

    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d", A[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("\n");

    // Free pointer
    free(A);
    return 0;
}

int *selection_sort(int *A, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int smallest = i;
        for (int j = i; j < n; ++j)
        {
            if (A[smallest] > A[j])
            {
                smallest = j;
            }
        }
        int tmp = A[smallest];
        A[smallest] = A[i];
        A[i] = tmp;
    }
    return A;
}