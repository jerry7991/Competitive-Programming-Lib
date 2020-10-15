#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums , int l , int r, vector<vector<int>> &dp) {
	if (l > r) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	int ans1 = nums[l] + solve(nums , l + 2 , r - (r == nums.size() - 1), dp);
	int ans3 = solve(nums , l + 1 , r, dp);
	int ans2 = nums[r] + solve(nums , l + (l == 0) , r - 2, dp);
	int ans4 = solve(nums , l, r - 1, dp);
	return dp[l][r] = max(ans1, max(ans2, max(ans3, ans4)));
}
int rob(vector<int>& nums) {
	int l = 0, r = nums.size() - 1;
	vector<vector<int>> dp(r + 1, vector<int>(r + 1, -1));
	return solve(nums , l, r, dp);
}

int robIIHelper(vector<int> &nums, int left, int right) {
	int prev = 0, curr = 0;
	while (left <= right) {
		int temp = max(nums[left] + prev , curr);
		prev = curr;
		curr = temp;
	}
	return curr;
}
int robII(vector<int> &nums) {
	int n = nums.size();
	if (n < 2) return n ? nums[n] : 0;
	return max(robIIHelper(nums , 0 , n - 2) , robIIHelper(nums , 1, n - 1));
}
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << robII(v) << '\n';
	return 0;
}
