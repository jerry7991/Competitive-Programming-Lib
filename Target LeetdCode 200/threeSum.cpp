#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        int front = i + 1, back = n - 1;
        int target = -nums[i];
        while (front < back) {
            // cout<<nums[i]<<" "<<nums[front]<<" "<<nums[back]<<endl;
            int sum = nums[front] + nums[back];
            if (sum < target) {
                front++;
            } else if (sum > target) {
                back--;
            } else {
                vector<int> triplet = {nums[i], nums[front], nums[back]};
                ans.push_back(triplet);
                while (front < back && nums[front] == triplet[1]) front++;
                while (front < back && nums[back] == triplet[2]) back--;
            }
        }
        while (i + 1 < n && nums[i] == nums[i + 1]) i++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> ans = threeSum(nums);
}