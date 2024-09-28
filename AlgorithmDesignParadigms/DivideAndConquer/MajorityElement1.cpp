/*
Majority Element Problem
Check whether a given sequence of numbers contains an element that appears more than half of the times.
Input: A sequence of n integers.
Output: 1, if there is an element that is repeated more than n/2 times, and 0 otherwise.
Input format: The first line contains an integer n, the next one contains a sequence of n
non-negative integers. a0,...,an−1.
Outputformat: Output 1 if the sequence contains an element that appears more than n/2 times, and 0 otherwise.

*/
#include <iostream>
#include <vector>

int findMajorityElement(std::vector<int>& nums) {
    int candidate = nums[0]; // Assume that the first element as the candidate majority element
    int count = 1; // Initialize the count of occurrences of the candidate as 1

    // Find the candidate with the required count
    for(int i=1; i<nums.size(); ++i) {

        // If the current element matches the candidate, increment the count
        if(nums[i] == candidate) {
            count++;
        }
        // else, decrement the count
        else {
            count--;
        }

        // If the count becomes 0, update the candidate to the current element
        // and reset the count to 1
        if(count == 0) {
            candidate = nums[i];
            count = 1;
        }
    }

    // Candidate may contain the majority element, but we need to verify it 
    count = 0;
    for(int n : nums) {  // Count the occurrence of candidate in the entire sequence
        if(n == candidate) {
            count++;
        }
    }

    // If the count is greater than n/2, then candidate is the majority element
    if(count > (nums.size())/2) {
        return 1;
    }
    // Else, No majority element
    else {
        return 0;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i<n; ++i) {
        std::cin >> nums[i];
    }
    std::cout << findMajorityElement(nums) << '\n';

    return 0;
}