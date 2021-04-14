#include<iostream>

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

void mergeSort(int array[],int left,int right){
    if(left >= right) {
        return;//returns recursively
    }
    
    int mid = left + (right-left) / 2;
    
    mergeSort(array, left ,mid);
    mergeSort(array, mid+1, right);
    merge(array, left, mid, right);
}

void printarray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
}

int main () {
    int a[10] = {5, 50, 92, 33, 24, 86, 14, 53, 76, 46};
    int aSize = sizeof(a) / sizeof(a[0]);

    std::cout << "The array unsorted is: " << std::endl;
    printarray(a, aSize);

    std::cout << "\n\nThe array after being sorted is: " << std::endl;
    mergeSort(a, 0, aSize-1);
    printarray(a, aSize);

    return 0;
}