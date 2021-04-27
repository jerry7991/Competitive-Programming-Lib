#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), count = 0;
    vector<int> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (sum[j] - sum[i - 1] == k) count++;
        }
    }
    return count;
}

int subarraySumOP(vector<int>& nums, int k) {
    int n = nums.size(), count = 0;
    unordered_map<int, int> visSum;
    int sum = 0;
    visSum[0]++;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        count += visSum[sum - k];
        visSum[sum]++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;
    cout << subarraySum(nums, k);
}