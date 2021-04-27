#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr = curr + nums[i];
        ans = max(ans, curr);
        curr = max(0, curr);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << maxSubArray(v);
}