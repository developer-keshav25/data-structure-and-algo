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
    int min_buy = prices[0];
    int profit1[n] = {0};
    int profit2[n] = {0};
    int transactions = 1;
    for (int i = 1; i < n; i++)
    {
        if (min_buy > prices[i])
        {
            min_buy = prices[i];
        }
        profit1[i] = std::max(prices[i] - min_buy, profit1[i - 1]);
    }
    int max_sell = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (max_sell < prices[i])
        {
            max_sell = prices[i];
        }
        profit2[i] = std::max(max_sell - prices[i], profit2[i + 1]);
    }
    int op = 0;
    for (int i = 0; i < n; i++)
    {
        if(op<profit1[i]+profit2[i]){
            op = profit1[i]+profit2[i];
        }
    }
    cout<<op;
    return 0;
}