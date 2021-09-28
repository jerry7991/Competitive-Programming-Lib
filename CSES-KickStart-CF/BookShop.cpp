#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& pr, vector<int> &pg, int x, int n) {
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= pr[i - 1]) {
				dp[i][j] = max(dp[i][j], pg[i - 1] + dp[i - 1][j - pr[i - 1]]);
			}
		}
	}
	return dp[n][x];
}

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> pr(n), pg(n);
	for (int &i : pr)cin >> i;
	for (int &i : pg)cin >> i;
	cout << solve(pr, pg, x, n);
}