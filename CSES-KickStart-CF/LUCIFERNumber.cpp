#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;

bool isPrime[100];

ll dp[200][10][2];


void fillPrime() {
	memset(isPrime , true, sizeof isPrime);

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= 100; i++) {

		if (!isPrime[i]) continue;
		isPrime[i] = true;

		for (int j = i * i; j < 100; j += i) {
			isPrime[j] = false;
		}
	}
}


ll solve(string &str, int n, int tight, int diff) {
	if (n == 0) {
		return diff >= 0 && isPrime[diff];
	}

	ll &ans = dp[100 + diff][n][tight];
	if (ans != -1) return ans;
	ans = 0;

	int ub = tight ? (str[str.size() - n] - '0') : 9;

	for (int dig = 0; dig <= ub; dig++) {
		if (n & 1)
			ans += solve(str, n - 1, tight & (dig == ub), diff - dig);
		else
			ans += solve(str, n - 1, tight & (dig == ub), diff + dig);
	}
	return ans;
}

int main() {
	fastio;
	int t;
	cin >> t;
	fillPrime();
	while (t--) {

		ll a, b;
		cin >> a >> b;

		a--;
		string A = to_string(a), B = to_string(b);


		memset(dp, -1, sizeof dp);
		ll resA = solve(A, A.size(), 1, 0);


		memset(dp, -1, sizeof dp);
		ll resB = solve(B, B.size(), 1, 0);

		cout << (resB - resA) << '\n';
	}
}