#include <iostream>
using namespace std;
int climb_stairs(int n,int dp[]){
    if(n==0)
    return 1;
    else if(n<0)
    return 0;
    if(dp[n]>0)
    return dp[n];
    int sum = 0;
    for(int i=1;i<4;i++){
        sum+=climb_stairs(n-i,dp);
    }
    dp[n] = sum;
    return sum;
}
int main() {
	int n;
	std::cin >> n;
	int dp[n+1];
	for (int i = 0; i < n+1; i++) {
	    dp[i] = 0;
	}
	std::cout << climb_stairs(n,dp) << std::endl;
	return 0;
}
