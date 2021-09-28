#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;

ll dp[180][20][2];

ll solve(string &str, int n, int tight, ll sum) {
	if (n == 0) {
		return sum;
	}

	if (dp[sum][n][tight] != -1) return dp[sum][n][tight];

	ll ans = 0;

	int ub = tight ? (str[str.size() - n] - '0') : 9;
	for (int i = 0; i <= ub; i++) {
		ans += solve(str, n - 1, (tight & (i == ub)), sum + i);
	}
	return dp[sum][n][tight] = ans;
}

ll solve(string &l, string &r) {
	memset(dp, -1, sizeof dp);
	ll right =  solve(r, r.size(), 1, 0);
	memset(dp, -1, sizeof dp);
	ll left = solve(l, l.size(), 1, 0);
	return (right - left);
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		string lft = to_string(l - 1);
		string rht = to_string(r);
		cout << solve(lft, rht) << "\n";
	}
}