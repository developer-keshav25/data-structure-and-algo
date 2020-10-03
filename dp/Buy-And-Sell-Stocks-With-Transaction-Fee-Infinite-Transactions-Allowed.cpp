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
    int fee;
    cin >> fee;
    int bsp = -prices[0];
    int ssp = 0;
    for (int i = 1; i < n; i++)
    {
        int nbsp = 0;
        int nssp = 0;

        if (ssp - prices[i] > bsp)
        {
            nbsp = ssp - prices[i];
        }
        else{
            nbsp = bsp;
        }
        if (prices[i] + bsp - fee > ssp)
        {
            nssp = prices[i] + bsp - fee;
        }
        else{
            nssp = ssp;
        }
        bsp = nbsp;
        ssp = nssp; 
    }

    cout << ssp;
    return 0;
}