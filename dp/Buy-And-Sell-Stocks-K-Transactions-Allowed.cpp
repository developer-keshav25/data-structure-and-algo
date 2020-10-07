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
    int k;
    cin >> k;
    int dp[k + 1][n + 1];
    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                int maxe = 0;
                for (int x = 1; x < j; x++)
                {
                    if(dp[i-1][x]+prices[j-1]-prices[x-1]>maxe)
                    maxe = dp[i-1][x]+prices[j-1]-prices[x-1];
                }
                
                dp[i][j] = std::max(dp[i - 1][j], maxe);
            }
        }
    }

    cout << dp[k][n];
    return 0;
}