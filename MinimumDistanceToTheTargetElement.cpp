#include <bits/stdc++.h>
using namespace std;

int getMinDistance(vector<int>& nums, int target, int start) {
    int left = start, right = start, n = nums.size();

    while (left >= 0 && right < n) {
        if (nums[left] == target) {
            return (start - left);
        }
        if (nums[right] == target) {
            return (right - start);
        }
        left--;
        right++;
    }
    while (left >= 0) {
        if (nums[left] == target) {
            return (start - left);
        }
        left--;
    }

    while (right < n) {
        if (nums[right] == target) {
            return (right - start);
        }
        right++;
    }
    return start;
}

int main() {
    int target, start, n;
    cin >> target >> start >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << getMinDistance(nums, target, start);
}