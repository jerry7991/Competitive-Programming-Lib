#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        int m = (l + r) / 2;
        if (nums[m] > nums[m + 1]) return search(nums, l, m);
        return search(nums, m + 1, r);
    }

    int findPeakElement(vector<int>& nums) {
        search(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << (new Solution())->findPeakElement(nums);
}