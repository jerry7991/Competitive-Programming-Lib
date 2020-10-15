#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int *arr=new int[n];
	int m=0;
	for(int i=0 ; i<n ; i++) cin>>arr[i],m=max(arr[i] ,i);
	vector<string> output;
	string str;
	for(int i=0 ; i<m+1 ; i++) str=str+char(97+i);
	output.push_back(str);
	str="";
	for(int i=0 ; i<n ; i++){
		str=output[output.size()-1].substr(0,arr[i]);
		output.push_back(str);
		str="";
	}
	for(int i=0 ; i<output.size() ; i++) cout<<output[i]<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}