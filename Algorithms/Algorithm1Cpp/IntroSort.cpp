#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <chrono>

// generates a pseudorandom number using rand function
int random(int n) {
    return rand() % (n + 1);
} 

// creates a dynamic array of n size with random in bound elements for the sortering
std::vector<int> createArray(int size) {
    std::vector<int> array(size);
    for (int i = 0; i < array.size(); ++i) {
        array.at(i) = random(1000);
    }
    return array;
}

void swapVal(int* a, int* b) {
    int* temp = a;
    a = b;
    b = temp;
    return;
}

void insertionSort(int arr[], int* begin, int* end) {
    int left = begin - arr;
    int right = end - arr;

    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + i]  = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    return;
}

int* partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[1 + i], arr[high]);
    return (arr + i + 1);
}

// function used to find middle value of pointed by pointers a, b and c
// not the best implementation but it will have to do.
int* medianOfThree(int* a, int* b, int* c) {
    if (*a < *b && *b < *c) 
        return (b); 
  
    if (*a < *c && *c <= *b) 
        return (c); 
  
    if (*b <= *a && *a < *c) 
        return (a); 
  
    if (*b < *c && *c <= *a) 
        return (c); 
  
    if (*c <= *a && *a < *b) 
        return (a); 
  
    if (*c <= *b && *b <= *a) 
        return (b);     
}

void introSortUtil(int arr[], int* begin, int* end, int depthLimit) {
    int size = end - begin;

    if (size < 16) {
        insertionSort(arr, begin, end);
        return;
    }

    if (depthLimit == 0) {
        std::make_heap(begin, end + 1);
        std::sort_heap(begin, end + 1);
        return; 
    }

    int* pivot = medianOfThree(begin, begin + size/2, end);

    swapVal(pivot, end);
    int* partitionPoint = partition(arr, begin - arr, end - arr);
    introSortUtil(arr, begin, partitionPoint - 1, depthLimit - 1);
    introSortUtil(arr, partitionPoint + 1, end, depthLimit - 1);

    return;
}

void introSort(int arr[], int* begin, int* end) {
    int depthLimit = 2 * std::log(end - begin);

    introSortUtil(arr, begin, end, depthLimit);
    return;
}

int main() {
    // timer start
    auto start = std::chrono::high_resolution_clock::now();
    // initialize array of whatever given size
    std::vector<int> arr = createArray(1000); // switch during testing

    int convertedArray[1000]; // switch during testing

    std::copy(arr.begin(), arr.end(), convertedArray);
    // the sorting
    int n = sizeof(convertedArray) / sizeof(convertedArray[0]);
    introSort(convertedArray, convertedArray, convertedArray + n - 1);

    auto end = std::chrono::high_resolution_clock::now();
    // timer end
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // delta time
    std::cout << "Time taken: " << duration << "ms" << std::endl;
    // print the array
    std::cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << " " << arr[i] << " ";
    }
    return 0;
}   