#include<bits/stdc++.h>
#define pb push_back
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
vector<int> *adjList;
int *weight , n;
void dfs(int s , unordered_set<int> & visited , bool &odd  , int &k , int &currLen){
	visited.insert(s);
	for(int i=0 ; i<adjList[s].size() ; i++){
		int adjacent=adjList[s][i];
		if(visited.find(adjacent)!=visited.end()) continue;
		int x=(weight[adjacent]^k);
		int parity=0;
		while(x>0){
			parity+=x%2;
			x/=2;
		}
		if(odd){
			if(parity&1){
				currLen++;
				dfs(adjacent , visited , odd , k , currLen);
			}
		}else{
			if((parity)%2==0){
				currLen++;
				dfs(adjacent , visited  , odd , k , currLen);
			}
		}
	}
}
int getAns(int k , bool odd){
	unordered_set<int> visited;
	int maxLen=0,currLen=0;
	for(int i=0 ; i<n  ; i++){
		if(visited.find(i)==visited.end()){
			int x=(weight[i]^k);
			int parity=0;
			while(x>0){
				parity+=x%2;
				x/=2;
			}
			if(odd){
				if(parity&1){
					currLen=1;
					dfs(i , visited , odd , k , currLen);
					maxLen=max(maxLen , currLen);
				}
			}else{
				if(parity%2==0){
					currLen=1;
					dfs(i , visited , odd , k , currLen);
					maxLen=max(maxLen , currLen);
				}
			}
		}
	}
	visited.clear();
	return maxLen;
}
void solve(){
	int m;cin>>n>>m;
	adjList=new vector<int>[n];
	weight=new int[n];
	for(int i=0  ; i<n ; i++) cin>>weight[i];
	for(int i=0 ; i<m ; i++){
		int x,y;cin>>x>>y;
		adjList[x-1].pb(y-1);
		adjList[y-1].pb(x-1);
	}
	int q;
	cin>>q;
	while(q--){
		int choice,k;cin>>choice>>k;
		if(choice%2==0)
			cout<<getAns(k , false)<<'\n';
		else
			cout<<getAns(k,true)<<'\n';
	}
	delete []adjList;
	delete []weight;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;cin>>t;
while(t--) 
	solve();
    return 0;
}