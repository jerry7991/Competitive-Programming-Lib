#include <bits/stdc++.h>
using namespace std;

class UnionFind {
   public:
    int count = 0, extraCount = 0;
    vector<int> parent, rank;
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i, rank[i] = 0;
    }

    int getParent(int u) {
        while (u != parent[u]) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    }

    void makeUnion(int u, int v) {
        int pu = getParent(u);
        int pv = getParent(v);
        if (pu == pv) {
            extraCount++;
            return;
        }

        count--;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            if (rank[pu] == rank[pv]) {
                rank[pu]++;
            }
        }
    }
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>> &cn) {
        UnionFind *unionFind = new UnionFind(n);
        for (vector<int> &x : cn) {
            unionFind->makeUnion(x[0], x[1]);
        }

        if (unionFind->extraCount < unionFind->count - 1) {
            return -1;
        } else {
            return unionFind->count - 1;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cn(2, vector<int>(2));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++) cin >> cn[i][j];
    cout << (new Solution())->makeConnected(n, cn);
}
