#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s, string t) {
    int n = s.size(), m = t.size(), flag = 1;
    vector<vector<int>> dp(2, vector<int>(m + 1));
    for (int i = 0; i <= m; i++) dp[0][i] = 0;
    dp[1][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j == 0) {
                dp[flag][j] = 0;
                continue;
            }
            if (s[i - 1] == t[j - 1]) {
                dp[flag][j] = 1 + dp[flag ^ 1][j - 1];
            } else {
                dp[flag][j] = max(dp[flag ^ 1][j], dp[flag][j - 1]);
            }
        }
        flag ^= 1;
    }
    return dp[flag ^ 1][m];
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << longestCommonSubsequence(s, t);
}