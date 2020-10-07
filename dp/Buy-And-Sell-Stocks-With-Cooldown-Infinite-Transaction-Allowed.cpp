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
    int bsp = -prices[0];
    int ssp = 0;
    int csp = 0;
    for (int i = 1; i < n; i++)
    {
        int nbsp = 0;
        int nssp = 0;
        int ncsp = 0;

        if (csp - prices[i] > bsp)
        {
            nbsp = csp - prices[i];
        }
        else{
            nbsp = bsp;
        }
        if (prices[i] + bsp > ssp)
        {
            nssp = prices[i] + bsp;
        }
        else{
            nssp = ssp;
        }
        if(ssp>csp){
            ncsp = ssp;
        }
        else{
            ncsp = csp;
        }
        csp = ncsp;
        bsp = nbsp;
        ssp = nssp; 
    }

    cout << ssp;
    return 0;
}