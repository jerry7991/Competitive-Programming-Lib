#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            count += (nums[i] == nums[j]);
        }
    }
    return count;
}

int numIdenticalPairs(vector<int>& nums) {
    int count = 0;
    vector<int> fre(101, 0);
    for (int x : nums) {
        count += fre[x]++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << numIdenticalPairs(nums);
}