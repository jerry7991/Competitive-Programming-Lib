#include <bits/stdc++.h>
using namespace std;

/*
    So we can have option to choose from left or right.
    So nums[0...i.....n], we want max of sum(nums[0..x]0+sum(nums[y...n]) such that (x-0+1)+(n-y+1) == k

    So what we can do we can take a sliding window of in beteween x--y and find the sum. 
    So for sum(nums[0..x]0+sum(nums[y...n]) = totalSum- sum[x-y];
    And we want this max.
*/

int maxScore(vector<int>& nums, int k) {
    int totalSum = 0, n = nums.size(), windowSum = 0, maxSum = 0;
    for (int i = 0; i < n; i++) totalSum += nums[i];

    // Get the window sum
    for (int i = 0; i < n - k; i++) {
        windowSum += nums[i];
    }

    // Keep margin between i and j
    for (int i = n - k, j = 0; i < n; i++, j++) {
        maxSum = max(maxSum, totalSum - windowSum);
        windowSum += nums[i] - nums[j];
    }
    // Check for last time when window changed
    maxSum = max(maxSum, totalSum - windowSum);

    return maxSum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    cout << maxScore(num, k);
}