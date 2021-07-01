#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(int n, int k, vector<vector<int>> &dp) {
        if (n <= 1 || k == 1) {
            return n;
        }
        int &ans = dp[n][k];
        if (ans != -1) return ans;
        ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int broken = solve(i - 1, k - 1, dp);
            int notBroken = solve(n - i, k, dp);
            ans = min(ans, 1 + max(broken, notBroken));
        }
        return ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(n, k, dp);
    }

    int solve(int n, int k) {
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= k; i++) dp[i][1] = 1, dp[i][0] = 0;
        for (int i = 0; i <= n; i++) dp[1][i] = i, dp[0][i] = 0;

        for (int i = 2; i <= k; i++) {
            for (int j = 2; j <= n; j++) {
                int l = 1, r = j, temp = 0, ans = INT_MAX;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    int left = dp[i - 1][mid - 1];  // Egg broken before down floor
                    int right = dp[i][j - mid];     // Egg broken up floor
                    temp = 1 + max(left, right);
                    if (left < right) {
                        l = mid + 1;  // Go to worst part
                    } else {
                        r = mid - 1;
                    }
                    ans = min(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[k][n];
    }
};

int main() {
    int k, n;
    cin >> n >> k;
    cout << (new Solution())->superEggDrop(n, k);
}