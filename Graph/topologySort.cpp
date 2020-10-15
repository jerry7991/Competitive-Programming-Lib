#include <iostream>
#include <stack>
#include <list>
using namespace std;
class Graph{
public:
	int v;
	list<int> *adj;
};
void dfs(Graph &g , bool *visited , int src,stack<int> &tpOrder){
	visited[src]=true;
	list<int>::iterator itr;
	for(itr=g.adj[src].begin(); itr!=g.adj[src].end();itr++){
		if(visited[*itr]) continue;
		dfs(g,visited , *itr , tpOrder);
	}
	tpOrder.push(src);
}
void topologicalSort(Graph g)
{
	stack<int> tpOrder;
	bool *visited=new bool[g.v];
	for(int i=0 ; i<g.v;i++) visited[i]=false;
	for(int i=0 ; i<g.v;i++){
		if(visited[i]) continue;
		dfs(g , visited  , i,tpOrder);
	}
	//now print the topology order
	while(tpOrder.size()){
		cout<<tpOrder.top()<<' ';
		tpOrder.pop();
	}
	delete []visited;
}
int main(){
	int n,m;
	cin>>n>>m;
	Graph g;
	g.v=n;
	g.adj=new list<int>[n];
	for(int i=0 ; i<m ; i++){
		int src,dest;
		cin>>src>>dest;
		g.adj[src].push_back(dest);
	}
	topologicalSort(g);
}