#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countPairs(vector<int>& d) {
        unordered_map<int, int> freq;
        int count = 0, n = d.size(), m = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 21; j++) {
                int power = 1 << j;
                if (freq.find(power - d[i]) != freq.end()) {
                    count += freq[power - d[i]];
                }
                count %= m;
            }
            freq[d[i]]++;
        }
        return count;
    }
};

int main() {
    Solution* sl = new Solution();
    int n;
    cin >> n;
    vector<int> deliciousness(n);
    for (int i = 0; i < n; i++) cin >> deliciousness[i];
    cout << sl->countPairs(deliciousness);
}
