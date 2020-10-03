#include<iostream>
using namespace std;
int main(){
int n;cin>>n;
int red[n],blue[n],green[n];
for (int i = 0; i < n; i++)
{
    cin>>red[i]>>blue[i]>>green[i];
}
int cost1[n],cost2[n],cost3[n];
cost1[0] = red[0];
cost2[0] = blue[0];
cost3[0] = green[0];
for (int i = 1; i < n; i++)
{
    cost1[i] = std::min(cost2[i-1],cost3[i-1])+ red[i];
    cost2[i] = std::min(cost1[i-1],cost3[i-1])+ blue[i];
    cost3[i] = std::min(cost1[i-1],cost2[i-1])+ green[i];
}
cout<<std::min(cost1[n-1],std::min(cost3[n-1],cost2[n-1]));

return 0;
}