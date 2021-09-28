#include <bits/stdc++.h>

using namespace std;



int main() {
	int mod = 1000000007;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<int> nums(n);
	for (int &i : nums) cin >> i;

	vector<int> dp(x + 1);
	dp[0] = 1;
	sort(nums.begin(), nums.end());

	for (int i = 1; i <= x; i++) {
		dp[i] = 0;
		for (int &j : nums) {
			if (i - j < 0) break;
			dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}
	cout << dp[x];
}