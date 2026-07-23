#include <iostream>
#include <vector>
#include <utility> // For std::swap

// Rearranges the array elements around a chosen pivot
int partition(std::vector<int>& arr, int low, int high) {
    // Selecting the last element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element (tracks the boundary of smaller elements)
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; 
            std::swap(arr[i], arr[j]);
        }
    }
    // Place the pivot in its correct sorted position
    std::swap(arr[i + 1], arr[high]);
    
    // Return the final index of the pivot
    return i + 1; 
}

// Main recursive function that executes Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    // Base case: If low is less than high, the subarray has elements to sort
    if (low < high) {
        // Find the pivot index such that elements are correctly partitioned
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before the pivot
        quickSort(arr, low, pivotIndex - 1);

        // Recursively sort elements after the pivot
        quickSort(arr, pivotIndex + 1, high);
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
    std::vector<int> data = {19, 7, 15, 12, 3, 22, 10};
    
    std::cout << "Original array: ";
    printArray(data);

    quickSort(data, 0, data.size() - 1);

    std::cout << "Sorted array:   ";
    printArray(data);

    return 0;
}
