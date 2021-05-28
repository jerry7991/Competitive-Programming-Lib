#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX, n = nums.size(), l = 0, r = n - 1, sum = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            l = 0, r = n - 1;
            while (l < r) {
                int s = nums[l] + nums[r] + nums[i];
                if (abs(target - s) < closest) {
                    sum = s;
                }
                if (s > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return sum;
    }
};

int main() {
}