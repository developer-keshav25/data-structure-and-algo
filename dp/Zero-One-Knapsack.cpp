#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    int tar;
    cin >> tar;
    int dp[n + 1][tar + 1] = {};//initialise a 2d array with 0

    for (int item = 1; item < n + 1; item++)
    {
        for (int j = 1; j < tar + 1; j++)
        {
            dp[item][j] = dp[item - 1][j];
            if (j >= weight[item - 1])
            {
                dp[item][j] = std::max(dp[item][j], dp[item - 1][j - weight[item - 1]] + price[item - 1]);
            }
        }
    }
    cout << dp[n][tar];
    return 0;
}