#include <iostream>
#include <vector>
using namespace std;
vector<int>* edge;
bool *visited;
bool isPath(int src , int dest){
	if(src==dest) return true;
	visited[src]=true;
	bool found=false;
	for(int i=0 ; i<edge[src].size();i++){
		int adjacent=edge[src][i];
		if(visited[adjacent])  continue;
		found=isPath(adjacent , dest);
		if(found) return found;
	}
	return found;
}
int main(){
	int n,m;
	cin>>n>>m;
	edge=new vector<int>[n];
	for(int i=0 ; i<m ; i++){
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
	}
    int src,dest;
    cin>>src>>dest;
	visited=new bool[n];
		for(int j=0 ; j<n ; j++)	visited[j]=false;
	bool ans=isPath(src,dest);
	if(ans)cout<<"True";
	else cout<<"False";
	delete []edge;
	delete []visited;
}