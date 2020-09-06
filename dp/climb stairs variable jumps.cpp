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
	dp[n] =1;
	for (int i = n-1; i >= 0; i--) {
	    for (int j = 1; j < jumps[i]+1&&i+j<n+1; j++) {
	        dp[i] += dp[i+j];
	    }
	}
	std::cout << dp[0] << std::endl;
	return 0;
}
