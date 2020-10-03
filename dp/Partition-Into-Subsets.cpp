#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if(n==0||k==0||n<k){
        cout<<0;
        return 0;
    }
    long dp[k + 1][n + 1];
    for (int j = 1; j <= k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (j == 1 || i == j)
            dp[j][i] = 1;
            else if(i < j)
            {
                dp[j][i] = 0;
            }
            else
            {
                dp[j][i] = j * dp[j][i - 1] + dp[j - 1][i - 1];
            }
        }
    }
    cout<<dp[k][n];
    return 0;
}