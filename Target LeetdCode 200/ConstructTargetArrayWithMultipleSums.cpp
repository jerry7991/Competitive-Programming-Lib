#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& target) {
    int n = target.size();
    auto s = accumulate(begin(target), end(target), (long long)0);
    priority_queue<int> pq(begin(target), end(target));
    while (s > 1 && pq.top() > s / 2) {
        auto curr = pq.top();
        pq.pop();
        s -= curr;
        if (s <= 1) {
            return s;
        }
        pq.push(curr % s);
        s += curr % s;
    }
    return s == target.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << isPossible(nums);
}