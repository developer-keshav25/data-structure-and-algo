#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int* countsort(int arr[],int max,int min,int n){
int range = max-min+1;
int *farr = new int[range];
for (int i = 0; i < n; ++i)
{
    int idx = arr[i]-min;
    ++farr[idx]; 
}
for (int i = 1; i <range; ++i)
{
    farr[i] = farr[i]+farr[i-1];
}
int *ans= new int[n];
for (int i = n-1; i>=0; i--)
{
    int val = arr[i];
    int pos = farr[val-min];
    int idx = pos-1;
    ans[idx] = val;
    --farr[val-min];
}
return ans;
// for (int i = 0; i < n; i++)
// {
//     arr[i] = ans[i];
// }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int min = INT_MAX;
    int max  =INT_MIN;
    for (int i = 0; i < n; i++)
    {
        min = std::min(min,arr[i]);
        max = std::max(max,arr[i]);
    }
    int* x= countsort(arr,max,min,n);
    for (int i = 0; i < n; i++)
    {
        cout<<x[i]<<endl;
    }
       
return 0;
}