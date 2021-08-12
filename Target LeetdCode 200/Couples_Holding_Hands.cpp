#include <bits/stdc++.h>
using namespace std;
class UnionFind {
   public:
    int cnt;
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        cnt = n;
    }
    int getParent(int u) {
        if (u != parent[u]) {
            return parent[u] = getParent(parent[u]);
        }
        return u;
    }
    void makeUnion(int u, int v) {
        int pu = getParent(u), pv = getParent(v);
        if (pu != pv) {
            cnt--;
            parent[pu] = pv;
        }
    }
    int getCount() {
        return cnt; 
    }
}; 

class Solution {
   public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        UnionFind* uf = new UnionFind(n);
        for (int i = 0; i < n; i++) {
            int a = row[2 * i], b = row[2 * i + 1];
            uf->makeUnion(a / 2, b / 2);
        }
        return uf->getCount();
    }
};