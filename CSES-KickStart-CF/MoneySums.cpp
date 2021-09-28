#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums, int i, unordered_set<int>& dp, int val = 0) {
	if (i == nums.size()) {
		if (val) {
			dp.insert(val);
		}
		return;
	}
	solve(nums, i + 1, dp, val + nums[i]);
	solve(nums, i + 1, dp, val);
}

void solve(vector<int>& nums) {
	int n = nums.size();

	int max_n = 1000 * n;

	vector<vector<bool>> dp(n + 1, vector<bool>(max_n + 1, false));
	dp[0][0] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= max_n; j++) {
			// one possibility will always in hand that we don't consider current i-th to make j
			dp[i][j] = dp[i - 1][j];
			// what if we consider
			int last = j - nums[i - 1];// what was the answer of last
			dp[i][j] = dp[i][j] || (last >= 0 && dp[i - 1][last]);
		}
	}

	vector<int> res;
	for (int i = 0; i <= max_n; i++) {
		if (i && dp[n][i]) res.push_back(i);
	}

	cout << res.size() << "\n";
	for (int &i : res) cout << i << " ";
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v) cin >> i;
	solve(v);
}