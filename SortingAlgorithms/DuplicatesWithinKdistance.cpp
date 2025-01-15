/*
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than the 
size of the array. Write a function that returns true if the array contains duplicates within k distance.

Examples: 
Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.

Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}
Output: true
1 is repeated at distance 3.

Input: k = 3, arr[] = {1, 2, 3, 4, 5}
Output: false

Input: k = 3, arr[] = {1, 2, 3, 4, 4}
Output: true
*/

#include <iostream>
#include <unordered_set>
#include <vector>

bool checkDuplicatesWithinK(const std::vector<int>& arr, int k) {
    std::unordered_set<int> us;
    
    for(int i=0; i < arr.size(); ++i) {
        if(us.find(arr[i]) != us.end()) {
            return true;
        }
        
        us.insert(arr[i]);
        
        if(i >= k) {
            us.erase(arr[i-k]);
        }
    }
    
    return false;
}

int main() {
    
    std::vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    if(checkDuplicatesWithinK(arr, 3)) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }
    
    return 0;
}

/*
Output:
Yes
*/
