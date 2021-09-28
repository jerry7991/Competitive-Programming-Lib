#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long
#define um unordered_map

using namespace std;

ll dp[20][2];

ll solve(string &str, int n , int tight, int k, um<int, int>&digits, ll nums = 0) {
	if (n == 0) {
		for (auto &x : digits) {
			int v = x.first, cnt = x.second;
			if (v && cnt > 0 && (nums % v) == 0) {
				k--;
			}
		}
		return k <= 0;
	}

	int ub = tight ? (str[str.size() - n] - '0') : 9;

	ll &ans = dp[n][tight];
	if (ans != -1) return ans;
	ans = 0;
	for (int dig = 0; dig <= ub; dig++) {
		digits[dig]++;
		ans += solve(str, n - 1, (tight & (dig == ub)), k, digits, nums * 10 + dig);
		digits[dig]--;
	}
	return ans;
}


int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {

		ll l, r;
		int k;
		cin >> l >> r >> k;
		l--;

		um<int, int> digits;

		string L = to_string(l), R = to_string(r);


		memset(dp, -1, sizeof dp);
		ll resL = solve(L, L.size(), 1, k, digits);
		memset(dp, -1, sizeof dp);
		ll resR = solve(R, R.size(), 1, k, digits);


		cout << (resR - resL) << "\n";
	}
}