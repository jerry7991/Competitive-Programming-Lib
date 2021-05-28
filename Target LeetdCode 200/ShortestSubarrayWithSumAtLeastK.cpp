#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), len = n + 1;
        vector<int> prefixSum(n + 1);
        deque<int> dq;
        prefixSum[0] = 0;
        for (int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + nums[i];

        for (int i = 0; i <= n; i++) {
            // Remove extra
            while (dq.size() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                len = min(len, i - dq.front());
                dq.pop_front();
            }

            //  In case any -ve
            while (dq.size() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        return len >= n + 1 ? -1 : len;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->shortestSubarray(nums, k);
}
