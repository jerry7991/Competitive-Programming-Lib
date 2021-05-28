#include <bits/stdc++.h>
using namespace std;

static bool compare(string &str1, string &str2) {
    return str1.size() < str2.size();
}

string longestWord(vector<string> &words) {
    unordered_set<string> dp(words.begin(), words.end());

    int len = -1;
    string out = "";
    for (string &str : words) {
        int i = 0;
        for (; i < str.size(); i++) {
            if (dp.count(str.substr(0, i)) == 0)
                break;
        }
        if (i == str.size()) {
            if (len == i) {
                out = (out > str) ? str : out;
            } else if (len < i) {
                len = i;
                out = str;
            }
        }
    }
    return len < 0 ? "" : out;
}

int main() {
}