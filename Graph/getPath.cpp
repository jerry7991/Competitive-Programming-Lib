#include <bits/stdc++.h>
#define fon(i,n) for(unsigned int i=0 ; i<n ; i++)
#define pb(n) push_back(n)
using namespace std;
vector<int>* dfs(vector<int> *edge , int n , bool *visited , int source , int dest )
{
	if(source==dest)	
	{
		vector<int> *output=new vector<int>();
		output->pb(source);
		return output;
	}
	visited[source]=true;
	fon(i , edge[source].size()){
		int adjVertex=edge[source][i];
		if(!visited[adjVertex]){
			vector<int> *smallOutput=dfs(edge , n , visited , adjVertex , dest );
			if(smallOutput!=NULL){
				smallOutput->pb(adjVertex);
				return smallOutput;
			}
		}
	}
	return NULL;
}
void getPathDFS(vector<int> *edge ,int n){
	int source,dest;
	cin>>source>>dest;
	if(source==dest){
		printf("%d\n",source );
		return;
	}
	bool *visited=new bool[n];
	fon(i,n) visited[i]=false;
	vector<int> *path=dfs(edge , n , visited , source , dest);
	if(path!=NULL){
		fon(i,path->size()) printf("%d  ",path->at(i) );
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> *adjList=new vector<int>[n];
	fon(i,m){
		int src,dest;
		cin>>src>>dest;
		adjList[src].pb(dest);
		adjList[dest].pb(src);
	}
	fon(i,m)
		sort(adjList[i].begin() , adjList[i].end() , greater<int>());
	getPathDFS(adjList,n);
	return 0;
}