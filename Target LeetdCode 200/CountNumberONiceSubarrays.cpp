#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), kCount = 0, count = 0, prefix = 0;
        while (r < n) {
            // increase odd count
            kCount += (nums[r++] & 1);
            if (kCount > k) {
                l++;
                kCount--;
                prefix = 0;
            }

            // Count the number of prefix which is even because either we include them or not still we get the nice one
            while (l < r && (nums[l] % 2 == 0)) prefix++, l++;
            if (kCount == k) {
                count += (1 + prefix);
            }
        }
        return count;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->numberOfSubarrays(nums, k) << endl;
}