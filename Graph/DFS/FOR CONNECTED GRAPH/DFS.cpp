#include <iostream>
using namespace std;
void printDFS(int **edges ,int nVertices ,bool * visited ,int startVertex)
{
	cout<<startVertex<<endl;
	//once i printed then we should make this node as visited ok!!!
	visited[startVertex]=true;
	for (int i = 0; i < nVertices; ++i)
	{
		//find first non-visited and start exploring that vertex till the end..
		if (i==startVertex)
		{
			//we are at our current node
			continue;
		}
		if (edges[startVertex][i]==1)//if there is an edge frmom start index to end index
		{
			if (visited[i])
				{
					//All ready has visited
					continue;
				}
				//now our start point will the first i-th non-visited element OK!!!!
				printDFS(edges , nVertices , visited , i);
			}
	}
}
int main()
{
	int nVertices;
	cin>>nVertices;
	int nEdges;
	cin>>nEdges;
	int **edges=new int*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		edges[i]=new int[nVertices];
		for(int j=0 ; j<nVertices ; j++)
		{
			edges[i][j]=0;
		}
	}
	cout<<"Enter edges source  destination";
	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		edges[source][destination]=1;
		edges[destination][source]=1;	//cause of undirected graph
	}
	//now we need a visited array in which we stores either this area is visited or not...
	bool *visited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		visited[i]=false;
	}
	int startVertex=0;
	cout<<"DFS path is \n";
	printDFS(edges , nVertices , visited , startVertex);
	return 0;
}