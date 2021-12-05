#include<bits/stdc++.h>
using namespace std;

int main (){
    int n;
    float m,outp;
    cout << "Enter the Value Of n :";
    cin >> n;
    cout << "\nEnter Maximum Capacity : ";
    cin >> m;
    float profit[n], weight[n];
    float x[n];
    float result[n];

    cout << "\nEnter the values Of Profit and Weight : ";
    for (int i=0; i<n; i++){
        cout<<"\nEnter The Profit "<<i+1<<" :";
        cin >> profit[i];
        cout << "\nEnter the Weight "<<i+1<<" :";
        cin >> weight[i];
    }

    for (int i=0; i<n; i++){
        result[i] = profit[i]/weight[i];
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (result[i]>result[j]){
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;

                int temp1 = profit[i];
                profit[i] = profit[j];
                profit[j] = temp1;

                int temp2 = weight[i];
                weight[i] = weight[j];
                weight[j] = temp2;
            }
        }
    }

    for (int i=0; i<n; i++){
        if (m == 0){
            break;
        }
        else if (m>=weight[i]){
            m = m - weight[i];
            x[i] = 1;
        }
        else{
            x[i] = m/weight[i];
            m = 0;
        }
    }

    for (int i=0; i<n; i++){
        outp = outp + (x[i]*profit[i]);
    }

    cout << "\nthe Optimal solution would be : "<<outp;

    return 0;
}