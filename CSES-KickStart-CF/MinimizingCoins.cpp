#include<bits/stdc++.h>
using namespace std;



int solve(vector<int>& arr, int k) {

	if (k == 0) {
		return 0;
	}

	int ans = INT_MAX;
	for (int i : arr) {
		if (i <= k)
			ans = min(ans, 1 + solve(arr, k - i));
	}
	return ans;
}


long solveDp(vector<int> &arr, int k) {
	vector<long> dp(k + 1);

	sort(arr.begin(), arr.end());

	dp[0] = 0;

	for (long i = 1; i <= k; i++) {
		dp[i] = INT_MAX;

		for (long j : arr) {
			if (j > i) break;
			dp[i] = min(dp[i], 1 + dp[i - j]);
		}
	}
	return dp[k] == INT_MAX ? -1 : dp[k];
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << solveDp(v, k);
}