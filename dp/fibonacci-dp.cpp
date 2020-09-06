#include <iostream>
using namespace std;
int fibonacci(int n,int dp[]){
    if (n==0||n==1)
    return n;
    if (dp[n]>0)
    return dp[n];
    dp[n] = fibonacci(n-1,dp)+ fibonacci(n-2,dp);
    return dp[n];
}
int main() {
	int n;
	cin>>n;
	int dp[n+1];
	for (int i = 0; i < n+1; i++) {
	    dp[i] = 0;
	}
	cout<<fibonacci(n,dp);
	return 0;
}
