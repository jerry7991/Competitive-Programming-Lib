#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(unordered_set<string>& res, string& str, int leftCount, int rightCount, int index, string path, int pair) {
        if (index == str.size()) {
            if (leftCount == 0 && rightCount == 0 && pair == 0) {
                res.insert(path);
            }
            return;
        }

        if (str[index] != '(' && str[index] != ')') {
            solve(res, str, leftCount, rightCount, index + 1, path + str[index], pair);
        } else {
            if (str[index] == '(') {
                if (leftCount > 0)
                    solve(res, str, leftCount - 1, rightCount, index + 1, path, pair);
                solve(res, str, leftCount, rightCount, index + 1, path + str[index], pair + 1);
            }
            if (str[index] == ')') {
                if (rightCount > 0)
                    solve(res, str, leftCount, rightCount - 1, index + 1, path, pair);
                if (pair > 0)
                    solve(res, str, leftCount, rightCount, index + 1, path + str[index], pair - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int leftCount = 0, rightCount = 0;
        for (auto ch : s) {
            if (ch == '(') {
                leftCount++;
            } else if (ch == ')') {
                if (leftCount != 0)
                    leftCount--;
                else
                    rightCount++;
            }
        }
        solve(result, s, leftCount, rightCount, 0, "", 0);
        return vector<string>(result.begin(), result.end());
    }
};

int main() {
    string str;
    cin >> str;
    auto x = (new Solution())->removeInvalidParentheses(str);
    for (auto y : x) cout << y << endl;
}