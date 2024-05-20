#include <iostream>
#include <vector>

template<typename T>
void insertionSort(std::vector<T>& arr, int n) {
    int i;
    T key;
    for(int j=1; j<n; ++j) {
        key = arr[j];
        i = j-1;
        while(i>=0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i -= 1;
        }
        arr[i+1] = key;
    }
    for(int k=0; k<n; ++k) {
        std::cout << arr[k] << " ";
    }
    std::cout << '\n';
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr1(n);
    for(int i=0; i<n; ++i){
        std::cin >> arr1[i];
    }
    insertionSort(arr1, n);

    std::vector<float> arr2(n);
    for(int i=0; i<n; ++i){
        std::cin >> arr2[i];
    }
    insertionSort(arr2, n);
    return 0;
}