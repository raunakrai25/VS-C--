#include<bits/stdc++.h>
using namespace std;


merge(int arr[], int low, int mid, int upper ){
    int i = low;
    int j = mid+1;
    int k = low;
    int arr1[upper];
    while((i<=mid) && (j<=upper)){
        if (arr[i]<arr[j]){
            arr1[k] = arr[i];
            i++;
        }
        else{
            arr1[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i>mid){
        while(j<=upper){
            arr1[k] = arr[j];
            k++;
            j++;
        }
    }
    else{
        while (i<=mid){
            arr1[k] = arr[i];
            i++;
            k++;
        }
    }
    for (int a=low; a<=upper; a++)
    {
        arr[a] = arr1[a];
    }
    
}

void mergesort (int arr[], int low, int upper){
    if (low<upper){
        int mid = (low+upper)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,upper);
        merge(arr, low, mid, upper);
    }
}


void display(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << ", ";
    }
}

int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    mergesort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    display(arr, n); 
    return 0; 
} 