#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> sumInd;

    vector<int> out;
    for (int i = 0; i < nums.size(); i++) {
        if (sumInd.count(target - nums[i])) {
            out.push_back(i);
            out.push_back(sumInd[target - nums[i]]);
            // return out;
            break;
        }
        sumInd[nums[i]] = i;
    }
    return out;
}

int main() {
    int n, tar;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> tar;

    vector<int> out = twoSum(nums, tar);
    for (int i : out) cout << i << " ";
}