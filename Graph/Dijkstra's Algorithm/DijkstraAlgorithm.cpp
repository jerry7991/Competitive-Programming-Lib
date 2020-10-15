#include<iostream>
using namespace std;
int getMinVertex(bool* visited ,int * distance , int nVertices)
{
	int minVertex=-1;
	for (int i = 0; i < nVertices; ++i)
	{
		if (	!visited[i] && (minVertex==-1 || (distance[minVertex]>distance[i]))	)
		{
			minVertex = i;
		}
	}
	return minVertex;
}
void DijkstraAlgorithm(int **weightMatrix ,int nVertices ,int nEdges , int source)
{
	//we need a visited array
	bool *visited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		visited[i]=false;
	}
	//we need a parent array
	int *parent=new int[nVertices];
	//we need a distance array in which each i-th element represent it's min the distance from source
	int *distance=new int[nVertices];
	distance[source]=0;
	for (int i = 1; i < nVertices; ++i)
	{
		distance[i]=INT_MAX;
	}
	parent[source]=source;
	int mstEdge=0;
	while( mstEdge < nVertices-1)
	{
		int currSource = getMinVertex(visited , distance , nVertices);
		//it return the vertex which is not visited yet and has at min distance
		//make currSource to visited
		visited[currSource]=true;
		//start exploring the edges of currSource
		for (int i = 0; i < nEdges; ++i)
		{
			//if there is any path from currSource to i and which is not visited yet
			if (!visited[i] && weightMatrix[currSource][i]!=0)
			{
				//relaxation
				if (distance[i] > (distance[currSource]+weightMatrix[currSource][i]) )
				{
					//if distanceof(i,from source) is greater than distance(currSource , i)
					//we got a better path than direct source to i
					distance[i] = distance[currSource] + weightMatrix[currSource][i];
					//update parent 
					parent[i] = currSource;
				}
			}
		}
		//one mst edge has been added
		mstEdge++;
	}
	//print mst
	for (int i = 0; i < nVertices; ++i)
	{
		cout<<i<<" "<<distance[i]<<endl;
	}
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
	for (int i = 0; i < nEdges; ++i)
	{
		int s,d,w;
		cin>>s>>d>>w;
		weightMatrix[s][d]=w;
		weightMatrix[d][s]=w;
	}
	DijkstraAlgorithm(weightMatrix , nVertices , nEdges , 0);
}