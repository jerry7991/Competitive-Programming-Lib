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
void dfs(vector<int>*adjList , stack<int> &st,bool *visited , int curr){
	visited[curr]=true;
	fon(i,adjList[curr].size()){
		int adjacent=adjList[curr][i];
		if(!visited[adjacent])
			dfs(adjList , visited , adjacent);
	}
	st.push(curr);
}
void dfs(vector<int>*adjList , bool *visited , int curr){
	visited[curr]=true;
	fon(i , adjList[curr].size()){
		int adjacent=adjList[curr][i];
		if(visited[adjacent]) continue;
		dfs(adjList , visited , adjacent);
	}
}
void solve(){
	int n,m;
	cin>>n>>m;	
	vector<int>* adjList=new vector<int>[n];
	bool *visited=new bool[n];
	fon(i,n) visited[i]=false;
	fon(i,m){
		int x,y;cin>>x>>y;
		adjList[x-1].pb(y-1);
	}
	int count=0;
	stack<int> st;
	fon(i,n){
		if(!visited[i])
		{
			dfs(adjList , st,visited , i);
		}
	}
	fon(i,n) visited[i]=false;
	while(!st.empty()){
		int curr=st.top(); st.pop();
		if(visited[curr])continue;
		count++;
		dfs(adjList  , visited , curr);
	}
	cout<<count<<'\n';
	delete []visited;
	delete []adjList;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) solve();
    return 0;
}