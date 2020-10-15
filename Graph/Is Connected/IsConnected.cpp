#include <iostream>
using namespace std;
void dfs(bool **isPath ,bool * isVisited ,int  nVertices , int start)
{
	isVisited[start]=true;
	for (int i = 0; i < nVertices; ++i)
	{
		if (start==i)
		{
			continue;
		}
		if (isPath[start][i]==1 && !isVisited[i])
		{
			dfs(isPath , isVisited , nVertices , i);
		}
	}
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;

	bool **isPath=new bool*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isPath[i]=new bool[nVertices];
		for(int j=0 ; j<nVertices ; j++)
		{
			isPath[i][j]=false;
		}
	}
	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		isPath[source][destination]=true;
		isPath[destination][source]=true;//cause of undirected
	}

	bool *isVisited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isVisited[i]=false;
	}
	dfs(isPath , isVisited , nVertices , 0);
	for (int i = 0; i < nVertices; ++i)
	{
		if ( !isVisited[i])
		{
			cout<<"false";
			return 0;
		}
	}
	cout<<"true";
	return 0;
}