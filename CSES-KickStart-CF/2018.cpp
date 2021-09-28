class Solution {
  public:

    bool same(vector<char>& row, int start, int end, string &str) {
        if (end - start != str.size()) return false;
        int j = 0;
        while (j + start < end && (row[j + start] == ' ' || row[j + start] == str[j])) j++;
        if (j == str.size()) {
            return true;
        }
        j = 0;
        while (end - 1 - j >= start && (row[end - 1 - j] == ' ' || row[end - 1 - j] == str[j])) j++;
        return j == str.size();
    }

    bool isPossible(vector<vector<char>>& a, string &str) {
        int r = a.size(), c = a[0].size();
        for (int i = 0; i < r; i++) {
            int j = 0;
            while (j < c) {
                while (j < c && a[i][j] == '#') j++;
                int start = j;
                while (j < c && a[i][j] != '#') j++;
                if (same(a[i], start, j, str)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool placeWordInCrossword(vector<vector<char>>& a, string word) {
        int r = a.size(), c = a[0].size();
        vector<vector<char>> b(c, vector<char>(r));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                b[j][i] = a[i][j];
            }
        }
        return (isPossible(a, word) || isPossible(b, word));
    }
};