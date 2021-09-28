#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;

ll dp[20][10][2][2];

ll solve(string &str, int n, int tight, int last, int leadingZero) {
	if (n == 0) {
		return 1;
	}

	if (last != -1 && dp[n][last][tight][leadingZero] != -1) {
		return dp[n][last][tight][leadingZero];
	}

	int ub = tight ? (str[str.size() - n] - '0') : 9;

	ll ans = 0;

	for (int i = 0; i <= ub; i++) {
		if (i == last && leadingZero == 0) continue;
		ans += solve(str, n - 1, (tight & (i == ub)), i, (leadingZero & (i == 0)));
	}
	return dp[n][last][tight][leadingZero] = ans;
}

ll solve(string & left, string & right) {
	memset(dp, -1, sizeof dp);
	ll lft = solve(left, left.size(), 1, -1, 1);
	memset(dp, -1, sizeof dp);
	ll rht = solve(right, right.size(), 1, -1, 1);

	return rht - lft;
}

int main() {
	fastio;
	int t = 1;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		x--;
		string sx = to_string(x), sy = to_string(y);
		cout << solve(sx, sy) << '\n';
	}
}