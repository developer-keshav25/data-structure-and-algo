#include <iostream>
using namespace std;
int main() {
	int n;
	std::cin >> n;
	int jumps[n];
	for (int i = 0; i < n; i++) {
	    cin>>jumps[i];
	}
	int dp[n+1];
	for (int i = 0; i < n+1; i++) {
	    dp[i] = 0;
	}
	dp[n] =0;
	for (int i = n-1; i >= 0; i--) {
	    int min = 1000;
	    for (int j = 1; j < jumps[i]+1&&i+j<n+1; j++) {
	        if (dp[i+j]<min)
	        min = dp[i+j];
	    }
	dp[i] = min+1;
	    
	}
	std::cout << dp[0] << std::endl;
	return 0;
}
