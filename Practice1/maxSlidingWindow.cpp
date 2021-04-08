#include <bits/stdc++.h>
using namespace std;
int getMax(vector<int>& nums, int start, int end) {
    int ans = INT_MIN;
    while (start <= end) {
        ans = max(ans, nums[start]);
    }
    return ans;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> out;
    for (int i = k; i < n; i++) {
        out.push_back(getMax(nums, i - k, k));
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;
    vector<int> out = maxSlidingWindow(v, k);
    for (int i : out) cout << i << " ";
}