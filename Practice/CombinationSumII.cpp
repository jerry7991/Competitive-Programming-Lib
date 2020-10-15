#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, int target, vector<vector<int>> *output, vector<int> &curr, int index = 0) {
    if (target == 0) {
        output->push_back(curr);
        return;
    }
    if (index >= arr.size()) return;
    for (int i = index; i < arr.size(); i++) {
        if (arr[i] > target) return;
        if (i && arr[i] == arr[i - 1] && i > index) continue;
        curr.push_back(arr[i]);
        solve(arr, target - arr[i], output, curr, i + 1);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> *output = new vector<vector<int>>();
    vector<int> v;
    solve(candidates, target, output, v);
    return *output;
}
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int target;
        cin >> target;
        vector<vector<int>> output = combinationSum2(v, target);
        for (auto x : output) {
            for (auto y : x) cout << y << ' ';
            cout << '\n';
        }
    }
    return 0;
}
