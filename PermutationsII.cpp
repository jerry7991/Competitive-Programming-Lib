#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &pmt, string &str, vector<int> &nums, int i, unordered_set<string> &seen) {
    if (i == str.size()) {
        if (!seen.count(str)) {
            seen.insert(str);
            pmt.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            swap(str[i], str[j]);
            solve(pmt, str, nums, i + 1, seen);
            swap(nums[i], nums[j]);
            swap(str[i], str[j]);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> pmt;
    string str = "";
    for (int i : nums) str.append(to_string(i));
    unordered_set<string> seen;
    solve(pmt, str, nums, 0, seen);
    return pmt;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    auto out = permuteUnique(nums);
    for (auto x : out) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}