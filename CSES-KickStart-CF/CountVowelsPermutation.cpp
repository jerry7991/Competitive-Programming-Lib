#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:

	int dp[2 * 10000 + 1][27];
	int mod = 1000000007;

	vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};

	int solve(int n, char last) {
		if (n == 0) return 1;


		int &ans = dp[n][last - 'a' + 1];
		if (ans != -1) return ans;
		ans = 0;

		switch (last) {
			case 'a':
				ans = (ans + solve(n - 1, 'e')) % mod;
				break;
			case 'e':
				ans = (ans + solve(n - 1, 'a') + solve(n - 1, 'i')) % mod;
				break;
			case 'i':
				for (char ch : vowel) {
					if (ch != 'i')
						ans = (ans + solve(n - 1, ch)) % mod;
				}
				break;
			case 'o':
				ans = (ans + solve(n - 1, 'i') + solve(n - 1, 'u')) % mod;
				break;
			case 'u':
				ans = (ans + solve(n - 1, 'a')) % mod;
				break;
			default:
				for (char ch : vowel) {
					ans = (ans + solve(n - 1, ch)) % mod;
				}
		}
		return ans;

	}


	int countVowelPermutation(int n) {
		memset(dp, -1, sizeof dp);

		char ch = 'a';
		ch--;

		return solve(n, ch);
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (new Solution())->countVowelPermutation(n) << endl;
	}
}