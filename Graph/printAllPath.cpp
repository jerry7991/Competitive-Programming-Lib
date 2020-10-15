#include <iostream>
#include <list>
#include <vector>
using namespace std;
vector<int> path;
class Graph{
public:
	int V;
	list<int>*adj;
};
void print(Graph g , int src , int dest , bool *visited){
		path.push_back(src);
		visited[src]=true;
	if(src==dest){
		for(int i=0 ; i<path.size() ; i++) cout<<path[i]<<" ";
        cout<<endl;
	}
	list<int> lst=g.adj[src];
	list<int>::iterator itr=lst.begin();
	while(itr!=lst.end()){
		if(visited[*itr]){
			itr++;
			continue;
		}
		print(g , *itr , dest ,visited);
		itr++;
	}
		path.pop_back();
		visited[src]=false;
}
void printAllPaths(Graph g,int s, int d)
{
	bool *visited=new bool[g.V];
	for(int i=0 ; i<g.V ; i++) visited[i]=false;
	print(g,s,d,visited);
	delete[] visited;
}
int main(){
	int n,m;
	cin>>n>>m;
	Graph g;
	g.V=n;
	g.adj=new list<int>[n];
	for(int i=0 ; i<m ; i++){
		int x,y;
		cin>>x>>y;
		g.adj[x-1].push_back(y-1);
	}
	int s,d;
	cin>>s>>d;
	printAllPaths(g , s-1 , d-1);
	delete []g.adj;
}