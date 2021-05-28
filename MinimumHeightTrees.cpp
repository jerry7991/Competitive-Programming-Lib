#include <bits/stdc++.h>
using namespace std;

void runBfs(vector<vector<int>>& adj, int st, vector<int>& dp) {
    queue<int> level;
    level.push(st);
    vector<bool> visited(dp.size(), false);
    visited[st] = true;
    int ht = 0;
    while (level.size()) {
        int n = level.size();
        ht++;
        while (n--) {
            int temp = level.front();
            level.pop();
            for (int i = 0; i < adj[temp].size(); i++) {
                if (!visited[adj[temp][i]]) {
                    level.push(adj[temp][i]);
                    visited[adj[temp][i]] = true;
                }
            }
        }
    }
    dp[st] = ht;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(n);
    for (vector<int> adj : edges) {
        adjList[adj[0]].push_back(adj[1]);
        adjList[adj[1]].push_back(adj[0]);
    }
    vector<int> dp(n, -1);
    int minHt = n + 2;
    for (int i = 0; i < n; i++) {
        runBfs(adjList, i, dp);
        minHt = min(minHt, dp[i]);
    }
    vector<int> out;
    for (int i = 0; i < n; i++) {
        if (dp[i] == minHt) out.push_back(i);
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> edges[i][0] >> edges[i][1];

    vector<int> out = findMinHeightTrees(n, edges);
    for (int x : out) cout << x << " ";
}