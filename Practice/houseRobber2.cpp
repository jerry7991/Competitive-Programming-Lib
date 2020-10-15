//https://leetcode.com/problems/house-robber-ii/
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &nums , int st,int len){
	int pre=0,curr=0;
	for(int i=st ; i<=len ; i++){
		int temp=max(pre+nums[i] , curr);
		pre=curr;
		curr=temp;
	}
	return curr;
}
int rob(vector<int> &nums){
	int n=nums.size();
	if(n<2) return n? nums[0]:0;
	return max(solve(nums , 0 , n-2) , solve(nums , 1,n-1));
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	while(n--){
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<rob(v)<<endl;
	return 0;
}