#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum1 = target - (nums[i] + nums[j]);
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int sum2 = (nums[l] + nums[r]);
                    if (sum2 > sum1) {
                        r--;
                    } else if (sum2 < sum1) {
                        l++;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        while (l < r && nums[l] == temp[2]) l++;
                        while (l < r && nums[r] == temp[3]) r--;
                        out.push_back(temp);
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return out;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    auto x = (new Solution())->fourSum(nums, k);

    for (auto y : x) {
        for (auto z : y) cout << z << " ";
        cout << endl;
    }
}