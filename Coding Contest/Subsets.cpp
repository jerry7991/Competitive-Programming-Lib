#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> output;
void Subset(vector<int>&nums , vector<int> ans,int size=0){
	if(size==nums.size()){
		output.push_back(ans);
		return ;
	}
	vector<int> ans1=ans;
	ans1.push_back(nums[size]);
	Subset(nums , ans ,size+1);
	Subset(nums  , ans1, size+1);
}
int main(){
	int n;cin>>n;
	vector<int> v;
	for(int i=0 ; i<n ; i++){
		int x;cin>>x;
		v.push_back(x);
	}
	vector<int> x;
	Subset(v,x);
	for (int i = 0; i < output.size(); ++i)
	{
		for(int j=0 ; j<output[i].size() ; j++) cout<<output[i][j]<<' ';
		cout<<'\n';
	}
}