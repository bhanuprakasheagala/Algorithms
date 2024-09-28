# Sorting Algorithms

This section provides implementations and explanations for various **Sorting Algorithms**. Sorting algorithms are essential for efficient data organization and are widely used in computer science for searching, data analysis, and more.

Each sorting algorithm covered here includes an overview, time complexity analysis, space complexity, algorithm steps, example usage, and code implementation in **C++**. The algorithms are divided into **Comparison-based Sorting** and **Non-Comparison Sorting** techniques.

---

## Table of Contents
1. [Bubble Sort](#bubble-sort)
2. [Selection Sort](#selection-sort)
3. [Insertion Sort](#insertion-sort)
4. [Merge Sort](#merge-sort)
5. [Quick Sort](#quick-sort)
6. [Heap Sort](#heap-sort)
7. [Radix Sort](#radix-sort)
8. [Bucket Sort](#bucket-sort)
9. [Counting Sort](#counting-sort)

---

### 1. Bubble Sort

#### Overview
Bubble Sort is a simple comparison-based algorithm where adjacent elements are repeatedly swapped if they are in the wrong order. Despite its simplicity, Bubble Sort is inefficient for large datasets.

#### Algorithm Steps
1. Iterate through the array.
2. Compare each pair of adjacent elements.
3. Swap if the first element is greater than the second.
4. Repeat the process for the remaining elements.

#### Time Complexity
- **Best Case**: O(n) (already sorted)
- **Average Case**: O(n²)
- **Worst Case**: O(n²)

#### Space Complexity
- O(1) (In-place sorting)

#### Example
Consider the array: [5, 1, 4, 2, 8]
- After the first pass: [1, 4, 2, 5, 8]
- After the second pass: [1, 2, 4, 5, 8]

#### Code Implementation (C++)
```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

---

### 2. Selection Sort

#### Overview
Selection Sort works by repeatedly selecting the smallest (or largest) element from the unsorted part of the array and swapping it with the first unsorted element.

#### Algorithm Steps
1. Find the minimum element in the unsorted array.
2. Swap it with the first unsorted element.
3. Move the boundary of the sorted part of the array by one element.
4. Repeat until the entire array is sorted.

#### Time Complexity
- **Best Case**: O(n²)
- **Average Case**: O(n²)
- **Worst Case**: O(n²)

#### Space Complexity
- O(1)

#### Example
Consider the array: [64, 25, 12, 22, 11]
- First pass: [11, 25, 12, 22, 64]
- Second pass: [11, 12, 25, 22, 64]

#### Code Implementation (C++)
```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
```

---

### 3. Insertion Sort

#### Overview
Insertion Sort builds the sorted array one element at a time. It is much more efficient than Bubble and Selection Sort for small datasets and nearly sorted arrays.

#### Algorithm Steps
1. Start with the second element.
2. Compare it with elements before it and insert it in the correct position.
3. Repeat the process for all elements.

#### Time Complexity
- **Best Case**: O(n) (nearly sorted)
- **Average Case**: O(n²)
- **Worst Case**: O(n²)

#### Space Complexity
- O(1)

#### Example
Consider the array: [12, 11, 13, 5, 6]
- After inserting 11: [11, 12, 13, 5, 6]
- After inserting 5: [5, 11, 12, 13, 6]

#### Code Implementation (C++)
```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

---

### 4. Merge Sort

#### Overview
Merge Sort is an efficient, stable, and divide-and-conquer sorting algorithm. It divides the array into halves, sorts each half recursively, and then merges the sorted halves.

#### Algorithm Steps
1. Divide the array into two halves.
2. Sort each half recursively.
3. Merge the two sorted halves into one sorted array.

#### Time Complexity
- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n)

#### Space Complexity
- O(n)

#### Example
Array: [12, 11, 13, 5, 6, 7]
- After dividing: [12, 11, 13] and [5, 6, 7]
- After sorting: [11, 12, 13] and [5, 6, 7]
- After merging: [5, 6, 7, 11, 12, 13]

#### Code Implementation (C++)
```cpp
void merge(int arr[], int left, int mid, int right) {
    // Code to merge two sorted subarrays
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

---

### 5. Quick Sort

#### Overview
Quick Sort is a fast, in-place sorting algorithm that uses a pivot to partition the array into two halves and then sorts each half recursively.

#### Algorithm Steps
1. Choose a pivot element.
2. Partition the array such that elements less than the pivot go to the left and greater to the right.
3. Recursively apply the same process to each partition.

#### Time Complexity
- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n²)

#### Space Complexity
- O(log n) (recursive stack)

#### Example
Array: [10, 80, 30, 90, 40, 50, 70]
- After partitioning with pivot 50: [10, 30, 40, 50, 90, 80, 70]
- Recursively sort left and right halves.

#### Code Implementation (C++)
```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

### 6. Heap Sort

#### Overview
Heap Sort is a comparison-based sorting technique based on Binary Heap data structure. It works by creating a max heap, then repeatedly extracting the largest element and reducing the heap size.

#### Algorithm Steps
1. Build a max heap from the input data.
2. Swap the first (largest) element with the last element.
3. Reduce the heap size and heapify the root.
4. Repeat the process for the reduced heap until the entire array is sorted.

#### Time Complexity
- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n)

#### Space Complexity
- O(1) (in-place sorting)

#### Example
Consider the array: [12, 11, 13, 5, 6, 7]
- After building a max heap: [13, 11, 12, 5, 6, 7]
- After swapping: [7, 11, 12, 5, 6, 13]
- After heapifying: [12, 11, 7, 5, 6, 13]

#### Code Implementation (C++)
```cpp
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```

---

### 7. Radix Sort

#### Overview
Radix Sort is a non-comparison-based sorting algorithm that works by sorting numbers digit by digit, starting from the least significant digit to the most significant one, using a stable sorting algorithm (like Counting Sort).

#### Algorithm Steps
1. Find the maximum number in the array to determine the number of digits.
2. Perform counting sort for each digit, starting from the least significant digit to the most significant.

#### Time Complexity
- **Best Case**: O(nk) where `k` is the number of digits.
- **Average Case**: O(nk)
- **Worst Case**: O(nk)

#### Space Complexity
- O(n + k)

#### Example
Consider the array: [170, 45, 75, 90, 802, 24, 2, 66]
- After sorting by the least significant digit: [170, 90, 802, 2, 24, 45, 75, 66]
- After sorting by the next digit: [802, 2, 24, 45, 66, 75, 170, 90]

#### Code Implementation (C++)
```cpp
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = *std::max_element(arr, arr + n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}
```

---

### 8. Bucket Sort

#### Overview
Bucket Sort is a non-comparison-based sorting algorithm that works by distributing elements into a number of buckets, sorting each bucket individually, and then combining the sorted buckets.

#### Algorithm Steps
1. Create `n` empty buckets.
2. Place each element in its corresponding bucket.
3. Sort individual buckets (using Insertion Sort or any other stable sort).
4. Concatenate the sorted buckets to get the final sorted array.

#### Time Complexity
- **Best Case**: O(n + k)
- **Average Case**: O(n + k)
- **Worst Case**: O(n²) (when all elements fall into one bucket)

#### Space Complexity
- O(n + k)

#### Example
Consider the array: [0.42, 0.32, 0.52, 0.12, 0.25, 0.78, 0.92, 0.68]
- After distributing into buckets: [[0.12, 0.25], [0.32, 0.42], [], [0.52, 0.68], [], [0.78, 0.92]]
- After sorting individual buckets and concatenating: [0.12, 0.25, 0.32, 0.42, 0.52, 0.68, 0.78, 0.92]

#### Code Implementation (C++)
```cpp
void bucketSort(float arr[], int n) {
    std::vector<float> bucket[n];

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        bucket[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        std::sort(bucket[i].begin(), bucket[i].end());

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < bucket[i].size(); j++) {
            arr[idx++] = bucket[i][j];
        }
    }
}
```

---

### 9. Counting Sort

#### Overview
Counting Sort is a non-comparison-based sorting algorithm that works by counting the occurrences of each unique element. It is effective when the range of the input data is small compared to the number of elements.

#### Algorithm Steps
1. Find the range of the input data (maximum and minimum values).
2. Create a count array to store the count of each unique element.
3. Modify the count array by adding the previous counts.
4. Build the output array by placing elements at their correct positions.

#### Time Complexity
- **Best Case**: O(n + k) where `k` is the range of the input.
- **Average Case**: O(n + k)
- **Worst Case**: O(n + k)

#### Space Complexity
- O(n + k)

#### Example
Consider the array: [4, 2, 2, 8, 3, 3, 1]
- Count array after counting: [1, 2, 2, 1, 1]
- After cumulative addition: [1, 3, 5, 6, 7]
- Sorted output: [1, 2, 2, 3, 3, 4, 8]

#### Code Implementation (C++)
```cpp
void countingSort(int arr[], int n) {
    int max = *std::max_element(arr, arr + n);
    int count[max + 1] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
```

---

## Conclusion

This repository covers multiple sorting algorithms, each with distinct advantages and trade-offs. Choose the right sorting algorithm based on the dataset size, nature of the data, and time or space constraints.