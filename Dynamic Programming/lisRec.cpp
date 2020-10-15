#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>& input,vector<int> subSeq,int len=0){
	if(len==input.size()) return subSeq.size();
	vector<int> v=subSeq;
	int _include=1,_exclude=1;
	if(subSeq.size()==0 || input[len]>subSeq[subSeq.size()-1]){
	v.push_back(input[len]);
	 _include=lis(input , v , len+1);
	}
	 _exclude=lis(input , subSeq , len+1);
	 return max(_include , _exclude);
}
int main(){
	int n;
	cin>>n;
	vector<int> v;
	while(n--){
		int x;cin>>x;
		v.push_back(x);
	}
	vector<int> out;
	cout<<lis(v,out)<<'\n';
}