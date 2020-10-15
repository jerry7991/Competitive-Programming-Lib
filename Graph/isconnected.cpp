#include <bits/stdc++.h>
#define fon(i,n) for (unsigned int i = 0; i < n; ++i)
#define pb push_back
#define cin(x) unsigned int x;cin>>x;
using namespace std;
void dfs(vector<int> *edge , bool *visited , int src=0){
	visited[src]=true;
	fon(i,edge[src].size()){
		int adjacent=edge[src][i];
		if(adjacent==src || visited[adjacent])	continue;
		dfs(edge , visited , adjacent);
	}
}
int main(){
	cin(n);cin(m);
	vector<int>* edge=new vector<int>[n];
	fon(i,m){
		cin(src);cin(dest);
		edge[src].pb(dest);
		edge[dest].pb(src);
	}
	bool *visited=new bool[n];
	fon(i,n) visited[i]=false;
	dfs(edge , visited);
	bool ans=true;
	fon(i,n)	if(!(ans=visited[i])) break;
	if(ans)	cout<<"true";
	else cout<<"false";
	delete []visited;
	delete []edge;
}