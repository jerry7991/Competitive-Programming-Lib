#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int maxF = 0, l = 0, r = 0, n = s.size();
        vector<int> count(26, 0);
        while (r < n) {
            maxF = max(maxF, ++count[s[r] - 'A']);

            if (r - l + 1 > maxF + k) {
                count[s[l] - 'A']--;
                l++;
            }

            r++;
        }
        return n - l;
    }
};

int main() {
    string str;
    int k;
    cin >> str >> k;
    cout << (new Solution())->characterReplacement(str, k) << endl;
    return 0;
}
