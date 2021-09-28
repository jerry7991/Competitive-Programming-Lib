class Solution {
  public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> distance(n, 0);
        vector<vector<int>> adjList(n);
        for (auto x : edges) {
            adjList[x[0] - 1].push_back(x[1] - 1);
            adjList[x[1] - 1].push_back(x[0] - 1);
        }

        int mask = 0;

        while (mask < (1 << n)) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    int nNode = cntNode();
                }
            }
            mask++;
        }

    }
};