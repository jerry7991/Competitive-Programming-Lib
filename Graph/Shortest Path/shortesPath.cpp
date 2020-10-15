#include <iostream>
#include <vector>
#include <queue>
#define pb(n) push_back(n)
#define fon(i , n) for(int i=0 ; i<n ; i++)
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
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>*edges=new vector<int>[n];
	fon(i , m)
	{
		int source,destination;
		cin>>source>>destination;
		edges[source-1].pb(destination-1);
		edges[destination-1].pb(source-1);
	}
	int source,destination;
	cin>>source>>destination;
	cout<<getMinPath(edges,n ,source-1,destination-1);
}