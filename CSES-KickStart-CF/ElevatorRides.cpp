#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;

int solve(vector<int>& v, int w) {
	int n = v.size();

	vector<vector<int>> dp(n + 1, vector<int>(w + 1, 30));

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			// ignore
			dp[i][j] = dp[i - 1][j];
			if (v[i] <= j) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			}
		}
	}



}

int main() {
	fastio;
	int n, w;
	cin >> n >> w;
	vector<int> v(n);
	for (int &i : v) cin >> i;
	cout << solve(v, w);
}