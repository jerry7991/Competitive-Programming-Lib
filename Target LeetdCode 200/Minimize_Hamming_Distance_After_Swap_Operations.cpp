#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void getConnectedComp(vector<vector<int>>& edge, vector<bool>& seen, vector<int>& comp, int src) {
        seen[src] = true;
        comp.push_back(src);
        for (auto x : edge[src]) {
            if (!seen[x]) {
                getConnectedComp(edge, seen, comp, x);
            }
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& swaps) {
        int n = source.size(), count = 0;
        vector<vector<int>> edge(n, vector<int>());
        vector<bool> seen(n, false);
        for (auto x : swaps) {
            edge[x[0]].push_back(x[1]);
            edge[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;
            vector<int> comp;
            getConnectedComp(edge, seen, comp, i);
            vector<int> st2;
            unordered_map<int, int> st1;
            for (int x : comp) st1[source[x]]++, st2.push_back(target[x]);
            for (auto x : st2) {
                if (st1[x] == 0) {
                    count++;
                } else if (st1[x] == 1) {
                    st1.erase(x);
                } else {
                    st1[x]--;
                }
            }
        }
        return count;
    }
};

int main() {
}