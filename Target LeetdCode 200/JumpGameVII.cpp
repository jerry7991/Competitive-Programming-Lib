#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canReach(string s, int minJ, int maxJ) {
        int n = s.size(), one = 0;
        vector<bool> dp(n);
        dp[0] = true;
        for (int i = 1; i < n; i++) {
            if (i >= minJ && dp[i - minJ]) one++;
            if (i > maxJ && dp[i - maxJ - 1]) one--;
            dp[i] = one > 0 && s[i] != '1';
        }
        return dp[n - 1];
    }
};

int main() {
    string s;
    int mn, mx;
    cin >> s >> mn >> mx;
    cout << (new Solution())->canReach(s, mn, mx);
}