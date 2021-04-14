// code edited by: Edward Cruz
// Discreet Mathematics (MATH-2305-N01)
#include<iostream>

// main source for merge sort algorithm code:
// https://www.geeksforgeeks.org/merge-sort/
// date found: 4/13/2021
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

 
    // Merge the temp arrays back into array[left..right]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = left;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// the merge sort that calls the actual merge recursively as shown in the psuedo code in the book (section 5.4.4)
void mergeSort(int array[],int left,int right){
    if(left >= right) {
        return; // returns recursively
    }
    
    int mid = left + (right-left) / 2;
    
    mergeSort(array, left ,mid);    // merges the left side
    mergeSort(array, mid+1, right); // merges the right side
    merge(array, left, mid, right); // puts it all together
}

// function to print array so i dont have to make a for loop every time.
void printarray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
}

// test/demo for mergeSort()
int main () {
    int a[10] = {5, 50, 92, 33, 24, 86, 14, 53, 76, 46}; // test list
    int aSize = sizeof(a) / sizeof(a[0]);                // size of test list

    std::cout << "\nThe array unsorted is: " << std::endl;
    printarray(a, aSize);   // prints the array to console

    std::cout << "\n\nThe array after being sorted is: " << std::endl;
    mergeSort(a, 0, aSize-1);   // calls the merge sort function and does its magic
    printarray(a, aSize);   // prints the array to console
    std::cout << "\n\n" << std::endl;   // just to tidy up output
    
    return 0;
}