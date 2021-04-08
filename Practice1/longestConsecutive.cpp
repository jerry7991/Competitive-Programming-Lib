#include <bits/stdc++.h>
using namespace std;

void doDfs(unordered_map<int, vector<int>>& edge, int src, unordered_set<int>& visited, int& count) {
    visited.insert(src);
    count++;
    vector<int> dest = edge[src];
    for (int i : dest) {
        if (!visited.count(i) && edge.count(i)) {
            doDfs(edge, i, visited, count);
        }
    }
}

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, vector<int>> srcToParent;
    for (int i : nums) {
        srcToParent[i] = {i + 1, i - 1};
    }
    unordered_set<int> visited;
    int total = 0;

    for (pair<int, vector<int>> curr : srcToParent) {
        int src = curr.first;
        if (!visited.count(src)) {
            int count = 0;
            doDfs(srcToParent, src, visited, count);
            total = max(total, count);
        }
    }
    return total;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << longestConsecutive(v);
}