#include <bits/stdc++.h>

#define Pair pair<int, pair<int, int>>

using namespace std;

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> edge(n, vector<pair<int, int>>());
        for (auto x : times) {
            edge[x[0] - 1].push_back({x[1] - 1, x[2]});
        }

        vector<int> weight(n, INT_MAX);
        vector<bool> seen(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPq;
        minPq.push({0, k - 1});
        weight[k - 1] = 0;

        while (minPq.size()) {
            auto x = minPq.top();
            minPq.pop();
            int u = x.second, w = x.first;

            if (seen[u]) continue;
            seen[u] = true;
            for (int i = 0; i < edge[u].size(); i++) {
                int v = edge[u][i].first, W = edge[u][i].second;
                if (w + W < weight[v]) {
                    weight[v] = w + W;
                    minPq.push({w + W, v});
                }
            }
        }
        int t = 0;
        for (int x : weight) {
            if (x == INT_MAX) return -1;
            t = max(t, x);
        }
        return t;
    }
};