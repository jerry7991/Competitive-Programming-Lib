#include <bits/stdc++.h>
using namespace std;

void runBfs(vector<vector<int>>& edges, vector<vector<bool>>& isReachable, int i, vector<bool>& visited) {
    queue<int> level;
    level.push(i);
    visited[i] = true;
    while (level.size()) {
        int n = level.size();
        while (n--) {
            int curr = level.front();

            isReachable[i][curr] = true;

            level.pop();
            for (int k = 0; k < edges[curr].size(); k++) {
                if (!visited[edges[curr][i]]) {
                    level.push(edges[curr][edges[curr][i]]);
                    visited[edges[curr][i]] = true;
                }
            }
        }
    }
}

vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    // Make adjacent List
    vector<vector<int>> edges(n);
    for (auto x : prerequisites) edges[x[0]].push_back(x[1]);

    // Collect the data where isReachable[i][j] will represents that i is prerequisites before taking course j
    vector<vector<bool>> isReachable(n, vector<bool>(n, false));

    //  runBfs for all I
    for (int i = 0; i < n; i++) {
        //  Will need it to avoid TLE because same node will be pushed multiple times
        vector<bool> visited(n);

        //  Collect all the course for which course 'i' is prerequisites
        runBfs(edges, isReachable, i, visited);
    }

    vector<bool> ans(queries.size());
    int i = 0;
    for (auto q : queries) {
        ans[i++] = isReachable[q[0]][q[1]];
    }
    return ans;
}

// Floyed washel
vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    for (auto x : prerequisites) edges[x[0]][x[1]] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                // if j->i and i->k thank j->k (Transitive Property)
                edges[j][k] = (edges[j][i] && edges[i][k]) || edges[j][k];
            }
        }
    }
    vector<bool> ans(queries.size());
    int i = 0;
    for (auto q : queries) {
        ans[i++] = edges[q[0]][q[1]];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> prerequisites(n, vector<int>(2));

    for (int i = 0; i < n; i++) cin >> prerequisites[i][0] >> prerequisites[i][1];
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) cin >> queries[i][0] >> queries[i][1];

    vector<bool> ans = checkIfPrerequisite(n, prerequisites, queries);
}