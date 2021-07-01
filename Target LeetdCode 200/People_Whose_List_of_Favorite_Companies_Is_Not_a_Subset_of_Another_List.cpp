#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> peopleIndexes(vector<vector<string>>& str) {
        for (int i = 0; i < str.size(); i++) sort(str[i].begin(), str[i].end());
        sort(str.begin(), str.end());
        vector<int> out;
        for (int i = 0; i < str.size(); i++) {
            int flag = true;
            for (int j = 0; j < str.size() && !flag; j++) {
                if (i == j) continue;
                flag = !includes(str[i].begin(), str[i].end(), str[j].begin(), str[j].end());
            }
            if (flag) out.push_back(i);
        }
        return out;
    }

    vector<int> peopleIndexes(vector<vector<string>>& str) {
        unordered_map<string, int> ump;
        int id = 1, n = str.size();
        for (auto& x : str) {
            for (auto& y : x) {
                if (ump.count(y)) continue;
                ump[y] = id++;
            }
        }

        vector<bitset<50001>> vec;
        for (auto& x : str) {
            bitset<50001> bt;
            for (auto& y : x) bt[ump[y]] = 1;
            vec.push_back(bt);
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n && flag; j++) {
                if (i == j) continue;
                if ((vec[i] & vec[j]) == vec[i]) flag = false;
            }
            if (flag) res.push_back(i);
        }
        return res;
    }
};

int main() {
    vector<vector<string>> fCom = {{"leetcode", "google", "facebook"}, {"google", "microsoft"}, {"google", "facebook"}, {"google"}, {"amazon"}};
    vector<int> x = (new Solution())->peopleIndexes(fCom);
    for (int i : x) cout << i << " ";
}