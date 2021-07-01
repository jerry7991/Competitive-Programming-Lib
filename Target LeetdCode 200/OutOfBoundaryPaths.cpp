#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int mod = 1e9 + 7;
    int solve(int m, int n, int maxMove, int r, int c, vector<vector<vector<int>>> &dp) {
        if (maxMove == 0) return (r >= m || c >= n || min(r, c) < 0);
        if (r >= m || c >= n || min(r, c) < 0) return 1;
        int &ans = dp[r][c][maxMove];
        if (ans != -1) return ans;
        ans = 0;
        for (int i = 0; i < 4; i++) {
            ans = (ans + solve(m, n, maxMove - 1, r + dx[i], c + dy[i], dp)) % mod;
        }
        return ans;
    }
    int findPaths(int m, int n, int maxMove, int r, int c) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(51, -1)));
        return solve(m, n, maxMove, r, c, dp);
    }
};

int main() {
    int v, w, x, y, z;
    cin >> v >> w >> z >> y >> z;
    cout << (new Solution())->findPaths(v, w, x, y, z);
}