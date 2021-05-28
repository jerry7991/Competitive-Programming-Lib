#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size(), res = INT_MAX;
        if (n == 1) {
            return nums[0] == x ? 1 : -1;
        }
        unordered_map<int, int> seen;
        for (int i = 0; i < n && sum <= x; i++) {
            seen[sum] = i;
            sum += nums[i];
        }

        for (int i = n - 1, sum = 0; i >= 0 && sum <= x; i--) {
            if (seen.count(x - sum) && i + 1 >= seen[x - sum]) {
                res = min(res, n - i - 1 + seen[x - sum]);
            }
            sum += nums[i];
        }
        return res == INT_MAX ? -1 : res;
    }

    //  Two sum
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(begin(nums), end(nums), 0);

        int l = 0, r = 0, res = INT_MAX, n = nums.size();
        while (l <= r) {
            if (sum >= x) {
                if (sum == x) {
                    res = min(res, l - r + n);
                }
                if (r < n) {
                    sum -= nums[r++];
                } else {
                    break;
                }
            } else {
                sum += nums[l++];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->minOperations(nums, k) << endl;
}