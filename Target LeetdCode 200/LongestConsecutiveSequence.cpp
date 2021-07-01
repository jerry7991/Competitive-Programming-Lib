#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void doDfs(unordered_set<int>& visited, unordered_map<int, vector<int>>& edges, int u, int& d) {
        visited.insert(u);
        d++;
        for (auto x : edges[u]) {
            if (visited.find(x) == visited.end() && edges.count(x)) {
                doDfs(visited, edges, x, d);
            }
        }
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, vector<int>> edges;
        unordered_set<int> visited;
        for (int x : nums) {
            edges[x] = {x + 1, x - 1};
        }
        int ans = 0;
        for (auto x = edges.begin(); x != edges.end(); x++) {
            if (visited.find(x->first) == visited.end()) {
                int curr = 0;
                doDfs(visited, edges, x->first, curr);
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->longestConsecutive(nums);
}