#include <bits/stdc++.h>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int getMinPath(vector<int>* edges,int n ,int source,int destination)
{
	queue<int>pendingVertices;
	int *level=new int[n];
	pendingVertices.push(source);
	bool *visited=new bool[n];
	fon(i , n) visited[i]=false , level[i]=0;
	visited[source]=true;
	int steps=0;
	level[source]=0;
	while(!pendingVertices.empty())
	{
		int adjacent=pendingVertices.front();
		steps++;
		if (adjacent==destination)
		{
			return level[adjacent];
		}
		pendingVertices.pop();
		fon(i , edges[adjacent].size())
		{
			int neighbour=edges[adjacent][i];
			if (!visited[neighbour])
			{
				level[neighbour]=level[adjacent]+1;
				visited[neighbour]=true;
				pendingVertices.push(neighbour);
			}
		}
	}
	return -1;
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> *edges=new vector<int>[n];
	unordered_map<string ,int>loc;
	int count=0;
	for(int i=0 ; i<k ; i++){
		string src,dest;
		cin>>src>>dest;
		if(loc[src]==0)	loc[src]=count++;
		if(loc[dest]==0) loc[dest]=count++;
		int x=loc[src];
		int y=loc[dest];
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	string src,dest;
	cin>>src>>dest;
	int s=loc[src];
	int d=loc[dest];
	cout<<getMinPath(edges , n ,s,d);
}