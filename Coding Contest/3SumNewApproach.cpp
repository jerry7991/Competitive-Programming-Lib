#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums){
	int ones=0,tows=0;
	int common_bit_mask;
	for(int i=0 ; i<nums.size() ; i++){
		tows= tows | (ones & nums[i]);
		ones=ones^nums[i];
		common_bit_mask=~(ones & tows);
		ones &=common_bit_mask;
		tows &=common_bit_mask;
	}
	return ones;
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