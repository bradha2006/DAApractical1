#include <iostream>
#include <vector>

// Merges two sorted subarrays of arr[].
// First subarray is arr[low..mid]
// Second subarray is arr[mid+1..high]
void merge(std::vector<int>& arr, int low, int mid, int high) {
    std::vector<int> temp; // Temporary vector to store merged elements
    int left = low;        // Starting index for left subarray
    int right = mid + 1;   // Starting index for right subarray

    // Compare elements from both halves and push the smaller element
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from the left subarray, if any
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from the right subarray, if any
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Transfer sorted elements from temp back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Main function that implements Merge Sort recursively
void mergeSort(std::vector<int>& arr, int low, int high) {
    // Base Case: If the subarray has 0 or 1 element, it is already sorted
    if (low >= high) return;

    // Calculate midpoint safely to avoid integer overflow
    int mid = low + (high - low) / 2;

    // Sort the left and right halves recursively
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge the sorted halves
    merge(arr, low, mid, high);
}

// Helper function to print the vector elements
void printVector(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {38, 27, 43, 3, 9, 82, 10};
    
    std::cout << "Original array: ";
    printVector(data);

    // Run merge sort on the entire vector
    mergeSort(data, 0, data.size() - 1);

    std::cout << "Sorted array:   ";
    printVector(data);

    return 0;
}
