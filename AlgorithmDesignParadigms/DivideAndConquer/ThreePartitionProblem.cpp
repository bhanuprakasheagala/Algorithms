#include <iostream>
#include <vector>
#include <numeric>

bool canPartitionIntoThreeSubsets(std::vector<int>& nums, int index, int currentSum, int target, int count) {
    // Base case: if we have formed 3 subsets
    if (count == 3) {
        return true;
    }
    
    // Base case: if the current sum reaches the target
    if (currentSum == target) {
        // Start forming the next subset
        return canPartitionIntoThreeSubsets(nums, 0, 0, target, count + 1);
    }

    // Try adding more numbers to the current subset
    for (int i = index; i < nums.size(); i++) {
        if (currentSum + nums[i] <= target) {
            // Choose the number
            int num = nums[i];
            nums[i] = -1; // Mark the number as used
            if (canPartitionIntoThreeSubsets(nums, i + 1, currentSum + num, target, count)) {
                return true;
            }
            // Backtrack
            nums[i] = num; // Unmark the number
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    
    // Check if total sum is divisible by 3
    if (totalSum % 3 != 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    int target = totalSum / 3;

    // Start the recursive backtracking
    if (canPartitionIntoThreeSubsets(nums, 0, 0, target, 0)) {
        std::cout << 1 << '\n';
    } else {
        std::cout << 0 << '\n';
    }

    return 0;
}