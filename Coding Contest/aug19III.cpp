	#include<bits/stdc++.h>
	using namespace std;
	int x,y , level;
	string str;
	unordered_set<string> visited;
	unordered_map<string , int> isPath;
	bool isPossible(int x2 ,int y2 , int len=0){
		if(len==str.size()){
			return (x==x2 && y==y2);
		}
		if(isPath.find(to_string(x2)+to_string(y2))!=isPath.end()){
			return true;
		}
		visited.insert(to_string(x2)+to_string(y2));
		bool isFind=false;
		isFind=isPossible(x2 , y2 , len+1);
		if(isFind) return isFind;
		if(str[len]=='R' && (visited.find(to_string(x2+1)+to_string(y2))==visited.end())){
			isFind |=isPossible(x2+1 , y2 , len+1);
			if(isFind){
				level++;
			 return isFind;
			}
		}
		if(str[len]=='L' && (visited.find(to_string(x2-1)+to_string(y2))==visited.end())){
			isFind |= isPossible(x2-1 , y2  , len+1);
			if(isFind){
				level++;
			 return isFind;
			}
		}
		if(str[len]=='U' && (visited.find(to_string(x2)+to_string(y2+1))==visited.end())){
			isFind |= isPossible(x2 , y2+1 , len+1);
			if(isFind){ 
				level++;
				return isFind;
			}
		}
		if(str[len]=='D' && (visited.find(to_string(x2)+to_string(y2-1))==visited.end())){
			isFind |= isPossible(x2 , y2-1 , len+1);
			if(isFind){
				level++;
			 return isFind;
			}
		}
		return isFind;
	}
	void solve(){
		cin>>str;
		cin>>x>>y;
		int q;
		cin>>q;
		isPath.clear();
		while(q--){
			int x2 , y2;
			cin>>x2>>y2;
			visited.clear();
			string st=to_string(x2)+to_string(y2);
			cout<<st<<'\n';
			level=0;
			if(isPath[st]){
				cout<<"YES "<<isPath[level]<<'\n';
			}
			else if(isPossible(x2,y2)){
				isPath[st]=level;
				cout<<"YES "<<level<<'\n';
			}else{
				cout<<"NO"<<'\n';
			}
		}
	}
	int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) solve();
	    return 0;
	}