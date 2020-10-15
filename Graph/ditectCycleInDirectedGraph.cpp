#include <iostream>
#include <list>
#include <queue>
using namespace std;
class Graph
{
public:
	int V;
	list<int> *adj;
};
bool dfs(int src , Graph &g , bool *visited , bool *backEdge){
	if(!visited[src]){
		visited[src]=true;
		bool ans=false;
		list<int>::iterator itr;
		for(itr=g.adj[src].begin();itr!=g.adj[src].end() ; itr++){
			if(!visited[*itr]){
				ans=dfs(*itr , g , visited , backEdge);
				if(ans) return ans;
			}else if(backEdge[*itr]){//means there is a backedge from src->*itr
				return true;
			}
		}
	}
		backEdge[src]=false;//backtrack for other connected compnent
		return ans;
}
bool isCycle(Graph &g){
	bool *visited=new bool[g.V];
	bool *backEdge=new bool[g.V];
	for(int i=0 ; i<g.V ; i++) visited[i]=backEdge[i]=false;
	int ans=false;
	for(int i=0 ; i<g.V ;i++){
		if(visited[i]) continue;
		ans=dfs(i,g,visited , backEdge);
		if(ans){
			delete []visited;
			delete []backEdge;
			return ans;
		}
	}
	delete []visited;
	delete []backEdge;
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	Graph g;
	g.V=n;
	g.adj=new list<int>[n];
	for(int i=0 ; i<m ; i++){
		int src,dest;
		cin>>src>>dest;
		g.adj[src].push_back(dest);
	}
	cout<<isCycle(g);
}
/*
problem related to codeZen
like---
https://codezen.codingninjas.com/practice/498/2443/detect-cycle-in-a-directed-graph
i think your test cases wrong or your result checking algorithm wrong.. please check for this input...
5 5
0 1
0 2
2 1
0 3
3 4
output must be false ...
because there is only edge between
0->1
0->2
2->1 wouldn't make a cycle because 1 has no outgoing edges...
but your's is true...
*/