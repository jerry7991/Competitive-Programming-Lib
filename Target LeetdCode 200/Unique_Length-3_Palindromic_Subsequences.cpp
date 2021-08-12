#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countPalindromicSubsequence(string s) {
        const int infinity = 1e9 + 5, n = s.size();
        vector<int> first(26, infinity), last(26);
        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] < last[i])
                res += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    cout << (new Solution())->countPalindromicSubsequence(s);
}