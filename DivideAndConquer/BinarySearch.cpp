#include <iostream>
#include <vector>

int Bsearch(const std::vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    int middle;
    while(left <= right) {
        middle = left + (right - left)/2;
        if(arr[middle] == key) {
            return middle;
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

int main() {
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
        std::cout << Bsearch(arr, keys[i]) << " ";
        i++;
    }
    std::cout << '\n';
    return 0;
}