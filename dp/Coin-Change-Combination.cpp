#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int tar;
    cin >> tar;
    int dp[tar + 1] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < tar+1; j++)
        {
            if(j>=coins[i]){
                dp[j] += dp[j-coins[i]];
            }
        }
        
    }
    
    cout<<dp[tar];
    return 0;
}