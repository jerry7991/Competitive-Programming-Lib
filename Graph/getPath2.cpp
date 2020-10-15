#include <bits/stdc++.h>
#define fon(i,n) for(unsigned int i=0 ; i<n ; i++)
using namespace std;
void getBFSPath(bool **edge  , int n){
	unordered_map<int,int>parent;
	int src,dest;
	cin>>src>>dest;
	bool *visited=new bool[n];
	fon(i,n)	visited[i]=false;
	vector<int>path;
	queue<int> q;
	q.push(src);
	visited[src]=true;
	while(q.size()){
		int adjacent=q.front();
		q.pop();
		if (adjacent==dest)
		{
			int curr=adjacent;
			while(curr!=src){
				path.push_back(curr);
				curr=parent[curr];
			}
			path.push_back(curr);
			break;
		}
		for(int i=0 ; i<n  ; i++){
			if(i==adjacent) continue;
			if(edge[adjacent][i] && !visited[i]){
				q.push(i);
				visited[i]=true;
				parent[i]=adjacent;
			}
		}
	}
	fon(i,path.size())	printf("%d ",path[i]);
    delete []visited;
}
int main(){
	int n,m;
	cin>>n>>m;
	bool **edge=new bool*[n];
	fon(i,n){
		edge[i]=new bool[n];
		fon(j,n)	edge[i][j]=false;
	}
	fon(i,m){
		int src,dest;
		cin>>src>>dest;
		edge[src][dest]=true;
		edge[dest][src]=true;
	}
	getBFSPath(edge ,n);
    fon(i,n) delete []edge[i];
    delete []edge;
}