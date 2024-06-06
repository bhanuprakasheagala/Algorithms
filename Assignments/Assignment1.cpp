#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int rollNo;
    std::string department;
};

void printStudent(const Student& student) {
    std::cout << "Name: " << student.name << '\n';
    std::cout << "RollNo: " << student.rollNo << '\n';
    std::cout << "Department: " << student.department << '\n';
}

void quickMerge(std::vector<Student>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<Student> L(arr.begin() + low, arr.begin() + mid + 1);
    std::vector<Student> R(arr.begin() + mid + 1, arr.begin() + high + 1);

    int i=0, j=0, k = low;
    while(i < n1 && j < n2) {
        if(L[i].name < R[j].name || (L[i].name == R[j].name && L[i].rollNo < R[j].rollNo)) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while(i < n1) {
        arr[k++] = L[i++];
    }
    while(j < n2) {
        arr[k++] = R[j++];
    }
}
void mergeSort(std::vector<Student>& arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        quickMerge(arr, low, mid, high);
    }
}


int quickPartition(std::vector<Student>& arr, int low, int high) {
    Student pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; ++j) {
        if(arr[j].name < pivot.name || (arr[j].name == pivot.name && arr[j].rollNo < pivot.rollNo)) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);

    return i+1;
}
void quickSort(std::vector<Student>& arr, int low, int high) {
    if(low < high) {
        int pi = quickPartition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void binarySearch(const std::vector<Student>& arr, int n, const std::string& key) {
    int left = 0, right = n-1, found = 0;
    while(left <= right) {
        int mid = left + (right - left)/2;
        if((arr[mid].name).compare(key) == 0) {
            printStudent(arr[mid]);
            found = 1;
            break;
        }
        else if((arr[mid].name).compare(key) < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if(!found) {
        std::cout << "Student record not found\n";
    }
}

int main() {

    std::ifstream file("students.txt");
    if(!file.is_open()) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    std::vector<Student> students;
    Student temp;

    // Read student records from the file
    while(file >> temp.name >> temp.rollNo >> temp.department) {
        students.push_back(temp);

    }

    file.close();

    int choice;
    std::string searchName;

    do {
        // Display Menu
        std::cout << "\nOptions: \n1. Merge Sort\n2. Quick Sort\n3. Binary Search\n4. Quit\nEnter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                mergeSort(students, 0, students.size()-1);
                std::cout << "Sorted using Merge Sort: \n";
                for(int i=0; i<students.size()-1; ++i) {
                    printStudent(students[i]);
                }
                break;
            }
            case 2: {
                quickSort(students, 0, students.size()-1);
                std::cout << "Sorted using Quick Sort: \n";
                for(int i=0; i<students.size()-1; ++i) {
                    printStudent(students[i]);
                }
                break;
            }
            case 3: {
                std::cout << "Enter Student name to search: ";
                std::cin >> searchName;
                binarySearch(students,students.size()-1, searchName);
                break;
            }
            case 4: {
                std::cout << "Quitting the program....\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Enter again: ";
        }
    } while(choice != 4);

    return 0;
}