#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void countsort(string arr[], int exp,int mod,int range,int n)
{
    string ans[n];
    int farr[range] = {0};
    stringstream ss;
    int x;
    for (int i = 0; i < n; ++i)
    {
        
        ++farr[stoi(arr[i],nullptr,10) / exp % mod];
    }
    for (int i = 1; i < range; ++i)
    {
        farr[i] += farr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int pos = farr[stoi(arr[i],nullptr,10)  / exp % mod] - 1;
        ans[pos] = arr[i];
        --farr[stoi(arr[i],nullptr,10)  / exp % mod];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}
void radixsort(string arr[], int n)
{
    countsort(arr,1000000,100,32,n);//days
    countsort(arr,10000,100,13,n);//months
    countsort(arr,1,10000,2501,n);//years
}
int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    radixsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}