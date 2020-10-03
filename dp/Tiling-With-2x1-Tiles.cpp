#include<iostream>
using namespace std;
int main(){
    int l;
    cin>>l;
    int dp[l+1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= l; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[l];

return 0;
}