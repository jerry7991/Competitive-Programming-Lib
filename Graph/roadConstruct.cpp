#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define infinte 2147483647
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define ump unordered_map
#define mp make_pair
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
void dfs(int st , vector<int>*adjList ,bool *visited , bool &cycle,int parent=-1){
	visited[st]=true;
	fon(i,adjList[st].size()){
        if(adjList[st][i]==parent) continue;
		if(!visited[adjList[st][i]]) dfs(adjList[st][i] ,adjList , visited , cycle,st);
		else
			cycle=true;
	}
}
void solve(){
	int v,e;
	cin>>v>>e;
	vector<int>* adjList=new vector<int>[v];
	fon(i,e){
		int x,y;cin>>x>>y;
		adjList[x-1].pb(y-1);
		adjList[y-1].pb(x-1);
	}
	bool *visited=new bool[v];
	fon(i,v) visited[i]=false;
	bool cycle=false;
	dfs(0 , adjList ,visited,cycle);
	if(cycle) cout<<"Yes";
	else cout<<"No";
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	solve();
    return 0;
}