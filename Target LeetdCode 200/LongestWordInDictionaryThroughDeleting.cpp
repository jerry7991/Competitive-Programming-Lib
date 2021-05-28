#include <bits/stdc++.h>
using namespace std;

bool compare(string& str1, string& str2) {
    if (str1.size() == str2.size()) {
        return str1 < str2;
    }
    return str1.size() > str2.size();
}

string findLongestWord(string s, vector<string>& dictornary) {
    //char pointer and int for index in dictornary
    vector<pair<const char*, int>> dp[128];
    int i = 0;
    for (string& str : dictornary) {
        dp[str[0]].push_back({str.c_str(), i++});
    }

    for (char ch : s) {
        auto curr = dp[ch];
        dp[ch].clear();
        for (auto it : curr) {
            auto itr = it.first;
            dp[*++itr].push_back({itr, it.second});
        }
    }
    vector<string> complete;
    for (auto x : dp[0]) {
        complete.push_back(dictornary[x.second]);
    }
    sort(complete.begin(), complete.end(), compare);
    return complete.size() ? complete[0] : "";
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> data(n);
    for (int i = 0; i < n; i++) cin >> data[i];
    cout << findLongestWord(s, data);
}