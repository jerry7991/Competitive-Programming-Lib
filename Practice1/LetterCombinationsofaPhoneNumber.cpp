#include <bits/stdc++.h>
using namespace std;

vector<string> data = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> solve(string digits, int i) {
    if (i < 0) {
        return {""};
    }
    vector<string> curr = solve(digits, i - 1);
    vector<string> out;
    for (int k = 0; k < curr.size(); k++) {
        for (int j = 0; j < data[digits[i] - '0'].size(); j++) {
            out.push_back(curr[k] + data[digits[i] - '0'][j]);
        }
    }
    return out;
}
vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
        return {};
    }
    return solve(digits, digits.size() - 1);
}

int main() {
    string d;
    cin >> d;
    vector<string> out = letterCombinations(d);
    for (string str : out) cout << str << " ";
}