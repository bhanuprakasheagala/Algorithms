/*
Given an array of size n, find the majority element (the element that appears more than n/2 times) using Divide and Conquer

Divide the array into two halves.
Conquer each half by recursively finding the majority element.
Combine the results from the two halves:
If both halves agree on the majority element, return it.
If they disagree, count the occurrences of both candidates in the original array and return the one that appears
more frequently.
*/

#include <iostream>
#include <vector>

// Helper function to count the occurrences of a candidate element in a range
int countOccurrences(const std::vector<int>& arr, int left, int right, int candidate) {
    int count = 0;
    for(int i=left; i<=right; ++i) {
        if(arr[i] == candidate) {
            count++;
        }
    }

    return count;
}

int findMajorityElement(const std::vector<int>& arr, int left, int right) {
    // Base case: If the subarray has only one element, return that element
    if(left == right) {
        return arr[left];
    }

    // Divide the array into two halves
    int mid = left + (right - left)/2;

    // Recursively find majority elements in the left and right halves
    int leftMajority = findMajorityElement(arr, left, mid);
    int rightMajority = findMajorityElement(arr, mid+1, right);

    // If both halves return the same majority element, return it
    if(leftMajority == rightMajority) {
        return leftMajority;
    }

    // Otherwise, count the occurrences of each candidate in the original array
    int leftCount = countOccurrences(arr, left, right, leftMajority);
    int rightCount = countOccurrences(arr, left, right, rightMajority);

    // Return the element that appears more frequently
    return (leftCount > rightCount) ? leftMajority : rightMajority;
}

int main() {
    
    std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2, 1, 1, 1};
    int result = findMajorityElement(arr, 0, arr.size()-1);

    std::cout << "The majority element is: " << result << '\n';

    return 0;
}
