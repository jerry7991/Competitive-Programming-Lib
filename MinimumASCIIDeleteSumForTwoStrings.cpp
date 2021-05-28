#include <bits/stdc++.h>
using namespace std;

int solve(string &s, string &t, vector<vector<int>> &dp, int i, int j) {
    if (i == s.size() && j == t.size()) {
        return 0;
    }
    if (i == s.size()) {
        int ans = 0;
        while (j < t.size()) {
            ans += (int)t[j++];
        }
        return ans;
    }
    if (j == t.size()) {
        int ans = 0;
        while (i < s.size()) {
            ans += (int)s[i++];
        }
        return ans;
    }
    int &ans = dp[i][j];
    if (ans != -1) {
        return ans;
    }

    if (s[i] == t[j]) {
        ans = solve(s, t, dp, i + 1, j + 1);
    } else {
        ans = min((int)s[i] + solve(s, t, dp, i + 1, j), (int)t[j] + solve(s, t, dp, i, j + 1));
    }
    return ans;
}

int minimumDeleteSum(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(s1, s2, dp, 0, 0);
}

int minimumDeleteSumItr(string s1, string s2) {
    int n = s1.size(), m = s2.size(), flag = 1;
    vector<vector<int>> dp(2, vector<int>(m, 0));

    for (int i = 0; i < m; i++) {
        if (i == 0) dp[0][i] = (int)s2[i];
        dp[0][i] = dp[0][i - 1] + (int)s2[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j]) {
                dp[flag][j] = dp[flag ^ 1][j];
            } else {
                dp[flag][j] = min((int)s1[i] + dp[flag ^ 1][j], (int)s2[j] + j > 0 ? dp[flag][j - 1] : 0);
            }
        }
        flag ^= 1;
    }
    return dp[flag ^ 1][m - 1];
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << minimumDeleteSum(s, t);
}