#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int slow = 0, fast = 0;
    while (fast < n) {
        if (nums[slow] != nums[fast]) {
            swap(nums[slow], nums[fast]);
            fast++;
        }
        while (fast < n && nums[slow] == nums[fast]) fast++;
        slow++;
    }
    return slow;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << removeDuplicates(nums);
}