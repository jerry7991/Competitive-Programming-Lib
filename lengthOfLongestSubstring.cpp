#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> last;
    int n = s.size(), ans = 0, start = 0;

    for (int i = 0; i < n; i++) {
        if (last.count(s[i])) {
            start = max(start, last[s[i]] + 1);
        }
        ans = max(ans, i - start + 1);
        last[s[i]] = i;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
}