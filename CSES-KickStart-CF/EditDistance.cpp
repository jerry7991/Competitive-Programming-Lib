#include<bits/stdc++.h>
using namespace std;

int solve(string &s, string &t, vector<vector<int>> &dp, int i = 0, int j = 0) {
	if (j == t.size()) {
		return s.size() - i;
	}

	if (i == s.size()) {
		return t.size() - j;
	}

	int &ans = dp[i][j];
	if (ans > -1) return ans;
	if (s[i] == t[j]) {
		ans = solve(s, t, dp, i + 1, j + 1);
	} else {
		int replace = 1 + solve(s, t, dp , i + 1, j + 1);
		int remove = 1 + solve(s, t, dp , i, j + 1);
		int add = 1 + solve(s, t, dp , i + 1, j);
		ans = min({replace, remove, add});
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t;
	cin >> s >> t;
	int n = t.size(), m = s.size();
	// cout << solve(s, t, dp);
	// return 0;

	vector<vector<int>> dp(2, vector<int>(m + 1, -1));


	for (int i = 0; i <= m; i++) dp[0][i] = i;
	// for (int i = 0; i <= n; i++)dp[i][0] = i;

	//	for t
	int flag = 1;

	for (int i = 1; i <= n; i++) {
		// for s
		for (int j = 0; j <= m; j++) {
			if (j == 0) {
				dp[flag][j] = i;
			} else if (s[j - 1] == t[i - 1]) {
				// Nothing to do
				dp[flag][j] = dp[flag ^ 1][j - 1];
			} else {
				int replace =  dp[flag ^ 1][j - 1]; // Both length will be decrease
				int insert =  dp[flag ^ 1][j]; // s.length will increase by 1
				int remove =  dp[flag][j - 1];
				dp[flag][j] = 1 + min({replace, insert, remove});
			}
		}
		flag ^= 1;
	}
	cout << dp[flag ^ 1][m] << endl;
}