#include <iostream>
#include <vector>

template<typename T>
void printArray(const std::vector<T>& arr, int n) {
    for(int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

template<typename T>
int partition(std::vector<T>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<r; ++j) {
        if(arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[r]);
    return i+1;
}

template<typename T>
void quickSort(std::vector<T>& arr, int l, int r) {
    if(l < r) {
        int pivotPoint = partition(arr, l, r);
        quickSort(arr, l, pivotPoint-1);
        quickSort(arr, pivotPoint+1, r);
    }
}

template<typename T>
void Sort(std::vector<T>& arr, int n) {
    int l = 0;
    int r = n-1;
    quickSort(arr, l, r);
    printArray(arr, n);
}

template<typename T>
void readInputArray(std::vector<T>& arr, int n) {
    for(int i=0; i<n; ++i)
        std::cin >> arr[i];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr1(n);
    std::vector<float> arr2(n);
    readInputArray(arr1, n);
    readInputArray(arr2, n);

    std::cout << "Sorted list(s): \n";
    Sort(arr1, n);
    Sort(arr2, n);
}