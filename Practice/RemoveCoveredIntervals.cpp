#include<bits/stdc++.h>
using namespace std;
int removeCoveredIntervals(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end());
	int res = 0, left = -1, right = -1;
	for (auto x : intervals) {
		if (x[0] > left && x[1] > right) {
			res++;
			left = x[0];
		}
		right = max(x[1], right);
	}
	return res;
}
int main() {
	int n; cin >> n;
	vector<vector<int>> intervals(n, vector<int>(2, 0));
	for (int i = 0 ; i < n ; i++) cin >> intervals[i][0] >> intervals[i][1];
	cout << removeCoveredIntervals(intervals) << '\n';
	return 0;
}
