#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int binarySearch(vector<int>& nums, int x) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < x) {
                l = m + 1;
            } else if (nums[m] > x) {
                r = m;
            } else {
                return m;
            }
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                int j = binarySearch(sub, nums[i]);
                sub[j] = nums[i];
            }
        }
        return sub.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->lengthOfLIS(nums);
}