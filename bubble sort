#include <iostream>
#include <vector>

// Function to perform optimized Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    
    // Outer loop for each pass
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        
        // Inner loop to compare adjacent elements
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements using built-in std::swap
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no two elements were swapped in the inner loop, break
        if (!swapped) {
            break;
        }
    }
}

// Helper function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Unsorted array: ";
    printArray(data);
    
    bubbleSort(data);
    
    std::cout << "Sorted array: ";
    printArray(data);
    
    return 0;
}
