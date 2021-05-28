#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, slow = 0, fast = 0, count = nums.size() + 1;

        while (fast < nums.size()) {
            sum += nums[fast++];
            while (sum >= (target + nums[slow])) sum -= nums[slow++];
            if (sum >= target) count = min(count, fast - slow);
        }
        return count == nums.size() + 1 ? 0 : count;
    }
};

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->minSubArrayLen(t, nums);
}
