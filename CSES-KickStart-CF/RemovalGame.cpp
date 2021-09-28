#include<bits/stdc++.h>
#define fastio 	ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007

using namespace std;


long solve(vector<long>& v) {
	long n = v.size();

	vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));
	long sum = 0;
	for (long i = 1; i <= n; i++) sum += v[i - 1];

	for (long l = n - 1; l >= 0; l--) {
		for (long r = l; r < n; r++ ) {
			if (l == r) {
				dp[l][r] = v[l];
			} else {
				dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
			}
		}
	}
	return (sum + dp[0][n - 1]) / 2;
}

int main() {
	fastio

	long n;
	cin >> n;
	vector<long> v(n);
	for (long &i : v) cin >> i;
	cout << solve(v) << "\n";
}