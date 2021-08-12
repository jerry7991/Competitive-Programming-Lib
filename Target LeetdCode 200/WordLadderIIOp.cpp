class Solution {
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        unordered_set<string> aw(wl.begin(), wl.end());
        aw.erase(bw);

        unordered_map<string, vector<vector<string>>> level;
        level[bw] = {{bw}};
        while (level.size()) {
            unordered_map<string, vector<vector<string>>> newLevel;
            for (const auto & [word, paths] : level) {
                if (word == ew) {
                    return level[word];
                }

                for (const string & nei : getNeighbours(word, aw)) {
                    for (auto path : paths) {
                        path.push_back(nei);
                        newLevel[nei].push_back(path);
                    }
                }
            }
            for (const auto & [word, _] : newLevel) aw.erase(word);
            level.swap(newLevel);
        }
        return {};
    }
    vector<string> getNeighbours(string str, unordered_set<string> &aw) {
        vector<string> out;
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            for (char j = 'a'; j <= 'z'; j++) {
                str[i] = j;
                if (aw.count(str)) out.push_back(str);
            }
            str[i] = ch;
        }
        return out;
    }
};