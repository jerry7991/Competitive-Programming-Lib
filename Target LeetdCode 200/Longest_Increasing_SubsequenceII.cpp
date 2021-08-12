#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                int j = 0;
                while (sub[j] < nums[i]) j++;
                sub[j] = nums[i];
            }
        }
        return sub.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->lengthOfLIS(nums);
}