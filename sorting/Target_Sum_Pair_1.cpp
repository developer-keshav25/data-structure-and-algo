#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
void TSP(int arr[],int n,int tar){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]>tar)
        --j;
        else if(arr[i]+arr[j]<tar)
        ++i;
        else{
            cout<<arr[i]<<", "<<arr[j]<<endl;
            ++i;
            --j;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
    std::sort(arr,arr+n);
    TSP(arr,n,tar);  
return 0;
}