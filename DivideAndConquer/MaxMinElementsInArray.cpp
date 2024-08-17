#include <iostream>
#include <vector>
#include <utility>

template <typename T>
std::pair<T, T> findMaxMin(const std::vector<T>& arr, int low, int high) {
    
    // Base class : If the array has only one element
    if(low == high) {
        return {arr[low], arr[high]};
    }

    // If the array has two elements
    if(high == (low+1)) {
        if(arr[low] < arr[high]) {
            return {arr[low], arr[high]};
        }
        else {
            return {arr[high], arr[low]};
        }
    }

    // Divide the array into two halves
    int mid = low + (high - low)/2;
    auto leftResult = findMaxMin(arr, low, mid);
    auto rightResult = findMaxMin(arr, mid+1, high);

    // Combine the results
    T minElement = std::min(leftResult.first, rightResult.first);
    T maxElement = std::max(leftResult.second, rightResult.second);

    return {minElement, maxElement};
}

int main()
{
    std::vector<int> arr1 = {3, 5, 2, 1, -2, 7, -3, 10, 6};

    auto result1 = findMaxMin(arr1, 0, arr1.size()-1);
    std::cout << "Minimum Element: " << result1.first << '\n';
    std::cout << "Maximum Element: " << result1.second << '\n';

    std::vector<std::string> arr2 = {"abc", "abb", "abcd", "ghi", "zyxw"};
    auto result2 = findMaxMin(arr2, 0, arr2.size()-1);
    std::cout << "Minimum Element: " << result2.first << '\n';
    std::cout << "Maximum Element: " << result2.second << '\n';

    return 0;
}