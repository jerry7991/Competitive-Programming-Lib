#include <iostream>
#include <list>
using namespace std;
class Graph
{
public:
	int V;
	list<int> *adj;
};
bool dfs(Graph &g , int src , bool *visited , int parent=-1){
	visited[src]=true;
	list<int>:: iterator itr=g.adj[src].begin();
	bool isFound=false;
	while(itr!=g.adj[src].end()){
		if(!visited[*itr])
		{
			isFound=dfs(g , *itr , visited,src);
			if(isFound) return isFound;
		}else if(*itr!=parent){
			return true;
		}
		itr++;
	}
	return isFound;
}
bool isCycle(Graph &g){
	bool *visited=new bool[g.V];
	bool isFound=false;
	for(int i=0 ; i<g.V ; i++) visited[i]=false;
	for(int i=0 ; i<g.V ; i++){
		if(visited[i]) continue;
		isFound=dfs(g ,i ,visited,i);
		if(isFound) return isFound;
	}
	delete []visited;
	return isFound;
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
		g.adj[dest].push_back(src);
	}
	cout<<isCycle(g);
}