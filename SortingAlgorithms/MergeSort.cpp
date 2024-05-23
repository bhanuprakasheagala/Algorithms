#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T>& arr, int low, int mid, int high) {
    int m = mid - low + 1;
    int n = high - mid;

    std::vector<T> L(m);
    std::vector<T> R(n);

    for(int i=0; i<m; ++i)
        L[i] = arr[low+i];
    for(int j=0; j<n; ++j)
        R[j] = arr[mid+1+j];
    
    int i=0, j=0, k=low;
    while(i<m && j<n) {
        if(L[i] <= R[j]) {
            arr[k] = L[i++];
        }
        else {
            arr[k] = R[j++];
        }
        k++;
    }
    while(i < m) {
        arr[k++] = L[i++];
    }
    while(j < n) {
        arr[k++] = R[j++];
    }
}

template<typename T>
void mergeSort(std::vector<T>& arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

template<typename T>
void Sort(std::vector<T>& arr, int n) {
    int l = 0;
    int r = n-1;
    mergeSort(arr, l, r);
    for(int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
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
    Sort(arr1, n);
    Sort(arr2, n);
}