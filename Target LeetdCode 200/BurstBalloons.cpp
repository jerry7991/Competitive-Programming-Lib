#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Let's extract from small length to n
        for (int len = 1; len <= n; len++) {
            for (int left = 1; left <= n - len + 1; left++) {
                // Get the right range
                int right = left + len - 1;
                int bestCoin = 0;

                // Find the maximum possible coins if we burned all the ballon in the rand left to right
                for (int burn = left; burn <= right; burn++) {
                    // total coin from [left...burn-1] and [burn+1...right] because [burn] is going to be burned
                    int coins = dp[left][burn - 1] + dp[burn + 1][right];
                    coins += (nums[burn] * nums[left - 1] * nums[right + 1]);
                    bestCoin = max(bestCoin, coins);
                }

                // Store the answer
                dp[left][right] = bestCoin;
            }
        }

        // return the max coins which getting after burning from 1-n
        return dp[1][n];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->maxCoins(nums);
}