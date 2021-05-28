#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int start = 0, i = n - 2;
    int j = n - 1;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i > 0) {
        while (j >= 0 && nums[j] <= nums[i]) j--;
        swap(nums[i++], nums[j]);
    }
    j = n - 1;
    while (i < j) swap(nums[i++], nums[j--]);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    nextPermutation(nums);
    for (int x : nums) {
        cout << x << " ";
    }
}