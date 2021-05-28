#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= m; i++) dp[0][i] = 0;
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = 0;
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
                count = max(count, dp[i][j]);
            }
        }
        return count;
    }

    // Optimise space

    int findLengthOp(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(2, vector<int>(m + 1));
        for (int i = 0; i <= m; i++) dp[0][i] = 0;
        for (int i = 0; i <= 1; i++) dp[i][0] = 0;
        int count = 0, flag = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[flag][j] = 0;
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[flag][j] = max(dp[flag][j], 1 + dp[flag ^ 1][j - 1]);
                }
                count = max(count, dp[flag][j]);
            }
            flag ^= 1;
        }
        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];
    cout << (new Solution())->findLength(nums1, nums2) << endl;
}
