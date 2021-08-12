#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];
    cout << (new Solution())->findLength(nums1, nums2);
    return 0;
}