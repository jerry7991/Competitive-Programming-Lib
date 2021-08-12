#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> bridge;
    int time = 0;

    void doDfs(vector<vector<int>>& edge, vector<int>& tin, vector<int>& low, vector<bool>& seen, int u, int p = -1) {
        tin[u] = low[u] = time++;
        seen[u] = true;
        for (auto v : edge[u]) {
            if (v == p) continue;
            if (!seen[v]) {
                doDfs(edge, tin, low, seen, v, u);
                low[u] = min(low[v], low[u]);
                if (low[v] > tin[u]) {
                    // this is the bridge
                    bridge.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> edge(n);
        for (auto x : con) {
            edge[x[0]].push_back(x[1]);
            edge[x[1]].push_back(x[0]);
        }

        vector<bool> seen(n, false);
        vector<int> tin(n), low(n);
        doDfs(edge, tin, low, seen, 0);
        return bridge;
    }
};
