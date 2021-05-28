#include <bits/stdc++.h>
using namespace std;
long long int solve(vector<int>& nums, vector<int>& multipliers, int l, int r, int i, vector<vector<long long int>>& dp) {
    if (l > r) {
        if (i == multipliers.size()) {
            return 0;
        } else {
            return INT_MIN;
        }
    }

    if (i == multipliers.size()) {
        return 0;
    }

    long long int &ans = dp[l][r % 1000], left, right;

    if (ans != INT_MIN) return ans;

    left = solve(nums, multipliers, l + 1, r, i + 1, dp) + multipliers[i] * nums[l];
    right = solve(nums, multipliers, l, r - 1, i + 1, dp) + multipliers[i] * nums[r];

    ans = max(ans, max(left, right));
    return ans;
}

int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    vector<vector<long long int>> dp(1001, vector<long long int>(1001, INT_MIN));
    return solve(nums, multipliers, 0, nums.size() - 1, 0, dp);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    vector<int> multipliers(m);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < m; i++) cin >> multipliers[i];
    cout << maximumScore(nums, multipliers);
}