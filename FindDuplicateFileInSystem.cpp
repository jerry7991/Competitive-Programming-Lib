#include <bits/stdc++.h>
using namespace std;

vector<string> splitStr(string& str) {
    vector<string> output;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        output.push_back(word);
    }
    return output;
}

pair<string, string> splitFile(string& str) {
    int i = 0;
    for (; i < str.size(); i++) {
        if (str[i] == '(') break;
    }
    return {str.substr(0, i), str.substr(i + 1, str.size() - 2)};
}

vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> ump;
    for (int i = 0; i < paths.size(); i++) {
        vector<string> filsplit = splitStr(paths[i]);
        string path = filsplit[0];
        for (int j = 1; j < filsplit.size(); j++) {
            pair<string, string> p = splitFile(filsplit[j]);
            ump[p.second].push_back(path + "/" + p.first);
        }
    }
    vector<vector<string>> ans;
    for (auto x : ump) {
        if (x.second.size() > 1)
            ans.push_back(x.second);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> path(n);
    for (int i = 0; i < n; i++) {
        cin >> path[i];
    }
    auto x = findDuplicate(path);
    for (auto y : x) {
        for (auto z : y) cout << z << " ";
        cout << endl;
    }
}