#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// generates a pseudorandom number using the mersine twister algorithm 
template<typename T>
T random(T rangeFrom, T rangeTo) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution distribute(rangeFrom, rangeTo);
    return distribute(generator);
}

// creates a dynamic array of n size with random in bound elements for the sortering
std::vector<int> createArray(int size, int random) {
    std::vector<int> array(size);
    for (int i = 0; i < array.size(); ++i) {
        array.at(i) = random;
    }
    return array;
}

int main() {
    // timer start
    auto start = std::chrono::high_resolution_clock::now();
    // initialize array of whatever given size
    std::vector<int> arr = createArray(1000, random(0, 1000));
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