#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

	int doDfs(vector < vector<int>> &edge, vector<bool>&seen, int src) {
		seen[src] = true;
		int res = 0;
		for (int dst : edge[src]) {
			if (seen[dst]) continue;
			res = max(res, doDfs(edge, seen, dst));
		}
		return res + 1;
	}

	int arrayNesting(vector<int>& nums) {
		int n = nums.size();
		vector < vector<int>> edge(n, vector<int>());

		for (int i : nums) {
			edge[nums[i]].push_back(nums[nums[i]]);
		}
		vector<bool> seen(n, false);

		int res = 0;
		for (int i = 0; i < n; i++) {
			if (seen[nums[i]])continue;
			res = max(res, doDfs(edge, seen, nums[i]));
		}
		return res;
	}


	int arrayNesting(vector<int>& nums) {
		int max_size = 0;

		for (int i = 0; i < nums.size(); i++) {
			int size = 0;

			for (int j = i; nums[j] >= 0; size++) {
				int k = nums[j];
				nums[j] = -1;
				j = k;
			}

			max_size = max(max_size, size);
		}
		return max_size;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v) cin >> i;
	cout << (new Solution()).arrayNesting(v);
	return 0;
}