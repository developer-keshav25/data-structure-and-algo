#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void countsort(int arr[], int exp, int n)
{
    int *ans = new int[n];
    int farr[10] = {0};
    for (int i = 0; i < n; ++i)
    {
        ++farr[arr[i] / exp % 10];
    }
    for (int i = 1; i < 10; ++i)
    {
        farr[i] += farr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int pos = farr[arr[i] / exp % 10] - 1;
        ans[pos] = arr[i];
        --farr[arr[i] / exp % 10];
    }
    cout<<"After sorting on "<<exp<<" place -> ";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
        arr[i] = ans[i];
    }
    cout<<endl;
}
void radixsort(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max = std::max(max, arr[i]);
    }
    int exp = 1;
    while (exp <= max)
    {
        countsort(arr, exp, n);
        exp *= 10;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    radixsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}