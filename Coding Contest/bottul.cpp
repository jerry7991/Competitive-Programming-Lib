#include<bits/stdc++.h>
using namespace std;
vector<string> out;
void solve(string str , string ans="" , int len=0){
	if(len==str.size()){
		out.push_back(ans);
		return;
	}
	
}
int main(){
	string s;
	cin>>s;
	solve(s);
	for (int i = 0; i < out.size(); ++i)
	{
		cout<<out[i]<<'\n';
	}
}