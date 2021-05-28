#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> fre;
    for (int x : nums) fre[x]++;

    vector<int> ans;

    priority_queue<pair<int, int>> pq;
    for (auto x : fre) {
        pq.push({x.second, x.first});
        if (pq.size() > ((int)fre.size() - k)) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
}