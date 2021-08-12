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


        vector<vector<int>> dp(n, vector<int>(n));

        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) {
                    dp[i][j] = 0;
                } else if (g == 1) {
                    dp[i][j] = (s[i] != s[j]);
                } else {
                    if (isPalindrome[i][j]) {
                        dp[i][j] = 0;
                    } else {
                        int m = INT_MAX;
                        for (int k = i; k < j; k++) {
                            m = min(m, 1 + (dp[i][k] + dp[k + 1][j]));
                        }
                        dp[i][j] = m;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};