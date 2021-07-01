#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] != nums[i + 1]) {
                ans += (n - i - 1);
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
    cout << (new Solution())->reductionOperations(nums);
}