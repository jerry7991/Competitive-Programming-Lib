#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

ll dp[51][17][17][17][2];

ll solve(string &str, ll n, ll tight, ll three = 0, ll six = 0, ll nine = 0) {

	if (max({three, six, nine}) >= 17) return 0;

	if (n == 0) {
		return (three >= 1 && three == six && six == nine) ? 1LL : 0LL;
	}



	ll ub = tight ? (str[str.size() - n] - '0') : 9;

	ll &ans = dp[n][three][six][nine][tight];

	if (ans != -1) return ans % mod;
	ans = 0;

	for (ll dig = 0; dig <= ub; dig++) {
		ans = (ans + solve(str, n - 1, tight && (dig == ub), three + (dig == 3), six + (dig == 6), nine + (dig == 9)));
		ans %= mod;
	}
	return ans;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;


		memset(dp, -1, sizeof(ll) * 51 * 17 * 17 * 17 * 2);
		// memset(dp, -1, sizeof dp);
		ll resA = solve(a, a.size(), 1);



		memset(dp, -1, sizeof(ll) * 51 * 17 * 17 * 17 * 2);
		// memset(dp, -1, sizeof dp);
		ll resB = solve(b, b.size(), 1);


		ll three = 0, six = 0, nine = 0;
		for (char ch : a) {
			if (ch == '9') nine++;
			if (ch == '6') six++;
			if (ch == '3') three++;
		}

		ll ans = 0;

		if (three >= 1 && three == six  && six == nine) ans++;

		ans = (resB - resA + ans) % mod;
		ans = (ans + mod) % mod;

		ans %= mod;

		cout << ans << "\n";

	}
}