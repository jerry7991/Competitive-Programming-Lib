#include<iostream>
using namespace std;
int getMinVertex(bool *visited ,int * weight ,int nVertices)
{
	int minVertex=-1;
	for (int i = 0; i < nVertices; ++i)
	{
		if ( !visited[i] && (minVertex==-1 || weight[minVertex]>weight[i]))
		{
			minVertex = i;
		}
	}
	return minVertex;
}
void primsAlgorithm(int **weightMatrix ,int nVertices ,int nEdges)
{
	//need a visited array to store the information about visited node
	bool *visited=new bool[nVertices]();
	//need a weight correspond each node
	int *weight =new int[nVertices];
	//initially 0 weight and mst start from 0
	weight[0]=0;
	for (int i = 1; i < nVertices; ++i)
	{
		weight[i]=INT_MAX;
	}
	//need a parent array to strore the data about parent
	int *parent=new int[nVertices];
	parent[0]=-1;

	//traverse each vertex
	for (int i = 0; i < nVertices; ++i)
	{
		//get min vertex i.e. unvisited vertex with min weight
		int minVertex = getMinVertex(visited , weight , nVertices);
		//make minVertex as visited
		visited[minVertex]=true;
		//now explore all the neighbours of this minVertex
		for(int j=0 ; j<nEdges ; j++)
		{
			//if their is any path from minVertex to j which is not visited
			if (weightMatrix[minVertex][j]!=0 && !visited[j])
			{
				//if new weight is lesser than older than update weight to new
				if (weightMatrix[minVertex][j] < weight[j])
				{
					weight[j] = weightMatrix[minVertex][j];
					//make j parent of minVertex
					parent[j]=minVertex;
				}
			}
		}
	}
	//now print the mst
	for (int i = 1; i < nVertices; ++i)
	{
		if (parent[i]>i)
		{
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}else{
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
		}
	}
	delete [] parent;
	delete [] weight;
	delete [] visited;
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;

	int **weightMatrix=new int*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		weightMatrix[i]=new int[nEdges];
		for(int j=0 ; j<nEdges ; j++)
		{
			weightMatrix[i][j]=0;
		}
	}
	for(int j=0 ; j<nEdges ; j++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			weightMatrix[s][d]=w;
			weightMatrix[d][s]=w;//undirected
		}
	primsAlgorithm(weightMatrix , nVertices , nEdges);
}