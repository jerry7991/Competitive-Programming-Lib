#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, sum = 0, maxSum = 0;
        unordered_map<int, int> seen;

        while (r < n) {
            if (seen.count(nums[r]) == 0) {
                seen[nums[l]]--;
                sum -= nums[l++];
            } else {
                seen[nums[r]]++;
                sum += nums[r++];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->maximumUniqueSubarray(nums);
}