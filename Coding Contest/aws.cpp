#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,char>p1 , pair<int,char>p2){
	return p1.first>p2.first;
}
int solve(string str){
	if(str.size()==0 || str.size()==1) return str.size();
	int *f=new int[300];
	for(int i=0 ; i<300 ; i++){
		f[i]=0;
	}
	for(int i=0 ; i<str.size() ; i++){
		f[str[i]]++;
	}
	vector<pair<int,char>> vt;
	for(int i=0 ; i<300  ; i++){
		if(f[i]==0) continue;
		char ch=i;
		vt.push_back(make_pair(f[i] , ch));
	}
	sort(vt.begin() , vt.end() , compare);
	//for(int i=0  ; i<vt.size() ; i++) cout<<vt[i].second<<" "<<vt[i].first<<'\n';
	bool oddInclude=false;
	int len=0;
	for(int i=0 ; i<vt.size() ; i++){
		if(!oddInclude && (vt[i].first & 1)){
			oddInclude=true;
			len+=vt[i].first;
		}
		if((vt[i].first & 1)==0){
			len+=vt[i].first;
		}
	}
	delete []f;
	return len;
}
int main(){
	string str;
	cin>>str;
	cout<<solve(str);
}