#include <iostream>
#include <vector>
using namespace std;
int solve(int k , vector<vector<vector<int>>> &dp, vector<int>&prices , bool onGoing = false , int day = 0) {
	if (day == prices.size()) return 0;
	if (dp[day][k][onGoing] != -1) return dp[day][k][onGoing];
	int opt2 = solve(k, dp, prices, onGoing, day + 1);
	if (onGoing) {
		int opt1 = prices[day] + solve(k, dp, prices, !onGoing, day + 1);
		opt2 = max(opt1, opt2);
	} else {
		if (k > 0) {
			int opt1 = solve(k - 1, dp, prices, !onGoing, day + 1) - prices[day];
			opt2 = max(opt1, opt2);
		}
	}
	return dp[day][k][onGoing] = opt2;
}
int maxProfit(int k, vector<int>& prices) {
	vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
	return solve(k, dp, prices);
}
int main() {
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}
	int k;
	cin >> k;
	cout << maxProfit(k, prices) << '\n';
}