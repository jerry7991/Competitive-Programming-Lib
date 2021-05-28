#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &pmt, vector<int> nums, int i) {
    if (i == nums.size()) {
        pmt.push_back(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++) {
        if (i != j && nums[i] == nums[j]) continue;
        swap(nums[i], nums[j]);
        solve(pmt, nums, i + 1);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> pmt;
    solve(pmt, nums, 0);
    return pmt;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    auto out = permute(nums);
    for (auto x : out) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}