#include <bits/stdc++.h>
using namespace std;

bool solve(string &s, string &t, int i, int j) {
    if (i == s.size()) {
        return true;
    }
    if (j == t.size()) {
        return false;
    }
    if (s[i] == t[j])
        return solve(s, t, i + 1, j + 1);
    else
        return solve(s, t, i, j + 1);
}

bool isSubsequence(string s, string t) {
    // return solve(s, t, 0, 0);
    int i = 0, j = 0;
    while (j < t.size() && i < s.size()) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    return i == s.size();
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << isSubsequence(s, t);
}