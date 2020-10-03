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
    int sd = 0;
    int bd = 0;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (prices[i + 1] > prices[i])
            ++sd;
        else
        {
            profit += prices[sd] - prices[bd];
            bd = sd = i;
        }
    }
    cout << profit;

    return 0;
}