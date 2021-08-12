#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] == 0) continue;
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    ans += (r - l);
                    r--;
                } else
                    l++;
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
    cout << (new Solution())->triangleNumber(nums);
}