#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int piv = arr[high];
    int i = (low-1);

    for (int j=low; j<=high; j++){
        if(arr[j]<piv){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low , high);
    quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
        
    }
}

void print(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i];
    }
}

int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quicksort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    print(arr, n); 
    return 0; 
} 