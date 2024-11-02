#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int* createArray(int size, int random) {
    int* arr = (int*)malloc(size * sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i) {
        arr[0] = random;
    }

    return arr;
}

void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
} 

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
    quickSort(arr, 0, n - 1);

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