#include <bits/stdc++.h>
using namespace std;

bool compare(pair<char, int> pr1, pair<char, int> pr2) {
    return pr1.second > pr2.second;
}

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char ch : s) freq[ch]++;
    vector<pair<char, int>> v;
    for (pair<char, int> pr : freq) {
        v.push_back(pr);
    }
    sort(v.begin(), v.end(), compare);
    string str = "";
    for (pair<char, int> pr : v) {
        char ch = pr.first;
        int n = pr.second;
        while (n--) {
            str.push_back(ch);
        }
    }
    return str;
}
int main() {
    string str;
    cin >> str;
    cout << frequencySort(str);
}