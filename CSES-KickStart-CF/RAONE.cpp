#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;


ll dp[20][200][2];

ll solve(string str, int tight, int n, ll diff) {

	if (n == 0) {
		return diff == 1;
	}

	int ub = tight ? (str[str.size() - n] - '0') : 9;

	ll &ans = dp[n][diff + 100][tight];

	if (ans != -1) return ans;
	ans = 0;

	for (int dig = 0; dig <= ub; dig++) {
		if (n & 1) {
			ans += solve(str, (tight & (dig == ub)), n - 1, diff - dig);
		} else {
			ans += solve(str, (tight & (dig == ub)), n - 1, diff + dig);
		}

	}
	return ans;

}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		a--;

		string A = to_string(a), B = to_string(b);

		memset(dp, -1, sizeof dp);

		ll left = solve(A, 1, A.size(), 0);

		memset(dp, -1, sizeof dp);

		ll right = solve(B, 1, B.size(), 0);

		cout << (right - left) << '\n';
	}
}