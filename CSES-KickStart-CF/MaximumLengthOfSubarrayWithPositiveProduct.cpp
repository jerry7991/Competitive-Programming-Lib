#include<bits/stdc++.h>
using namespace std;


class Solution {
 public:
	int getMaxLen(vector<int>& nums) {
		int n = nums.size(), res = 0, i = 0;

		while (i < n) {
			int s = i;
			while (s < n && nums[s] == 0) s++;

			int e = s, c = 0;
			int startNeg = -1, endNeg = -1;
			while (e < n && nums[e] != 0) {
				if (nums[e] < 0) {
					endNeg = e;
					c++;
					if (startNeg == -1) startNeg = e;
				}
				e++;
			}
			if (c % 2 == 0) {
				res = max(res, e - s + 1);
			} else {
				if (startNeg != -1) {
					res = max(res, e - startNeg - 1);// ignore start
				}
				if (endNeg != -1) {
					res = max(res, endNeg - s);
				}
			}
			i = e;
		}
	}
};

int main() {

}