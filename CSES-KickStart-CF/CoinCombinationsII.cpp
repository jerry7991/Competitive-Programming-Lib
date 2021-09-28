#include<bits/stdc++.h>
using namespace std;


int main() {
	int mod = 1000000007;

	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int &i : v)cin >> i;


	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = (dp[i - 1][j] + (j - v[i - 1] < 0 ? 0 : dp[i][j - v[i - 1]])) % mod;
		}
	}

	cout << dp[n][x] << endl;

	return 0;
}