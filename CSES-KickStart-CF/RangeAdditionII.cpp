class Solution {
  public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int  x = m, y = n;

		for (auto &op : ops) {
			x = min(x, op[0]), y = min(y, op[1]);
		}

		return x * y;
	}
};
