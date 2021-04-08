#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t) {
    int n = s.length(), m = t.length();
    int left = 0, right = 0, ok = 0;
    int ans = INT_MAX, startIndex = 0, endIndex = 0, prevLen = -1;
    unordered_map<char, int> totalPresent;
    unordered_map<char, int> currPresent;
    for (char ch : t) totalPresent[ch]++;
    m = totalPresent.size();
    while (right < n) {
        currPresent[s[right]]++;
        if (totalPresent.count(s[right]) && currPresent[s[right]] == totalPresent[s[right]]) {
            ok++;
        }
        while (left <= right && ok == m) {
            if (prevLen < 0 || (right - left + 1) < prevLen) {
                prevLen = (right - left + 1);
                startIndex = left;
                endIndex = right;
            }
            cout << startIndex << " " << endIndex << " " << prevLen << endl;
            currPresent[s[left]]--;
            if (currPresent[s[left]] < totalPresent[s[left]]) {
                ok--;
            }
            left++;
        }
        right++;
    }
    return (prevLen < 0) ? "" : s.substr(startIndex, endIndex - startIndex + 1);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t);
}