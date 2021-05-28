#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, j = 0, count = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum > goal) {
                sum -= nums[j++];
            }
            if (sum == goal && j <= i) {
                count++;
                int k = j;
                while (k < i && !nums[k]) k++, count++;
            }
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), ans = 0;
        vector<int> sum(n + 1);
        sum[0] = 0;
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];

        unordered_map<int, int> seen;
        for (int x : sum) {
            ans += seen[x];
            seen[x + goal]++;
        }
        return ans;
    }
};

int main() {
}