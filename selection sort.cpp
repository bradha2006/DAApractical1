#include <iostream>
#include <utility> // Required for std::swap

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    // Loop through the entire array except the last element
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // Track the index of the minimum element
        
        // Scan the unsorted portion to find the true minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index if a smaller element is found
            }
        }
        
        // Swap the found minimum element with the first unsorted element
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int n = sizeof(data) / sizeof(data[0]);
    
    std::cout << "Original array: ";
    printArray(data, n);
    
    selectionSort(data, n);
    
    std::cout << "Sorted array:   ";
    printArray(data, n);
    
    return 0;
}
