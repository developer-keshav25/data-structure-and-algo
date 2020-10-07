#include <iostream>
#include <bits/stdc++.h>
#include <iomanip> 
using namespace std;

struct Pair
{
    int wt;
    int val;
};

bool cmp(Pair arr1, Pair arr2)
{
    return ((arr1.val / arr1.wt) >= (arr2.val / arr2.wt));
}
int main()
{
    int n;
    cin >> n;
    Pair arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].val;
    }
    int weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].wt;
    }
    std::sort(arr, arr + n, cmp);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].val << " " << arr[i].wt << '\n';
    // }
    int tar;
    cin >> tar;
    int iweight = 0;
    double ival = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (iweight + arr[i].wt <= tar)
        {
            iweight += arr[i].wt;
            ival += arr[i].val;
        }
        else
        {
            int remain = tar - iweight;
            ival += arr[i].val*(static_cast<double>(remain) /(arr[i].wt));
            break;
        }
    }
    // string res = to_string(ival);
    printf("%.2f",ival);
    return 0;
}