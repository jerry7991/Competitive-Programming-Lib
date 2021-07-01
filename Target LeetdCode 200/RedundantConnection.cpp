#include <bits/stdc++.h>
using namespace std;

class UnionFind {
   public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i, rank[i] = 0;
    }

    int getParent(int u) {
        while (parent[u] != u) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    }

    bool makeUnion(int u, int v) {
        int pU = getParent(u), pV = getParent(v);
        if (pU == pV) return false;

        if (rank[pU] > rank[pV]) {
            parent[pV] = pU;
        } else {
            if (rank[pV] == rank[pU]) {
                parent[pV] = pU;
                rank[pU]++;
            } else {
                parent[pU] = pV;
            }
        }
        return true;
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind* unionFind = new UnionFind(10001);
        vector<int> out;
        for (auto edge : edges) {
            int x = edge[0], y = edge[1];
            if (!unionFind->makeUnion(x, y)) {
                out.push_back(x);
                out.push_back(y);
            }
        }
        return out;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> nums[i][0] >> nums[i][1];
    auto x = (new Solution())->findRedundantConnection(nums);
    for (auto y : x) cout << y << " ";
}