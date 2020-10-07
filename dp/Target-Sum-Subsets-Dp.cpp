#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int set[n];
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    int tar;
    cin >> tar;
    int dp[n + 1][tar + 1] = {0};
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < tar + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (j >= set[i - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - set[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    if (dp[n][tar])
        cout << "true";
    else
        cout << "false";
    return 0;
}