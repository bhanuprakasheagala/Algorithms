#include <iostream>
#include <vector>

template <typename T>
int mergeAndCount(std::vector<T>& arr, int left, int mid, int right) {
    // Left subarray
    std::vector<T> leftSub(arr.begin()+left, arr.begin()+mid+1);

    // Right subarray
    std::vector<T> rightSub(arr.begin()+mid+1, arr.begin()+right+1);

    int i = 0; // Initial index of the left subarray
    int j = 0; // Initial index of the right subarray
    int k = left; // Initial index of merged subarray
    int invCount = 0;

    // Merge the two sorted subarrays
    while(i < leftSub.size() && j < rightSub.size()) {
        if(leftSub[i] <= rightSub[j]) {
            arr[k++] = leftSub[i++];
        }
        else {
            arr[k++] = rightSub[j++];

            // All the remaining elements in leftSub are greater than rightSub[j]
            invCount += (mid + 1) - (left + i);
        }
    }

    // Copy the remaining elements of leftSub, if any
    while(i < leftSub.size()) {
        arr[k++] = leftSub[i++];
    }

    // Copy the remaining elements of rightSub, if any
    while(j < rightSub.size()) {
        arr[k++] = rightSub[j++];
    }

    return invCount;
}

// Function to count inversions using modified Merge sort
template <typename T>
int countInversions(std::vector<T>& arr, int left, int right) {
    int invCount = 0;
    if(left < right) {
        int mid = left + (right - left)/2;

        // Count the inversions in the left half
        invCount += countInversions(arr, left, mid);

        // Count the inversions in the right half
        invCount += countInversions(arr, mid+1, right);

        // Count split inversions and merge the two halves
        invCount += mergeAndCount(arr, left, mid, right);

    }

    return invCount;
}

int main()
{
    std::vector<int> arr1 = {1, 20, 6, 4, 5};
    int inversionCount1 = countInversions(arr1, 0, arr1.size()-1);
    std::cout << "Number of Inversions in arr1: " << inversionCount1 << '\n';

    std::vector<float> arr2 = {1.75, 9.64, 6.57, 5.32, 4.98};
    int inversionCount2 = countInversions(arr2, 0, arr2.size()-1);
    std::cout << "Number of Inversions in arr2: " << inversionCount2 << '\n';

    return 0;
}