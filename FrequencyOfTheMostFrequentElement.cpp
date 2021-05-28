#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    int n = nums.size(), count = 1;

    sort(nums.begin(), nums.end());

    for (int i = n - 1, j = i; i > 0; --i) {
        for (; j >= 0 && k >= (nums[i] - nums[j]); --j) {
            k -= (nums[i] - nums[j]);
        }
        count = max(count, i - j);
        k += (nums[i] - nums[i - 1]) * (i - j - 1);  // Let them rest as same
    }

    return count;
}

int maxFrequency(vector<int>& nums, int k) {
    int left = 0, right, n = nums.size(), count = 1;
    long long sum = 0;
    sort(nums.begin(), nums.end());
    for (right = 0; right < n; right++) {
        sum += nums[right];

        //  Find the window which sum same as if we change all [0...right] with nums[right]
        while (sum + k < (long long)nums[right] * (right - left + 1)) {
            sum -= nums[left];
            left++;
        }

        count = max(count, right - left + 1);
    }
    return count;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;
    cout << maxFrequency(nums, k);
}

//https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175090/JavaC%2B%2BPython-Sliding-Window
