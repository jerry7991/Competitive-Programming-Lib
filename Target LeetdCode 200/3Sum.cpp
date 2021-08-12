#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> trip;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    while (l < r && nums[l] == triplet[1]) l++;
                    while (l < r && nums[r] == triplet[2]) r--;
                    trip.push_back(triplet);
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return trip;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> x = (new Solution())->threeSum(nums);
    for (vector<int> y : x) {
        for (int z : y) cout << z << " ";
        cout << endl;
    }
}