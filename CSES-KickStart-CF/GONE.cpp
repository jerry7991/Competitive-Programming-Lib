#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;

bool isPrime[100];
ll dp[100][10][2];


void calPrime() {
	memset(isPrime, true, sizeof isPrime);

	isPrime[1] = isPrime[0] = false;

	for (int i = 2; i * i < 100; i++) {
		if (!isPrime[i]) continue;
		isPrime[i] = true;
		for (int j = i * i; j < 100; j += i) {
			isPrime[j] = false;
		}
	}
}


ll solve(string &str, int n, int tight, int sum) {
	if (n == 0) {
		return isPrime[sum];
	}

	ll &ans = dp[sum][n][tight];

	if (ans != -1) return ans;
	ans = 0;

	int ub = tight ? (str[str.size() - n] - '0') : 9;

	for (int dig = 0; dig <= ub; dig++) {
		ans += solve(str, n - 1, tight & (dig == ub), sum + dig);
	}
	return ans;
}

int main() {
	fastio;

	calPrime();
	int t;
	cin >> t;
	while (t--) {

		ll a, b;
		cin >> a >> b;
		a--;

		string A = to_string(a), B = to_string(b);


		memset(dp, -1, sizeof dp);
		ll left = solve(A, A.size(), 1, 0);

		memset(dp, -1, sizeof dp);
		ll right = solve(B, B.size(), 1, 0);

		cout << (right - left) << "\n";
	}
}