/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order)
from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray
is picked and moved to the sorted subarray.

Example:
arr[] = 64 25 12 22 11
Find the minimum element in arr[0...4] and place it at beginning
11 25 12 22 64
Find the minimum element in arr[1...4] and place it at beginning of arr[1...4]
11 12 25 22 64
Find the minimum element in arr[2...4] and place it at beginning of arr[2...4]
11 12 22 25 64
Find the minimum element in arr[3...4] and place it at beginning of arr[3...4]
11 12 22 25 64

*/
#include <iostream>
#include <string>

template <class dataType>
void swap(dataType *left, dataType *right) {
    dataType temp = *left;
    *left = *right;
    *right = temp;
}

template <class dataType>
void selectionSort(dataType arr[], int itemsCount) {
    int i, j, min_index;
    for(i=0; i<itemsCount-1; ++i) {
        min_index = i;
        for(j=i+1; j<itemsCount; ++j) {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[min_index], &arr[i]);
    }
}

int main() {
    int n;
    std::cout << "Enter number of items: ";
    std::cin>>n;

    std::string arr[n];
    std::cout << "The items list? \n";
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    selectionSort(arr, n);

    std::cout << "The Sorted list of items: \n";
    for(int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}
