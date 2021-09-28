#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;

vector<int> odds = {1, 3, 5, 7, 9};
vector<int> even = {0, 2, 4, 6, 8};


ll dp[20][2][2][2];

ll solve(string &str, int n, int odd, int tight, int leading ) {
	if (n == 0) {
		return 1;
	}

	ll ans = 0;

	if (dp[n][odd][tight][leading] != -1) {
		return dp[n][odd][tight][leading];
	}

	ll ub = tight ? (str[str.size() - n] - '0') : 9;

	if (odd) {
		if (leading) {
			ans += solve(str, n - 1, odd, 0, 1);
		}
		for (int dig : odds) {
			if (dig <= ub)
				ans += solve(str, n - 1, 0, (tight & (dig == ub)), 0);
		}
	} else {
		for (int dig : even) {
			if (dig <= ub)
				ans += solve(str, n - 1, 1, (tight & (dig == ub)), 0);
		}
	}
	return dp[n][odd][tight][leading] = ans;
}

ll solve(string &l, string &r) {
	memset(dp, -1, sizeof dp);
	ll r_res = solve(r, r.size(), 1, 1, 1);
	memset(dp, -1, sizeof dp);
	ll l_res = solve(l, l.size(), 1, 1, 1);
	return (r_res - l_res);
}

int main() {
	fastio;
	int t;
	cin >> t;
	int i = 1;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		string lft = to_string(l - 1), rht = to_string(r);
		cout << "Case #" << i++ << ": " << solve(lft, rht) << "\n";
	}
}