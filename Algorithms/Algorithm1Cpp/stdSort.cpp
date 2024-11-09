#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <ctime>

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

int main() {
    // timer start
    auto start = std::chrono::high_resolution_clock::now();
    // initialize array of whatever given size
    std::vector<int> arr = createArray(1000);
    // the sorting
    std::sort(arr.begin(), arr.end());

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