#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student record
struct Student {
    char name[50];
    int rollNo;
    char department[50];
};

// Function prototypes
void mergeSort(struct Student arr[], int low, int high);
void merge(struct Student arr[], int low, int mid, int high);
void quickSort(struct Student arr[], int low, int high);
int partition(struct Student arr[], int low, int high);
void binarySearch(struct Student arr[], int n, char key[]);
void printStudent(struct Student student);

int main() {
    FILE *file;
    char filename[] = "students.txt";
    struct Student students[100]; // Assuming maximum 100 students
    int choice, numStudents = 0, i;
    char searchName[50];

    // Read student records from the file
    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file %s.\n", filename);
        return 1;
    }
    while(fscanf(file, "%s %d %s", students[numStudents].name, &students[numStudents].rollNo, students[numStudents].department) != EOF) {
        numStudents++;
    }
    fclose(file);

    do {
        // Diplay Menu
        printf("\nOptions:\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Binary Search\n");
        printf("4. Quit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                mergeSort(students, 0, numStudents-1);
                printf("Sorted using Merge Sort:\n");
                for(int i=0; i<numStudents; ++i) {
                    printStudent(students[i]);
                }
                break;
            }
            case 2: {
                quickSort(students, 0, numStudents-1);
                printf("Sorted using Quick Sort:\n");
                for(int i=0; i<numStudents; ++i) {
                    printStudent(students[i]);
                }
                break;
            }
            case 3: {
                printf("Enter student name to search: ");
                scanf("%s", searchName);
                binarySearch(students, numStudents, searchName);
                break;
            }
            case 4: {
                printf("Quitting the program...\n");
                break;
            }
            default:
                printf("Invalid choice. Please enter again.\n");
        }

    } while(choice != 4);

    return 0;
}

// Function to print student record
void printStudent(struct Student student) {
    printf("Name: %s, RollNumber: %d, Department: %s\n", student.name, student.rollNo, student.department);
}

// Merge Sort functions

void mergeSort(struct Student arr[], int low, int high) {
    if(low < high) {
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(struct Student arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    struct Student L[n1], R[n2];
    int i, j, k;

    for(i=0; i<n1; ++i) {
        L[i] = arr[low + i];
    }
    for(j=0; j<n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }
    
    i = j = 0;
    k = low;
    while(i<n1 && j<n2) {
        if(strcmp(L[i].name, R[j].name) < 0 || strcmp(L[i].name, R[j].name) == 0 && (L[i].rollNo < R[j].rollNo)) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Quick sort functions
void quickSort(struct Student arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
int partition(struct Student arr[], int low, int high) {
    struct Student pivot = arr[high];
    int i = low - 1, j;
    struct Student temp;
    
    for(j=low; j<high; ++j) {
        if(strcmp(arr[j].name, pivot.name) < 0 || strcmp(arr[j].name, pivot.name) == 0 && arr[j].rollNo < pivot.rollNo) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return (i+1);
}

// Binary Search function
void binarySearch(struct Student arr[], int n, char key[]) {
    int left = 0, right = n-1, found = 0;
    while(left <= right) {
        int mid = left + (right - left)/2;
        if(strcmp(arr[mid].name, key) == 0) {
            printStudent(arr[mid]);
            found = 1;
            break;
        }
        else if(strcmp(arr[mid].name, key) < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
    if(!found) {
        printf("Student record not found.\n");
    }
}