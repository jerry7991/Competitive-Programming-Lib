class Solution {
public:
    int dp2[200][200];
    int getMin(vector<vector<bool>>&dp, string &s, int i, int j) {
        int ans = 0;
        while (i <= j) {
            if (dp[i][j]) {
                return ans;
            }
            ans += (s[i++] != s[j--]);
        }
        return ans;
    }

    int solve(string &s, int k, vector<vector<bool>>& dp, int i) {
        if (i == s.size() || k < 0 ) {
            return k == 0 ? 0 : 2000;
        }

        int ans = 2000;
        if (dp2[i][k] > -1) return dp2[i][k];
        for (int j = i; j < s.size(); j++) {

            int minSwap = getMin(dp, s, i, j);
            int curr = solve(s, k - 1, dp, j + 1) + minSwap;
            ans  = min(ans, curr);
        }

        return dp2[i][k] = ans;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));


        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; j++, i++) {
                if (g < 2) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }

        memset(dp2, -1, sizeof(dp2));

        return solve(s, k, dp, 0);

    }
};