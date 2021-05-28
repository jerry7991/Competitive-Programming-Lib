#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= m; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string scs = "";
    int i = n - 1, j = m - 1;
    while (i >= 0 || j >= 0) {
        if (i < 0 ^ j < 0) {
            // Only one string reaches left
            if (i < 0) {
                scs.push_back(t[j--]);
            } else {
                scs.push_back(s[i--]);
            }
        } else if (s[i] == t[j]) {
            scs.push_back(s[i]);
            i--;
            j--;
        } else {
            // choose the max one
            char ch = dp[i][j + 1] > dp[i + 1][j] ? s[i--] : t[j--];
            scs.push_back(ch);
        }
    }
    reverse(scs.begin(), scs.end());
    return scs;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << shortestCommonSupersequence(s, t);
}