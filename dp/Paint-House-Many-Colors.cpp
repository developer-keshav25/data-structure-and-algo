#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n][k];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int cost[n][k];
    for (int i = 0; i < k; i++)
    {
        cost[0][i] = arr[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int min = INT_MAX;
            for (int c = 0; c < k; c++)
            {
                if(c!=j){
                    min = std::min(min,cost[i-1][c]);
                }
            }
            
            cost[i][j] = arr[i][j] + min;
        }
        
    }
    cout<<*std::min_element(cost[n-1],cost[n-1]+k);
    
return 0;
}