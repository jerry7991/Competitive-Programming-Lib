#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int n = fee.size();
        const int inf = 1e9 + 5;
        vector<vector<int>> dp(maxTime + 1, vector<int>(n + 1, inf));
        vector<vector<pair<int, int>>> adj(n);
        for (auto x : edges) {
            int u = x[0], v = x[1], len = x[2];
            adj[u].emplace_back(v, len);
            adj[v].emplace_back(u, len);
        }
        dp[0][0] = fee[0];

        for (int t = 0; t <= maxTime; t++) {
            for (int u = 0; u < n; u++) {
                int cost = dp[t][u];
                if (cost >= inf) continue;

                //  Go to every neoughbour
                for (const pair<int, int>& e : adj[u]) {
                    int v = e.first, t2 = t + e.second;
                    if (t2 <= maxTime) {
                        // Take min of u->v
                        dp[t2][v] = min(dp[t2][v], cost + fee[v]);
                    }
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= maxTime; i++) {
            ans = min(ans, dp[i][n - 1]);
        }

        return ans >= inf ? -1 : ans;
    }
};
