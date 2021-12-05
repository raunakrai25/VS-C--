#include <bits/stdc++.h>
using namespace std;

void subset (int arr[] , int n, vector<int>v, int sum){
    if (sum == 0){
        for(auto i:v){
            cout << i << ", ";
        }
        cout << endl;
        return;
    }
    if (n == 0){
        return;
    }

    subset(arr,n-1,v,sum);
    v.push_back(arr[n-1]);
    subset(arr,n-1,v,sum-arr[n-1]);

}

void Display(int arr[], int n, int sum){
    vector<int>v;
    subset(arr,n,v,sum);
}

int main(){

    int n;
    cout << "Enter the total number of array elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter array Elements : ";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int sum;
    cout << "Enter Sum Value : ";
    cin >> sum;

    Display(arr,n,sum);

    return 0;
}
