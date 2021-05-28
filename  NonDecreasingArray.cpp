#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    int n = nums.size(), count = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) {
            count++;
            if (i - 2 < 0 || nums[i - 2] <= nums[i])
                nums[i - 1] = nums[i];
            else
                nums[i] = nums[i - 1];
        }
    }
    return count <= 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << checkPossibility(nums);
}