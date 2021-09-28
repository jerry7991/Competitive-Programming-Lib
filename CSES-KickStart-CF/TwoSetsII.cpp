#include<bits/stdc++.h>
#define fastio 	ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007

using namespace std;

long long offset = 0;


//	Didn't work
long long solve(long long i, long long n, long long w, vector<vector<long long>>& dp) {
	if (i > n) {
		return w == 0;
	}

	long long ans = 0;
	if (dp[i][w + offset] != -1) {
		return dp[i][w + offset];
	}

	ans = (ans + solve(i + 1, n, w + i, dp)) % mod;
	ans = (ans + solve(i + 1, n, w - i, dp)) % mod;
	return dp[i][w + offset] = ans;
}

long long solve(long long n) {
	long long w = (n * (n + 1)) / 2;

	if (w & 1) return 0;

	w /= 2;


	vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, 0));

	dp[0][0] = 1;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			// we don't include it
			dp[i][j] = dp[i - 1][j];
			if (j - i >= 0) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
			}
		}
	}
	return dp[n][w];
}

int main() {
	fastio
	int n;
	cin >> n;
	cout << solve(n) << "\n";
}