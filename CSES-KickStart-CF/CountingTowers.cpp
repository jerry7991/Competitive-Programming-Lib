#include<bits/stdc++.h>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int mod = 1e9 + 7;

	vector<vector<int>> dp(1e6 + 1, vector<int>(2));
	dp[0][0] = dp[0][1] = 1;

	for (int i = 1; i < (1e6 + 1); i++) {
		// we can whether prev was linked or not
		// for not linked
		int notExtend = (dp[i - 1][0] + dp[i - 1][1]) % mod;
		int extend = ((2 * dp[i - 1][0]) % mod + dp[i - 1][0]) % mod; /// Extend any of one or both

		dp[i][0] = (notExtend + extend) % mod;


		// For linked
		//	Either we can extend both or we can not extend any of them

		notExtend = (dp[i - 1][0] + dp[i - 1][1]) % mod;
		extend = dp[i - 1][1];// when last height was filled with linked than only i can extend both/

		dp[i][1] = (notExtend + extend) % mod;
	}


	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << endl;
	}
}