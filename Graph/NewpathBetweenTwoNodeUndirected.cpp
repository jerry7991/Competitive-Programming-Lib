#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
	int V;    
    list<int> *adj;    
};
bool isPath(Graph g , int s , int d,bool *visited){
    if(s==d) return true;
    visited[s]=true;
    list<int> edge=g.adj[s];
    bool found=false;
    list<int>:: iterator itr=edge.begin();
    while(itr!=edge.end()){
        if(visited[*itr]) 
        {
            itr++;
            continue;
        }
        found=isPath(g, *itr , d,visited);
        if(found) return found;
        itr++;
    }
    return found;
}
bool isReachable(Graph g,int s, int d)
{
	bool *visited=new bool[g.V];
    for(int i=0 ; i<g.V ; i++) visited[i]=false;
    bool found=isPath(g , s,d,visited);
    delete []visited;
    return found;
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
    int x,y;
    cin>>x>>y;
    cout<<isReachable(g,x-1,y-1);
}