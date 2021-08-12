#include<bits/stdc++.h>
using namepsace std;



class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		vector<int> m = arr;
		for (int i = 1; i < m.size(); i++) {
			m[i] = max(m[i - 1], m[i]);
		}
		sort(arr.begin(), arr.end());

		int ans = 0;

		for (int i = 0; i < m.size(); i++) {
			if (m[i] == arr[i]) ans++;
		}
		return ans;
	}
};