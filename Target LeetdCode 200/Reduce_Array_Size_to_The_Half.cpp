#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> fre(1e5 + 2);
        for (int i : arr) fre[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHp;

        for (int i = 0; i < fre.size(); i++) {
            if (fre[i])
                maxHp.push({fre[i], i});
        }
        int removed = 0, count = 0;
        while (maxHp.size()) {
            int f = maxHp.top().first;
            maxHp.pop();
            removed += f;
            count++;
            if (removed >= n / 2) {
                return count;
            }
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << (new Solution())->minSetSize(arr);
}