#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
std::vector<int> path;
std::map<int , int> parent;
bool getPath(bool **isPath ,int  nVertices ,int source ,int destination)
{
	bool * isVisited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isVisited[i]=false;
	}
	queue<int>pendingVertices;
	pendingVertices.push(source);
	isVisited[source]=true;
	while( ! pendingVertices.empty())
	{
		int currentVertex=pendingVertices.front();
		pendingVertices.pop();
		if (currentVertex==destination)
		{
			path.push_back(currentVertex);
			//i knwo contition will be true because if there is a path from a to b then reverse also will possible
			while(	parent[currentVertex]!=source	)
			{
				currentVertex=parent[currentVertex];
				path.push_back(currentVertex);
			}
			path.push_back(source	);
			// std::map<int, int> ::iterator itr;
			// for (itr=parent.begin() ; itr!=parent.end() ; itr++)
			// {
			// 	cout<<itr->first<<" ->"<<itr->second<<endl;
			// }
			return true;
		}
		for (int i = 0; i < nVertices; ++i)
		{
			if (i==currentVertex)
			{
				continue;
			}
			if (isPath[currentVertex][i]==1 && !isVisited[i])
			{
				pendingVertices.push(i);
				isVisited[i]=true;
				//store the acknowledgement about their parent i.e. parent of i
				parent[i]=currentVertex;
			}
		}
	}
return false;
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
	int source,destination;
	cin>>source>>destination;
	bool answer=getPath(isPath , nVertices , source ,destination);
	if (answer)
	{
		for(unsigned int i=0 ; i<path.size() ; i++)
		{
			cout<<path[i]<<" ";
		}
	}
}