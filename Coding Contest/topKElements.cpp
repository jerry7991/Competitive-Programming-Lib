#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>& nums , int k){
	unordered_map<int,int> feq;
	for(int i=0 ; i<nums.size() ;i++){
		int x= feq[nums[i]]++ +1;
	}
	priority_queue<pair<int ,int>> pq(fq.begin(), fq.end());
	vector<int> output;
	while(k--){
		int x=pq.top().second;
			output.push_back(x);
			k--;
		pq.pop();
	}
	return output;
}
int main(){
	int n;
	cin>>n;
	vector<int>v;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;v.push_back(x);
	}
	int k;
	cin>>k;
	vector<int> output=solve(v ,k);
	for(int i=0 ; i<output.size() ; i++) cout<<output[i]<<' ';
	cout<<""<<'\n';
}