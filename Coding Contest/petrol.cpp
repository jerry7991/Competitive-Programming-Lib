#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v ,int i=0 , int group1=0 , int group2=0){
	if(i==v.size()) return max(group1 ,group2);
	int ans1=solve(v, i+1 , group1+v[i] , group2);
	int ans2=solve(v , i+1 , group1 , group2+v[i]);
	return min(ans1 , ans2);
}
int main(){
	string str;
	getline(cin , str);
	vector<int> in;
	int i=0;
	while(i<str.size()){
		int x=0;
		while(i<str.size() && str[i]!=' '){
			x=x*10+(str[i]-'0');
			i++;
		}
		in.push_back(x);
		i++;
	}
	cout<<solve(in);
}