#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
	vector<int> dp(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		dp[i] = INT_MAX;
		while (j) {
			int r = j % 10;
			j /= 10;
			if (r)
				dp[i] = min(dp[i], 1 + dp[i - r]);
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << solve(n);
}