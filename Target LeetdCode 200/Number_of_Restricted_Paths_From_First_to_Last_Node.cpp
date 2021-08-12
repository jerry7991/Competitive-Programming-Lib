class Solution {
public:
    int countPathUToV(vector<vector<int>> &dag, vector<int> &dp , int u, int n, int p = -1) {
        if (u == n - 1) {
            return 1;
        }
        int &ans = dp[u];

        if (ans > -1) return ans;

        ans = 0;

        for (int v : dag[u]) {
            if (v == p) continue;
            ans = (ans + countPathUToV(dag, dp, v, n, u)) % 1000000007;
        }
        return ans;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dist(n, INT_MAX);
        vector < vector<vector<int>>> graph(n);
        for (auto x : edges) {
            graph[x[0] - 1].push_back({x[1] - 1, x[2]});
            graph[x[1] - 1].push_back({x[0] - 1, x[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPq;

        minPq.push({0, n - 1});
        dist[n - 1] = 0;
        int cnt = 0;

        while (minPq.size()) {
            auto x = minPq.top();
            minPq.pop();

            int u = x.second, w = x.first;

            if (dist[u] != w)continue;

            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i][0], W = graph[u][i][1];

                if (w + W < dist[v]) {
                    dist[v] = w + W;
                    minPq.push({dist[v], v});
                }
            }
        }

        vector<vector<int>> dag(n);


        vector<int> dp(n, -1);

        for (auto x : edges) {
            if (dist[x[0] - 1] > dist[x[1] - 1]) {
                dag[x[0] - 1].push_back(x[1] - 1);
            }

            if (dist[x[0] - 1] < dist[x[1] - 1]) {
                dag[x[1] - 1].push_back(x[0] - 1);
            }
        }


        return countPathUToV(dag, dp, 0, n);
    }
};