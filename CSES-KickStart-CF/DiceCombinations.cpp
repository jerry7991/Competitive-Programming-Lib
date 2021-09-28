#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;



int solve(int n) {
	vector<int> dp(n + 1);
	dp[0] = 0;

	for (int i = 1; i <= n; i++ ) {
		dp[i] = (i <= 6);
		for (int j = 1; j <= 6 && i - j >= 0; j++) {
			dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}
	return dp[n];
}



int main() {
	int n;
	cin >> n;
	cout << solve(n);
}