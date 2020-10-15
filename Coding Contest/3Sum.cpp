#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums){
	long long int sum=0,set_sum=0;
	for(unsigned int i=0 ; i<nums.size() ; i++){
		sum+=nums[i];
	}
	unordered_set<int> s(nums.begin(), nums.end());
	set_sum=accumulate(s.begin(), s.end(),0);
	return ((3*set_sum)-sum)/2;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<singleNumber(v);
}