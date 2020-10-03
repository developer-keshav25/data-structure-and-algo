#include<iostream>
using namespace std;
int main(){
int n;cin>>n;
int arr[n];
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
int inc[n],exc[n];
inc[0] = arr[0];
exc[0] = 0;
for (int i = 1; i < n; i++)
{
    inc[i] = arr[i]+exc[i-1];
    exc[i] = std::max(inc[i-1],exc[i-1]);
}
cout<<inc[n-1];
return 0;
}