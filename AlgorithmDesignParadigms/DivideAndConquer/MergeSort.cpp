#include <iostream>
#include <vector>

// Template function to merge two sorted arrays
template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create Temporary Arrays
    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    // Copy data to temporary arrays leftArr[] and rightArr[]
    for(int i=0; i<n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for(int j=0; j<n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left...right]
    int i = 0;  // Initial index of leftArr
    int j = 0;  // Initial index of rightArr
    int k = left;   // Initial index of merged subarray

    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i++];
        }
        else {
            arr[k] = rightArr[j++];
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while(i < n1) {
        arr[k++] = leftArr[i++];
    }

    // Copy the remaining elements of rightArr[], if any
    while(j < n2) {
        arr[k++] = rightArr[j++];
    }
}

// Template function for merge sort
template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left)/2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Helper function to print the array
template <typename T>
void printArray(const std::vector<T>& arr) {
    for(const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

int main()
{
    // Example with integers
    std::vector<int> intArr = {38, 27, 43, 3, 9, 82, 18};
    
    std::cout << "Original integer Array: ";
    printArray(intArr);

    mergeSort(intArr, 0, intArr.size()-1);

    std::cout << "Sorted integer Array: ";
    printArray(intArr);


    // Example with floating-point numbers
    std::vector<double> doubleArr = {38.5, 27.1, 43.0, 3.3, 9.9, 82.2, 10.4};

    std::cout << "Original double Array: ";
    printArray(doubleArr);

    mergeSort(doubleArr, 0, doubleArr.size()-1);

    std::cout << "Sorted double Array: ";
    printArray(doubleArr);


    // Example with Strings
    std::vector<std::string> strArr = {"def", "acb", "jkl", "ghi"};
    
    std::cout << "Original String Array: ";
    printArray(strArr);

    mergeSort(strArr, 0, strArr.size()-1);

    std::cout << "Sorted string Array: ";
    printArray(strArr);

    return 0;
}

/*
Notes:

Let's walk through the Merge Sort process with a visual representation at every step using the 
example array `[38, 27, 43, 3, 9, 82, 10]`.

### Original Array
```
[38, 27, 43, 3, 9, 82, 10]
```

### Step 1: Divide the Array

#### First Split
- Split the array into two halves:
```
Left half:  [38, 27, 43]
Right half: [3, 9, 82, 10]
```

#### Further Split
- Recursively split until each subarray contains only one element:

**Left Half `[38, 27, 43]`**
```
Split:      [38, 27]      [43]
Further Split: [38]  [27]
```

**Right Half `[3, 9, 82, 10]`**
```
Split:      [3, 9]      [82, 10]
Further Split: [3]  [9]      [82]  [10]
```

At this point, the array is divided into individual elements:
```
[38] [27] [43] [3] [9] [82] [10]
```

### Step 2: Conquer and Combine (Merge Step)

Now, we'll start merging the elements back together in a sorted order.

#### Merge Step 1: Merge Single Elements into Sorted Pairs

**Merging `[38]` and `[27]`:**
```
[27, 38]
```
**Merging `[3]` and `[9]`:**
```
[3, 9]
```
**Merging `[82]` and `[10]`:**
```
[10, 82]
```

Now, the array looks like this:
```
[27, 38] [43] [3, 9] [10, 82]
```

#### Merge Step 2: Merge Sorted Pairs and Single Elements

**Merging `[27, 38]` and `[43]`:**
```
[27, 38, 43]
```
**Merging `[3, 9]` and `[10, 82]`:**
```
[3, 9, 10, 82]
```

Now, the array looks like this:
```
[27, 38, 43] [3, 9, 10, 82]
```

### Step 3: Final Merge

Finally, merge the two sorted subarrays `[27, 38, 43]` and `[3, 9, 10, 82]`:

**Merging `[27, 38, 43]` and `[3, 9, 10, 82]`:**
```
Compare 27 and 3 → [3]
Compare 27 and 9 → [3, 9]
Compare 27 and 10 → [3, 9, 10]
Compare 27 and 82 → [3, 9, 10, 27]
Compare 38 and 82 → [3, 9, 10, 27, 38]
Compare 43 and 82 → [3, 9, 10, 27, 38, 43]
Add remaining 82 → [3, 9, 10, 27, 38, 43, 82]
```

### Final Sorted Array
```
[3, 9, 10, 27, 38, 43, 82]
```

### Visual Summary of Steps

```
Step 1: Divide
Original Array: [38, 27, 43, 3, 9, 82, 10]
[38, 27, 43]      [3, 9, 82, 10]

Further Split:
[38, 27] [43]      [3, 9] [82, 10]
[38] [27] [43]      [3] [9] [82] [10]

Step 2: Conquer and Combine
Merge Step 1:
[27, 38] [43]      [3, 9] [10, 82]

Merge Step 2:
[27, 38, 43]      [3, 9, 10, 82]

Final Merge:
[3, 9, 10, 27, 38, 43, 82]
```

*/