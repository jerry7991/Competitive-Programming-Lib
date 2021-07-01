#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            while (dq.size() && i - dq.front() > k) dq.pop_front();

            if (dq.size()) nums[i] += nums[dq.front()];

            while (dq.size() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        return nums.back();
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->maxResult(nums, k);
}