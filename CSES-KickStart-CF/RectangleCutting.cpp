#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int solve(int l, int w) {
	if (l == w) {
		return 0;
	}

	int ans = INT_MAX;
	if (dp[l][w] != -1) return dp[l][w];

	// Let's cut vertical
	for (int i = 1; i < w; i++) {
		ans = min(ans, 1 + solve(l, i) + solve(l, w - i));
	}

	// Let's cut horizontal
	for (int i = 1; i < l; i++) {
		ans = min(ans, 1 + solve(i, w) + solve(l - i, w));
	}
	return dp[l][w] = ans;

}

int solveDp(int l, int w) {
	vector<vector<int>> dp(l + 1, vector<int>(w + 1, 0));

	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			if (i == j) continue;
			dp[i][j] = INT_MAX;
			//vertical cut
			for (int k = 1; k < j; k++) {
				dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
			}

			// horizontal cut
			for (int k = 1; k < i; k++) {
				dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
			}
		}
	}
	return dp[l][w];
}

int main() {
	int a, b;
	cin >> a >> b;

	memset(dp, -1, sizeof dp);
	cout << solveDp(a, b);
}