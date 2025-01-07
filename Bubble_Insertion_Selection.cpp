#include <iostream>
#include <vector>
#include <algorithm>

// Function to display an array
void displayArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Bubble Sort
void bubbleSort(std::vector<int> arr) {
    std::cout << "Bubble Sort:" << std::endl;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    displayArray(arr);
}

// Insertion Sort
void insertionSort(std::vector<int> arr) {
    std::cout << "Insertion Sort:" << std::endl;
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
    displayArray(arr);
}

// Selection Sort
void selectionSort(std::vector<int> arr) {
    std::cout << "Selection Sort:" << std::endl;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
    displayArray(arr);
}

int main() {
    std::vector<int> arr;
    int n;

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        arr.push_back(num);
    }

    std::cout << "\nOriginal Array: ";
    displayArray(arr);

    // Perform Bubble Sort
    bubbleSort(arr);

    // Perform Insertion Sort
    insertionSort(arr);

    // Perform Selection Sort
    selectionSort(arr);

    return 0;
}
