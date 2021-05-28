#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    vector<unordered_set<int>> adjList(n);
    for (vector<int> adj : edges) {
        adjList[adj[0]].insert(adj[1]);
        adjList[adj[1]].insert(adj[0]);
    }
    vector<int> visited(n, false);
    vector<int> leaves;
    for (int i = 0; i < n; i++) {
        //  To the parent
        if (adjList[i].size() == 1) {
            leaves.push_back(i);
            visited[i] = true;
        }
    }

    int remainingNode = n;
    while (remainingNode > 2) {
        remainingNode -= leaves.size();
        vector<int> newLeaves;
        //  Remove the current leaves
        for (int leafe : leaves) {
            for (int nb : adjList[leafe]) {
                adjList[nb].erase(leafe);
                if (adjList[nb].size() == 1) {
                    newLeaves.push_back(nb);
                }
            }
        }
        leaves = newLeaves;
    }
    return leaves;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> edges[i][0] >> edges[i][1];

    vector<int> out = findMinHeightTrees(n, edges);
    for (int x : out) cout << x << " ";
}