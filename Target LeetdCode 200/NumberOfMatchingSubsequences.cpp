#include <bits/stdc++.h>
using namespace std;

int numMatchingSubseq(string s, vector<string>& words) {
    vector<const char*> wait[128];
    for (auto& w : words) {
        wait[w[0]].push_back(w.c_str());
    }

    for (char ch : s) {
        auto advance = wait[ch];
        wait[ch].clear();
        for (auto it : advance) {
            wait[*++it].push_back(it);
        }
    }
    return wait[0].size();
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    cout << numMatchingSubseq(s, words);
}