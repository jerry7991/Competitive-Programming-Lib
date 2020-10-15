#include <iostream>
#include <vector>
using namespace std;
std::vector<int> path;
void dfs(bool ** isPath ,bool * isVisited ,int nVertices ,int start)
{
	isVisited[start]=true;
	path.push_back(start);
	for (int i = 0; i < nVertices; ++i)
	{
		if (i==start)
		{
			continue;
		}
		if(isPath[start][i]==1 && !isVisited[i])
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
	for (int i = 0; i < nVertices; ++i)
	{
		if ( !isVisited[i])
		{
			dfs(isPath , isVisited , nVertices , i);
			//now our path has one connected path's vertices
			for (unsigned int i = 0; i < path.size(); ++i)
			{
				cout<<path[i]<<" ";
			}
			cout<<endl;
			path.clear();
		}
	}
}