#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> seen(nums.size() + 1);
        int count = 0, l = 0, r = 0, prefix = 0, n = nums.size(), ans = 0;
        while (r < n) {
            if (seen[nums[r]]++ == 0) count++;
            if (count > k) {
                --count;
                --seen[nums[l++]];
                prefix = 0;
            }
            while (seen[nums[l]] > 1) {
                --seen[nums[l++]];
                ++prefix;
            }
            if (count == k)
                ans += (1 + prefix);
            r++;
        }
        return prefix;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->subarraysWithKDistinct(nums, k) << endl;
    return 0;
}