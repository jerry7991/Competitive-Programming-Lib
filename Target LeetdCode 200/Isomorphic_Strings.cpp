#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> st, ts;
        for (int i = 0; i < n; i++) {
            if (st.count(s[i]) && st[s[i]] != t[i]) {
                return false;
            } else {
                if (ts.count(t[i]) && ts[t[i]] != s[i]) return false;
                st[s[i]] = t[i];
                ts[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << (new Solution())->isIsomorphic(s, t);
}