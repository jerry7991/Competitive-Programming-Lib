#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int balancedString(string s) {
        vector<int> count(27, 0);
        for (char ch : s) count[ch - 'A']++;

        int l = 0, r = 0, n = s.size(), k = n / 4, ans = n;

        while (r < n) {
            --count[s[r] - 'A'];

            while (l < n && count['Q' - 'A'] <= k && count['R' - 'A'] <= k && count['E' - 'A'] <= k && count['W' - 'A'] <= k) {
                ans = min(ans, r - l + 1);
                count[s[l] - 'A']++;
                l++;
            }
            r++;
        }
        return ans;
    }
};

int main() {
    string str;
    cin >> str;
    cout << (new Solution())->balancedString(str) << endl;
}