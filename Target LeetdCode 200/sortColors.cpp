#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int start = 0, mid = 0, end = n - 1;
    while (mid <= end) {
        if (nums[mid] == 0) {
            swap(nums[start], nums[mid]);
            start++;

            //  Assumption is nums[i]<2 for all i[start,mid],
            //  nums[mid] will be 1 after swapping for nums[start]
            mid++;
        } else if (nums[mid] == 2) {
            swap(nums[mid], nums[end]);

            //  Assumption is nums[end]>2 for all i[mid, end],
            //  we don't know about nums[mid] it can be 0 or 1. So it's better to recheck
            end--;
        } else if (nums[mid] == 1) {
            mid++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sortColors(nums);

    for (int x : nums) cout << x << " ";

    return 0;
}
