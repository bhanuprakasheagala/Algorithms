/*
Find the index of the first occurrence of a key in a sorted array.
Input: A sorted array of integers (possibly with duplicates) and an integer q.
Output: Index of the first occurrence of q in the array or “−1” if q does not appear in the array.

Input:
7
2 4 4 4 7 7 9
4
9 4 5 2

Output:
6 1 -1 0

key 9 -> first occurance found at index 6
key 4 -> first occurance found at index 1
key 5 -> not present, hence return -1
key 2 -> first occurance found at index 0

*/

#include <iostream>
#include <vector>

int BsearchWithDuplicates(const std::vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    int middle;
    while(left <= right) {
        middle = left + (right - left)/2;
        if(arr[middle] == key) {
            if(middle == 0 || arr[middle] != arr[middle - 1]) {
                return middle;
            }
            else {
                right = middle - 1;
            }
        }
        else if(arr[middle] < key) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i){
        std::cin >> arr[i];
    }
    int m;
    std::cin >> m;
    std::vector<int> keys(m);
    for(int i=0; i<m; ++i) {
        std::cin >> keys[i];
    }
    int i = 0;
    while(i < m) {
        std::cout << BsearchWithDuplicates(arr, keys[i]) << " ";
        i++;
    }
    std::cout << '\n';

    return 0;
}