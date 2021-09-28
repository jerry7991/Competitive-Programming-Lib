#include <bits/stdc++.h>
using namespace std;

long long dp[100001][101];

int solve(vector<int> &v, int m) {
	int n = v.size();
	int mod = 1000000007;
	if (v[0] == 0) {
		fill(dp[0], dp[0] + 101, 1);
	} else {
		dp[0][v[0]] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (v[i]) {
			dp[i][v[i]] += dp[i - 1][v[i]];
			if (v[i] - 1 > 0) {
				dp[i][v[i]] += dp[i - 1][v[i] - 1];
			}
			if (v[i] + 1 <= m) {
				dp[i][v[i]] += dp[i - 1][v[i] + 1];
			}
			dp[i][v[i]] %= mod;
		} else {
			for (int j = 1; j <= m; j++) {
				dp[i][j] += dp[i - 1][j];
				if (j - 1 > 0)dp[i][j] += dp[i - 1][j - 1];
				if (j + 1 <= m)dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}
		}
	}


	long long ans = 0;
	for (int i = 1; i <= m; i++) ans = (ans + dp[n - 1][i]) % mod;
	return ans;

}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int &i : v)cin >> i;
	cout << solve(v, m);
}