#include<bits/stdc++.h>
#define fastio 	ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define ll long long

using namespace std;

bool compare(vector<ll> &v1, vector<ll> &v2) {
	return v1[1] < v2[1];
}

ll getUpperBound(vector<vector<ll>> &v, ll j, ll x) {
	ll i = 0, ans = -1;
	while (i <= j) {
		ll m = (i + j) / 2;
		if (v[m][1] > x) {
			j = m - 1;
		} else if (v[m][1] < x) {
			ans = m;
			i = m + 1;
		} else {
			i = m + 1;
		}
	}
	return ans;
}

ll solve(vector<vector<ll>> &v) {
	ll n = v.size();
	sort(v.begin(), v.end(), compare);

	vector<ll> dp(n);
	dp[0] = v[0][2];


	for (ll i = 1; i < n; i++) {
		ll exclude = dp[i - 1];
		ll idx = getUpperBound(v, i - 1, v[i][0]);
		ll include = v[i][2];
		if (idx != -1) {
			include = include + dp[idx];
		}
		dp[i] = max(include, exclude);
	}
	return dp[n - 1];
}

int main() {
	fastio

	ll n;
	cin >> n;

	// 0-start time, 1- end time 2-profit
	vector<vector<ll>>v(n, vector<ll>(3));
	for (auto &x : v) {
		for (auto &y : x) cin >> y;
	}
	cout << solve(v) << "\n";
}