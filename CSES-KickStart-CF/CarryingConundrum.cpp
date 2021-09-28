#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

ll dp[10][10][10];

ll solve(string &str, int n, int prev, int prevOfPrev, int a = 0, int b = 0) {
	if (n == 0) {
		return prev == 0 && prevOfPrev == 0;
	}
	ll &ans = dp[n][prev][prevOfPrev];

	if (ans != -1) return ans;

	ans = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i + j + prevOfPrev) % 10 == (str[n - 1] - '0')) {
				ans += solve(str, n - 1, (i + j + prevOfPrev) / 10, prev, a * 10 + i, b * 10 + j);
			}
		}
	}
	return ans;

}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		memset(dp, -1, sizeof dp);
		cout << solve(str, str.size(), 0, 0) - 2 << "\n";
	}
}