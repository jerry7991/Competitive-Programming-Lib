#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
	int dp[32][3][2];

	int solve(string & dig, int n, int tight,  int last, string str = "") {
		if (n == 0) {

			// uncomment for all the possible substring and also remove memo
			// cout << str << endl;
			return 1;
		}

		/*

			if dig = 10101 and we put 1 at first position than we can't put 1 and 2nd from msb

		*/
		int ub = tight ? (dig[dig.size() - n] - '0') : 1;

		int &ans = dp[n][last + 1][tight];

		if (ans != -1) return ans;
		ans = 0;

		for (int i = 0; i <= ub; i++) {

			// If last wasn't 0  and it equals to 1
			if (last && last == i) continue;
			ans += solve(dig, n - 1, tight & (i == ub), i, str + to_string(i));
		}

		return ans;
	}

	int findIntegers(int n) {
		string dig = "";

		memset(dp, -1, sizeof dp);

		while (n) {
			dig.append(to_string(n % 2));
			n /= 2;
		}

		reverse(dig.begin(), dig.end());

		return solve(dig, dig.size(), 1, -1);
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << findIntegers(n) << endl;
	}

}