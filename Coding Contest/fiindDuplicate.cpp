//https://leetcode.com/articles/find-the-duplicate-number/
#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
	int slow_pointer=nums[0];
	int fast_pointer=nums[0];
	//now our fast pointer is running two times more than our slow pointer

	slow_pointer=nums[slow_pointer];
	fast_pointer=nums[nums[fast_pointer]];
	while(slow_pointer!=fast_pointer){
		slow_pointer=nums[slow_pointer];
		fast_pointer=nums[nums[fast_pointer]];
	}
	int finder_pointer=nums[0];
	while(finder_pointer!=slow_pointer){
		slow_pointer=nums[slow_pointer];
		finder_pointer=nums[finder_pointer];
	}
	return finder_pointer;
}
int main(){
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0 ; i<n ; i++){
		int x;
		cin>>x;
		nums.push_back(x);
	}
	cout<<findDuplicate(nums);
}