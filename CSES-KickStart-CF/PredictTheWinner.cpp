class Solution {
  public:

    int solve(vector<int>&nums, int left, int right, int diff, int player) {
        if (left > right) {
            return diff;
        }
        int res = 0;
        if (res != -1) return res;
        if (player) {
            res = min(solve(nums, left + 1, right, diff - nums[left], player ^ 1) , solve(nums, left, right - 1, diff - nums[right], player ^ 1));
        } else {
            res = max(solve(nums, left + 1, right, diff + nums[left], player ^ 1) , solve(nums, left, right - 1, diff + nums[right], player ^ 1));
        }
        return res;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int len = 1; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};