#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findErrorNums(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                return {nums[i], i + 1};
            }
        }
        return {};
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution* slv = new Solution();
    vector<int> out = slv->findErrorNums(nums);
    for (int x : out) cout << x << endl;
}