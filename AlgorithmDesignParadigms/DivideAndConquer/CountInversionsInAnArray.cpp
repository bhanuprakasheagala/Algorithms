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

/*
Notes:

This program implements an efficient algorithm to count the number of inversions in an array using a modified merge sort.
An inversion is defined as a pair of indices (i, j) such that (i < j) and (A[i] > A[j]). The merge sort algorithm is ideal 
for this task because it naturally divides the array into smaller subarrays, sorts them, and counts inversions as it merges 
the sorted subarrays back together. By leveraging the divide-and-conquer approach, the program is able to count inversions 
in O(nlogn) time, making it much more efficient than the naive O(n^2) approach.

The program works by recursively splitting the array into two halves, counting inversions in each half, and then counting
split inversions (inversions that involve elements from both halves) during the merge process. During merging, if an element
in the right subarray is smaller than an element in the left subarray, this indicates that all remaining elements in the left
subarray are also greater, contributing to the inversion count. The program updates the inversion count in a single step for
these cases, ensuring that the overall algorithm remains efficient while accurately counting all inversions in the array.

Example
For the array [1, 20, 6, 4, 5]:

Split:
Left half: [1, 20, 6]
Right half: [4, 5]

Merge and Count:
Merging [1, 20, 6] results in [1, 6, 20] with 2 inversions (20 > 6).
Merging [1, 6, 20] and [4, 5] results in [1, 4, 5, 6, 20] with 3 more inversions (6 > 4, 6 > 5, and 20 > 5).

Total Inversions: The total number of inversions is 5.
*/