#include <bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr, int target, vector<vector<int> >& output, vector<int> curr, int index = 0) {
    if (target == 0) {
        output.push_back(curr);
        return;
    }
    if (index == arr.size()) {
        return;
    }
    for (int i = index; i < arr.size(); i++) {
        if (arr[i] <= target) {
            curr.push_back(arr[i]);
            solve(arr, target - arr[i], output, curr, i);
            curr.pop_back();
        }
    }
}
vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > output;
    vector<int> curr;
    solve(candidates, target, output, curr);
    return output;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;
    vector<vector<int> > output = combinationSum(v, k);
    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < output[i].size(); j++) cout << output[i][j] << " ";
        cout << endl;
    }
}