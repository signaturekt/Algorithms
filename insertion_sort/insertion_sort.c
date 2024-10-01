#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 5

void insertion_sort(int *A, int n);

int main() {
    srand(time(NULL));
    // Init pointer array and assign random numbers in each element
    int *A = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        A[i] = rand() % 25;
    }

    // Print unsorted array
    printf("Unsorted Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d", A[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n");

    
    insertion_sort(&*A, size);

    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d", A[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // Free pointer
    free(A);
    return 0;
}

void insertion_sort(int *A, int n) {
    for(int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
    }
}