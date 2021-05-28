#include <bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> adjList(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < edges.size(); i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }

    vector<bool> visited(n, false);
    vector<vector<int>> dp(n, vector<int>(26, 0));

    queue<int> level;
    for (int i = 0; i < n; i++) {
        // Push all root node
        if (indegree[i] == 0) level.push(i);
    }
    int ans = 0;
    while (level.size()) {
        int m = level.size();
        while (m--) {
            int u = level.front();
            level.pop();
            visited[u] = true;
            dp[u][colors[u] - 'a']++;  // Include color

            for (int i = 0; i < 26; i++) {
                ans = max(ans, dp[u][colors[u] - 'a']);
            }

            for (int v : adjList[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    level.push(v);
                } else if (indegree[v] < 0) {
                    return -1;
                }

                // Now fill the dp
                for (int i = 0; i < 26; i++) dp[v][i] = max(dp[v][i], dp[u][i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return -1;
    }
    return ans;
}

int main() {
    string colors;
    cin >> colors;
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> edges[i][0] >> edges[i][1];
    cout << largestPathValue(colors, edges);
}