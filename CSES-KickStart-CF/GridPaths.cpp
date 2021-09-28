#include<bits/stdc++.h>
using namespace std;



int solve(vector<string>& grid) {
	int n = grid.size();
	int mod = 1000000007;

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		dp[i][0] = (grid[i][0] != '*' && (i == 0 || dp[i - 1][0]));
		dp[0][i] = (grid[0][i] != '*' && (i == 0 || dp[0][i - 1]));
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (grid[i][j] == '*') {
				dp[i][j] = 0;
			} else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	}
	return dp[n - 1][n - 1];
}

int main() {
	int n;
	cin >> n;
	vector<string> grid(n);
	for (auto &x : grid) {
		cin >> x;
	}
	cout << solve(grid);
}