#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

	int dp[11][11][2][2];

	int solve(string &str, int tight, int n, int lz, int one) {
		if (n == 0) return one;
		int &ans = dp[n][one][tight][lz];

		if (ans != -1) return ans;
		ans = 0;

		int ub = tight ? (str[str.size() - n] - '0') : 9;

		if (lz == 0) {
			ans += solve(str, 0, n - 1, 0, one);
		}

		for (int i = 0; i <= ub; i++) {

			if (lz == 0 && i == 0) continue;

			ans += solve(str, tight & (i == ub), n - 1, 1, one + (i == 1));
		}

		return ans;

	}


	int countDigitOne(int n) {

		if (n == 0) return 0;

		string N = to_string(n);

		memset(dp, -1, sizeof dp);

		return solve(N, 1, N.size(), 0, 0);
	}
};

int main() {
	int n;
	cin >> n;
	cout << (new Solution())->countDigitOne(n) << endl;
}