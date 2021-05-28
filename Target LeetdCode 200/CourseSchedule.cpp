#include <bits/stdc++.h>
using namespace std;

bool runDfs(int curr, vector<bool>& visited, vector<bool>& stackHistory, vector<vector<int>>& edges) {
    // Assume there is no cycle
    bool ans = true;
    visited[curr] = stackHistory[curr] = true;

    for (int i = 0; i < edges[curr].size(); i++) {
        if (!visited[edges[curr][i]]) {
            ans &= runDfs(edges[curr][i], visited, stackHistory, edges);
            if (!ans) return ans;
        } else if (stackHistory[edges[curr][i]]) {
            return false;
        }
    }
    stackHistory[curr] = false;
    return ans;
}

bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(n);
    for (vector<int> a : prerequisites) {
        edges[a[0]].push_back(a[1]);
    }
    vector<bool> visited(n, false);
    vector<bool> stackHistory(n, false);

    // Assume there is no cycle
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            ans &= runDfs(i, visited, stackHistory, edges);
        if (!ans) return ans;
    }
    return ans;
}

int main() {
    int numCourses;
    cin >> numCourses;
    vector<vector<int>> prerequisites(numCourses, vector<int>(2));
    for (int i = 0; i < numCourses; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    cout << canFinish(numCourses, prerequisites);
}