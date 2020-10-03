#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    int lsf = INT_MAX;
    int op = 0;
    int pist = 0;
    for (int i = 0; i < n; i++)
    {
        if (prices[i] < lsf)
        {
            lsf = prices[i];
        }
        int pist = prices[i] - lsf;
        if (pist > op)
        {
            op = pist;
        }
    }
    cout << op;

    return 0;
}