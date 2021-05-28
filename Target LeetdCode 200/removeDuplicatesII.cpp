#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), len = 0, i = 0;

    for (int x : nums) {
        if (i < 2 || x > nums[i - 2])
            nums[i++] = x;
    }
    return i;
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