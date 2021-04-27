#include <bits/stdc++.h>
using namespace std;

vector<int> avoidFlood(vector<int>& rains) {
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> out = avoidFlood(nums);
    for (int i : out) cout << i << " ";
}