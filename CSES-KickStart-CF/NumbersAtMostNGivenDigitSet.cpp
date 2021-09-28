#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
	int dp[10][2][2];

	int solve(vector<int> & digits, string &nums, int tight, int n, int leadingZero = 0, int x = 0) {

		if (n == 0) {

			// Just print here to get what what number you created and for that you need to comment memo
			// Finally we made a number
			return 1;
		}

		int &ans = dp[n][tight][leadingZero];
		if (ans != -1) return ans;
		ans = 0;


		//	If prev was tight like 345 and we have put 3 at first than we can put only [1,4] at second position
		int ub = tight ? (nums[nums.size() - n] - '0') : 9;

		if (leadingZero == 0) {

			//	One thing is always possible that we can create number by appneding 0
			// Like 000, 001, 002 in which 000 is not desired because digits wouldn't contains 0
			ans += solve(digits, nums, 0, n - 1, 0, 0);
		}

		for (int &i : digits) {

			if (i > ub) break;


			ans += solve(digits, nums, tight & (i == ub), n - 1, 1, x * 10 + i);
		}
		return ans;
	}

	int atMostNGivenDigitSet(vector<string>& digits, int n) {

		// Let's convert it to int
		vector<int> dig(digits.size());
		for (int i = 0; i < digits.size(); i++) {
			dig[i] = stoi(digits[i]);
		}


		// Take string to get faster digit
		string str = to_string(n);

		memset(dp, -1, sizeof dp);
		return solve(dig, str, 1, str.size()) - 1;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> digits(n);


	for (string &i : digits) cin >> i;
	cout << (new Solution())->atMostNGivenDigitSet(digits, m) << endl;
}