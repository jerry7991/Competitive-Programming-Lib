#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    int count = 0;
    vector<int> parent, rank;

   public:
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i, rank[i] = 0;
    }

    int findParent(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];  // Path compression
            p = parent[p];
        }
        return p;
    }

    void makeUnion(int p, int q) {
        int pp = findParent(p);
        int pq = findParent(q);
        if (pp == pq) return;
        if (rank[pq] > rank[pp]) {
            parent[pp] = pq;
        } else {
            parent[pq] = pp;
            if (rank[pq] == rank[pq]) {
                rank[pp]++;
            }
        }
        count--;
    }

    int getCountRoot() {
        return count;
    }
};

class Solution {
   public:
    int getParent(vector<int>& parent, int i) {
        if (parent[i] != i) {
            return parent[i] = getParent(parent, parent[i]);
        }
        return i;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!isConnected[i][j]) continue;
                int pi = getParent(parent, i);
                int pj = getParent(parent, j);
                if (pi != pj) {
                    parent[pj] = pi;
                }
            }
        }
        for (int i = 0; i < n; i++) ans += (parent[i] == i);
        return ans;
    }

    // Most optimise
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind* unionFind = new UnionFind(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) unionFind->makeUnion(i, j);
            }
        }
        return unionFind->getCountRoot();
    }
};

int main() {
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << (new Solution())->findCircleNum(isConnected);
}