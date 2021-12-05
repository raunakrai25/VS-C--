#include <bits/stdc++.h>
using namespace std;

int a,b,c,i,j,k,n,u,v,ne=1;
int mini, mincost=0, cost[9][9], parent[9];

int find(int);
int uni(int,int);



int main(){
    cout << "Enter no of vertex : ";
    cin >> n;
    cout << "Enter cost matrix : ";
    for (i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> cost[i][j];
            if (cost[i][j] == 0){
                cost[i][j] = 999;
            }
        }
    }
    cout << "The min cost of spanning tree : ";
    while (ne<n){
        for(i=1,mini=999; i<=n; i++){
            for(j=1; i<=n; j++){
                if (cost[i][j]<mini){
                    mini = cost[i][j];
                    a=u=i;
                    b=v=j;
                }

            }
        }
        u = find(u);
        v = find(v);
        if (uni(u,v)){
            cout << "\n" << ne++ << " edge (" << a << "," << b << ") = "<<mini ;
            mincost += mini;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << "the minimum cost is :" << mincost;
   
}

int find(int i){
    while (parent[i])
    i = parent[i];
    return i;
}

int uni(int i, int j){
    if (i != j){
        parent[j] = i;
        return 1;
    }
    return 0;
}