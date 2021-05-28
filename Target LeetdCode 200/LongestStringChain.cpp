#include <bits/stdc++.h>
using namespace std;

bool compare(string &str1, string &str2) {
    return str1.size() < str2.size();
}

int longestStrChain(vector<string> &words) {
    sort(begin(words), end(words), compare);
    unordered_map<string, int> dp;
    int res = 0;
    for (string &word : words) {
        for (int i = 0; i < word.size(); i++) {
            string str = word.substr(0, i) + word.substr(i + 1);
            dp[word] = max(dp[word], dp[str] + 1);
        }
        res = max(res, dp[word]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    cout << longestStrChain(words);
}