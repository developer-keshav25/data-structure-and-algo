#include<iostream>
using namespace std;
int main(){
int n;cin>>n;
int price[n];
for (int i = 0; i < n; i++)
{
    cin>>price[i];
}
int weight[n];
for (int i = 0; i < n; i++)
{
    cin>>weight[i];
}
int tar;cin>>tar;
int dp[tar+1] = {0};
for (int i = 1; i <tar+1 ; i++)
{
    for (int item=0;item<n;item++)
    {
        if(i>=weight[item]){
            dp[i] =std::max(dp[i],price[item]+dp[i-weight[item]]);
        }
    }
    
}
cout<<dp[tar];
return 0;
}