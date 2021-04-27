#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> last = {{0, -1}};

    int s = 0;

    for (int i = 0; i < n; i++) {
        s = (s + nums[i]) % k;
        if (last.count(s)) {
            if (i - last[s] > 1)
                return true;
        } else {
            last[s] = i;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;
    cout << checkSubarraySum(nums, k);
}