class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));



        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; j++, i++) {
                if (g == 0) {
                    isPalindrome[i][j] = true;
                } else if (g == 1) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    if (s[i] == s[j]) {
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                    } else {
                        isPalindrome[i][j] = false;
                    }
                }
            }
        }


        vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;
                continue;
            }
            int ans = INT_MAX;
            for (int k = i; k >= 1; k--) {
                if (isPalindrome[k][i]) {
                    ans = min(ans, dp[k - 1]);
                }
            }
            dp[i] = ans + 1;
        }
        return dp[n - 1];
    }
};