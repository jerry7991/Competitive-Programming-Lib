class Solution {
public:
    vector<vector<string>> *output;
    void solve(string bw, string &ew, unordered_set<string>& aw, int currStep, int &minStep, vector<string> path, unordered_set<string >& seen) {
        path.push_back(bw);
        if (bw == ew) {
            if (currStep <= minStep)
                output[currStep].push_back(path);
            minStep = min(minStep, currStep);
            return;
        }
        if (currStep > minStep) {
            return;
        }

        seen.insert(bw);
        for (int i = 0; i < bw.size(); i++) {
            char ch = bw[i];
            for (int j = 'a'; j <= 'z'; j++) {
                bw[i] = j;
                if (aw.find(bw) != aw.end() && seen.find(bw) == seen.end()) {
                    solve(bw, ew, aw, currStep + 1, minStep, path, seen);
                }
                bw[i] = ch;
            }
        }
        seen.erase(bw);
    }

    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        output = new vector<vector<string>>[1002];
        unordered_set<string> seen;
        unordered_set<string> aw(wl.begin(), wl.end());
        int minStep = 1001;
        vector<string> path;
        solve(bw, ew, aw, 0, minStep, path, seen);
        return output[minStep];
    }
};