#include <bits/stdc++.h>
using namespace std;

int solve(string &word1, string &word2, vector<vector<int>> &dp, int i, int j) {
    if (i == word1.size() && j == word2.size()) {
        return 0;
    }
    if (i == word1.size()) {
        return word2.size() - j;
    }
    if (j == word2.size()) {
        return word1.size() - i;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 0;
    if (word1[i] == word2[j]) {
        ans = solve(word1, word2, dp, i + 1, j + 1);
    } else {
        ans = 1 + min(solve(word1, word2, dp, i + 1, j), solve(word1, word2, dp, i, j + 1));
    }
    return dp[i][j] = ans;
}

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(word1, word2, dp, 0, 0);
}

int minDistanceOp(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}

int minDistanceOp(string word1, string word2) {
    int n = word1.size(), m = word2.size(), flag = 1;
    vector<vector<int>> dp(2, vector<int>(m + 1));
    for (int i = 0; i <= m; i++) dp[0][i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                dp[flag][j] = i;
            } else {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[flag][j] = dp[flag ^ 1][j - 1];
                } else {
                    dp[flag][j] = 1 + min(dp[flag ^ 1][j], dp[flag][j - 1]);
                }
            }
        }
        flag ^= 1;
    }
    return dp[flag ^ 1][m];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << minDistance(str1, str2);
}