#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int count = 0;
    string findParent(unordered_map<string, string> &parent, string &u) {
        while (parent[u] != u) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return parent[u];
    }

    void makeUnion(unordered_map<string, string> &parent, string &u, string &v) {
        string parentU = findParent(parent, u);
        string parentV = findParent(parent, v);
        if (parentU == parentV) return;
        parent[parentV] = parentU;
        count--;
    }

    int removeStones(vector<vector<int>> &stones) {
        count = stones.size();
        unordered_map<string, string> parent;
        for (vector<int> &x : stones) {
            string str = to_string(x[0]) + " " + to_string(x[1]);
            parent[str] = str;
        }
        for (vector<int> &x : stones) {
            string str = to_string(x[0]) + " " + to_string(x[1]);
            for (vector<int> &y : stones) {
                if (x[0] == y[0] || x[1] == y[1]) {
                    string st = to_string(y[0]) + " " + to_string(y[1]);
                    makeUnion(parent, str, st);
                }
            }
        }
        return stones.size() - count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> stones(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++) cin >> stones[i][j];
    cout << (new Solution())->removeStones(stones);
}