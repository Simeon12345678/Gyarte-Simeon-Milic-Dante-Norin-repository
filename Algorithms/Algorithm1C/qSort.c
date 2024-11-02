#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// comparison function due to how qsort is used it requires a comparison function, 
// ie the function compares 2 elements in the array
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// c lacks dynamic arrays so we use this function to simulate the existance of one.
int* createArray(int size, int random) {
    int* arr = (int*)malloc(size * sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i) {
        arr[0] = random;
    }

    return arr;
}

int main() {
    // generates random number for the array
    srand(time(NULL));
    int random = rand() % 1000 + 1;

    // code needed to check execution time
    clock_t start;
    clock_t end;
    double timeUsed;

    start = clock();

    // initialize array of whatever given size
    int arr[1000];
    memcpy(createArray(1000, random), arr, 1000); // memcpy since direct assignement is not allowed

    // length of the array in n 
    int n = sizeof(arr) / sizeof(arr[0]);   

    // the sorting 
    qsort(arr, n, sizeof(int), compare);

    end = clock();
    timeUsed = ((double) (end - start)); // taking the difference of time before and after measured code yields the total time used.

    // displaying everything
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    printf("Time taken: %f seconds", timeUsed);
    return 0;
}