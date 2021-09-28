#include<bits/stdc++.h>
#define fastio 	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007ss

using namespace std;

int solve(vector<int>& v) {
	int n = v.size();

	/**
	Worst
	vector<int> dp(n);
	dp[0] = 1;
	int mx = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
		mx = max(mx, dp[i]);
	}
	return mx;
	**/

	vector<int> dp;

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(dp.begin(), dp.end(), v[i]);
		if (it == dp.end()) {
			dp.push_back(v[i]);
		} else {
			*it = v[i];
		}
	}
	return dp.size();
}

int main() {
	fastio;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v)cin >> i;
	cout << solve(v);
}