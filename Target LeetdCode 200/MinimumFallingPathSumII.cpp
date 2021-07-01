#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Approach With memo
    int solve(vector<vector<int>>& nums, int i, int j, int n, int m, vector<vector<int>>& dp) {
        if (i == n) return 0;
        int& ans = dp[i][j];
        if (ans != 1000000) return ans;
        for (int k = 0; k < m; k++) {
            if (k == j) continue;
            ans = min(ans, nums[i][j] + solve(nums, i + 1, k, n, m, dp));
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& nums) {
        int ans = 1000000;
        for (int i = 0; i < nums[0].size(); i++) {
            vector<vector<int>> dp(nums.size(), vector<int>(nums[0].size(), 1000000));
            ans = min(ans, solve(nums, 0, i, nums.size(), nums[0].size(), dp));
        }
        return ans;
    }

    // Optimise O(N*M^2)
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size(), mVal = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mVal = INT_MAX;
                for (int k = 1; k <= m; k++) {
                    if (k == j) continue;
                    mVal = min(mVal, dp[i - 1][k]);
                }
                dp[i][j] = nums[i - 1][j - 1] + mVal;
            }
        }

        mVal = INT_MAX;
        for (int i = 1; i <= m; i++) mVal = min(mVal, dp[n][i]);
        return mVal;
    }

    //  Optimize O(N*M)
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size(), firstMin = 0, secondMin = 0, pos = -1;

        for (int i = 0; i < n; i++) {
            int firstMin2 = INT_MAX, secondMin2 = INT_MAX, pos2 = 0;
            for (int j = 0; j < m; j++) {
                int mn = (pos != j) ? firstMin : secondMin;
                if (nums[i][j] + mn < firstMin2) {
                    secondMin2 = firstMin2;
                    firstMin2 = nums[i][j] + mn;
                    nums[i][j] = firstMin2;
                    pos2 = j;
                } else {
                    secondMin2 = min(secondMin2, nums[i][j] + mn);
                }
            }
            firstMin = firstMin2, secondMin = secondMin2, pos = pos2;
        }
        return firstMin;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> nums[i][j];
    cout << (new Solution())->minFallingPathSum(nums);
}