#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> out(n - k + 1);
    map<int, int> window;
    for (int i = 0; i < k - 1; i++) window[nums[i]]++;

    for (int i = k - 1; i < n; i++) {
        window[nums[i]]++;
        out[i - k + 1] = window.rbegin()->first;
        if (window[nums[i - k + 1]] == 1) {
            window.erase(nums[i - k + 1]);
        } else {
            window[nums[i - k + 1]]--;
        }
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