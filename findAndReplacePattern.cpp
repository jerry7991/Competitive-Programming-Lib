#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool isValid(string &word, string &pattern) {
        unordered_map<char, char> mapped;
        for (int i = 0; i < word.size(); i++) {
            if (mapped.count(word[i]) == 0) {
                mapped[word[i]] = pattern[i];
            }
            if (mapped[word[i]] != pattern[i]) {
                return false;
            }
        }

        vector<bool> seen(26, false);

        for (auto x : mapped) {
            if (seen[x.second - 'a']) return false;
            seen[x.second - 'a'] = true;
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> output;
        for (string &str : words) {
            if (isValid(str, pattern)) output.push_back(str);
        }
        return output;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    string str;
    cin >> str;

    vector<string> out = (new Solution())->findAndReplacePattern(words, str);
    for (string str : out) cout << str << " ";
}