#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getParent(vector<int>& parent, int u) {
        if (u != parent[u]) {
            return parent[u] = getParent(parent, parent[u]);
        }
        return u;
    }

    void makeUnion(vector<int>& parent, vector<int>& rank, int u, int v) {
        int uParent = getParent(parent, u), vParent = getParent(parent, v);
        if (uParent == vParent) return;
        if (rank[uParent] > rank[vParent]) {
            parent[vParent] = uParent;
        } else {
            if (rank[uParent] == rank[vParent]) {
                parent[vParent] = uParent;
                rank[uParent]++;
            } else {
                parent[uParent] = vParent;
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> parent(n), rank(n);
        vector<vector<int>> group(n, vector<int>());
        for (int i = 0; i < n; i++) parent[i] = i;
        for (vector<int>& x : pairs) {
            int u = getParent(parent, x[0]), v = getParent(parent, x[1]);
            if (u != v) {
                parent[v] = u;
            }
        }

        for (int i = 0; i < parent.size(); i++) {
            group[getParent(parent, i)].push_back(i);
        }

        for (auto& ids : group) {
            string ss = "";
            for (auto id : ids) {
                // cout<<id<<" ";
                ss += s[id];
            }
            // cout<<endl;
            sort(ss.begin(), ss.end());

            for (int i = 0; i < ids.size(); i++) {
                s[ids[i]] = ss[i];
            }
        }
        return s;
    }
};

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> pairs[i][0] >> pairs[i][1];
    cout << (new Solution())->smallestStringWithSwaps(s, pairs);
}