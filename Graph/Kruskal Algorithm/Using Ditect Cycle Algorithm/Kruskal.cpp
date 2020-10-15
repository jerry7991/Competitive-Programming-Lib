#include<iostream>
#include <queue>
#include<algorithm>
using namespace std;
class Edge
{
public:
	int source;
	int destination;
	int weight;	
};
bool theirIsPath(bool ** isPath ,int nVertices , int nEdges ,int src ,int dest)
{
	if (src==dest)
	{
		return true;
	}
	bool *isVisited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isVisited[i]=false;
	}
	queue<int> pendingVertex;
	pendingVertex.push(src);
	isVisited[src]=true;
	while( ! pendingVertex.empty() )
	{
		int currentVertex=pendingVertex.front();
		pendingVertex.pop();
		if (currentVertex==dest)
		{
			return true;
		}
		for (int i = 0; i < nEdges; ++i)
		{
			if (i==currentVertex)
			{
				continue;
			}
			if (isPath[currentVertex][i] && !isVisited[i])
			{
				isVisited[i]=true;
				pendingVertex.push(i);
			}
		}
	}
	return false;
}
bool compare(Edge e1 , Edge e2)
{
	return (e1.weight<e2.weight);
}
Edge * getMst(Edge *edges ,int nEdges ,int nVertices)
{
	Edge *outputMst=new Edge[nVertices-1];
	bool **isPath=new bool*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isPath[i]=new bool[nEdges];
		for(int j=0 ; j<nEdges ; j++)
		{
			isPath[i][j]=false;
		}
	}
	int mstIndex=0;
	int edgeIndex=0;
	while( mstIndex<(nVertices-1)	)
	{
		int src = edges[edgeIndex].source;
		int dest = edges[edgeIndex].destination;
		if(	!theirIsPath(isPath  ,nVertices,nEdges , src ,dest)	)
		{
			//if their is no path from src to dest then we can make an edge from src to dest in our mst and it will not make a cycle in mst tree
			outputMst[mstIndex] = edges[edgeIndex];
			//update src to dest has path now
			isPath[src][dest]=true;
			isPath[dest][src]=true;//undirected
			mstIndex++;
		}
		edgeIndex++;
	}
	return outputMst;
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;
	Edge *edges=new Edge[nEdges];
	for (int i = 0; i < nEdges; ++i)
	{
		cin>>edges[i].source;
		cin>>edges[i].destination;
		cin>>edges[i].weight;
	}
	//sort the edges according to their weight
	sort(edges , edges+nEdges , compare);
	Edge * outputMst=getMst(edges , nEdges , nVertices);
	//print mst
	for (int i = 0; i < nVertices-1; ++i)
	{
		if (outputMst[i].source < outputMst[i].destination)
		{
			cout<<outputMst[i].source <<" "<<outputMst[i].destination<<" "<<outputMst[i].weight<<endl;
		}else{
			cout<<outputMst[i].destination <<" "<<outputMst[i].source<<" "<<outputMst[i].weight<<endl;
		}
	}
	return 0;
}