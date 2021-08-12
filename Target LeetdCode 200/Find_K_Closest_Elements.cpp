#include <bits/stdc++.h>

using namespace std;
class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPq;
        for (int i = 0; i < arr.size(); i++) {
            minPq.push({abs(x - arr[i]), i});
        }
        vector<int> out;
        while (k--) {
            out.push_back(arr[minPq.top().second]);
            minPq.pop();
        }
        sort(out.begin(), out.end());
        return out;
    }
};

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> out = (new Solution())->findClosestElements(arr, k, x);
    return 0;
}