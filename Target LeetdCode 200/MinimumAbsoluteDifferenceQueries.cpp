#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> counts(1e5 + 1, vector<int>(101, 0));

class Solution {
   public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 101; j++) counts[i][j] = counts[i - 1][j];
            counts[i][nums[i - 1]] = counts[i - 1][nums[i - 1]] + 1;
        }

        n = queries.size();
        vector<int> cnt(101);
        vector<int> out(n);
        for (int i = 0; i < n; i++) {
            int l = queries[i][0], r = queries[i][1], ans = 102, last = -1;

            for (int j = 1; j < 101; j++) {
                cnt[j] = counts[r + 1][j] - counts[l][j];
            }

            for (int i = 1; i < 101; i++) {
                if (cnt[i] != 0) {
                    if (last != -1) {
                        ans = min(ans, i - last);
                    }
                    last = i;
                }
            }
            if (ans == 102 || ans == 0)
                out[i] = -1;
            else
                out[i] = ans;
        }
        return out;
    }
};

int main() {
}