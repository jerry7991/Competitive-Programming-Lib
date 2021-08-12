class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));



        vector<int> edge[n];

        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; j++, i++) {
                if (g < 2) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    if (s[i] == s[j]) {
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                    }
                }
                // if (isPalindrome[i][j]) {
                //     edge[i].push_back(j + 1);
                // }
            }
        }


        // int l = 0;
        // queue<int> level;
        // level.push(0);
        // vector<bool> seen(n + 1, false);
        // seen[0] = 0;


        // while (level.size() && l <= 3) {
        //     int k = level.size();
        //     l++;
        //     while (k--) {
        //         int u = level.front();
        //         level.pop();
        //         if (u == n) {
        //             if (l == 4)
        //                 return true;
        //             else {
        //                 continue;
        //             }
        //         }

        //         if (l < 4)
        //             for (int v : edge[u]) {
        //                 level.push(v);
        //             }
        //     }
        // }
        // return false;



        for (int i = 0; i < n - 2; i++) {
            for (int j = n - 1; j > i + 1; j--) {
                if (isPalindrome[0][i] && isPalindrome[i + 1][j - 1] && isPalindrome[j][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};