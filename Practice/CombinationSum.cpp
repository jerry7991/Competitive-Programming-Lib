#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr , int target ,vector<vector<int>> *output , vector<int> curr , int index=0){
	if(target==0){
		output->push_back(curr);
		return ;
	}
	if(index==arr.size()) return;
	//exlcude
	solve(arr , target , output , curr , index+1);
	//include
	if(arr[index]<=target){
		curr.push_back(arr[index]);
		solve(arr ,target-arr[index] ,output , curr , index);
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> *output=new vector<vector<int>>();
	vector<int> curr;
	solve(candidates , target , output , curr);
return *output;
}
int main(){
	while(true){
		int n;
		cin>>n;
		vector<int> v;
		for(int i=0 ; i<n ; i++){
			int x;cin>>x;
			v.push_back(x);
		}
		int target;cin>>target;
		vector<vector<int>> output=combinationSum(v , target);
		for(auto x:output){
			for(auto y:x)cout<<y<<' ';
			cout<<'\n';
		}
	}
 return 0;
}