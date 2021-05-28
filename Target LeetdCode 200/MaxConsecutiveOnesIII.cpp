#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, one = 0, n = nums.size(), finalOne = 0;
        while (r < n) {
            if (k == 0 && nums[r] ^ 1) {
                k += (nums[l++] ^ 1);
                one--;
            } else {
                k -= (nums[r++] ^ 1);
                one++;
                finalOne = max(one, finalOne);
            }
        }
        return finalOne;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->longestOnes(nums, k);
    return 0;
}