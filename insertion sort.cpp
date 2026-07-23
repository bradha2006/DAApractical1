#include <iostream>
#include <vector>

// Function to perform insertion sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element to be positioned
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Place the key at its correct location
        arr[j + 1] = key;
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
    std::vector<int> data = {12, 11, 13, 5, 6};
    
    std::cout << "Original array: ";
    printArray(data);

    insertionSort(data);

    std::cout << "Sorted array:   ";
    printArray(data);

    return 0;
}
