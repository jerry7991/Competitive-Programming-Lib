#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> Subset(vector<int> &nums){
	const int x=nums.size();
	vector<vector<int>> output;
	for(int i=0 ; i<(1<<x) ;i++){
		vector<int> res;
		for(int j=0 ; j<x ; j++){
			if(i & (1<<j)){
				res.push_back(nums[j]);
			}
		}
		output.push_back(res);
	}
	return output;
}
int main(){
	int n;cin>>n;
	vector<int> v;
	for(int i=0 ; i<n ; i++){
		int x;cin>>x;
		v.push_back(x);
	}
	vector<vector<int>> output= Subset(v);
	for (int i = 0; i < output.size(); ++i)
	{
		for(int j=0 ; j<output[i].size() ; j++) cout<<output[i][j]<<' ';
		cout<<'\n';
	}
}