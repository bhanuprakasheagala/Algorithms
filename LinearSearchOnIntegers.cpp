#include <iostream>
#include <vector>

int linearSearch(const std::vector<int> arr, int n, int key) {
    for(int i=0; i<n; ++i) {
        if(arr[i] == key) {
            return i+1;
        }
    }
    return 0;
}

int main() {
    int n;
    int key;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Enter the element to be searched: ";
    std::cin >> key;
    int key_pos = linearSearch(arr, n, key);
    if(key_pos) {
        std::cout << "Element found at position " << key_pos << '\n';
    }
    else {
        std::cout << key << " not present in the given elements\n";
    }
}
