#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>> week;
        for (int i = 0; i < mat.size(); i++) {
            week.insert({accumulate(begin(mat[i]), end(mat[i]), 0), i});
        }

        vector<int> ans;
        auto it = week.begin();
        for (int i = 0; i < k; i++, it++) ans.push_back(it->second);
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> nums(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> nums[i][j];
    }
    vector<int> out = (new Solution())->kWeakestRows(nums, k);

    for (int x : out)
        cout << x << " ";
}