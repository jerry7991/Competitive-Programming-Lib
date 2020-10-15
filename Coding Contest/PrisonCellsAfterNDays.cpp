#include <bits/stdc++.h>
using namespace std;
vector<int> prisonAfterNDays(vector<int>& cells, int n) {
	unordered_map<string , int> seen;
	while(n--){
		vector<int> v;
		v.push_back(0);
		string str="0";
		for(int i=1 ; i<7 ; i++){
			v.push_back(cells[i-1]^cells[i+1]^1);
			str+=to_string((cells[i-1]^cells[i+1]^1));
		}
		str+="0";
		//cout<<str<<endl;
		v.push_back(0);
		cells=v;
		if(seen[str]){
			n%= seen[str]-n;
		}else{
			seen[str]=n;
		}
	}
	return cells;
}
int main(){
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0 ; i<8 ; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	v=prisonAfterNDays(v,n);
	for(int i=0 ; i<8 ; i++){
		cout<<v[i]<<" ";
	}
}