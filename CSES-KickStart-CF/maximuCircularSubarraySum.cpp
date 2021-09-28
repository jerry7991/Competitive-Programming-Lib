#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:

	int kadanes(vector<int> &nums) {
		int mxSum = INT_MIN, currSum = 0, n = nums.size();

		for (int i : nums) {
			currSum += i;
			mxSum = max(mxSum, currSum);
			if (currSum < 0) currSum = 0;
		}
		return mxSum;
	}

	int maxSubarraySumCircular(vector<int>& nums) {
		int totalSum = accumulate(begin(nums), end(nums), 0);
		int nonCircular = kadanes(nums);
		for (int &i : nums) i = -i;
		int circular = kadanes(nums) + totalSum;



		if (circular == 0) {
			return nonCircular;
		}

		return max(circular, nonCircular);
	}
};