#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    int count = 0;

    for (int x : nums) {
        if (x == k - x && freq[x] >= 2) {
            count++;
            freq[x] -= 2;
        } else if (x != k - x && freq[x] && freq[k - x]) {
            count++;
            freq[x]--;
            freq[k - x]--;
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << maxOperations(nums, k);
}