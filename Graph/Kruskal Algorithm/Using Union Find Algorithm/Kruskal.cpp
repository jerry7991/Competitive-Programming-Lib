#include <iostream>
#include <algorithm>
using namespace std;
class Edge
{
public:
	int Source;
	int Destination;
	int weight;
	
};
bool compare(Edge e1 , Edge e2)
{
	return (e1.weight<e2.weight);
}
int getParent(int source ,int * parent)
{
	if(parent[source] ==source)
	{
		return source;
	}
	return getParent( parent[source] , parent );
}
Edge * getMst(int nVertices ,int nEdges ,Edge *edges)
{
	//first sort the given edge matrix because we need min weight of edge first than greater
	sort(edges , edges+nEdges , compare);
	//ok now we need an output array of type edge in which we store our output mst.........
	Edge * outputMST=new Edge[nVertices-1];
	//nVertices-1 because for mst only n-1 edges possible greater than this make cycle in tree which is not allowed

	//now we need to store the parent of each new vertices for which newly two vertices with same parent
	//not make an edge in mst other wise it will create cycle in mst...
	int *parent=new int[nVertices];
	//initially all vertieces is the parent of their own
	for (int i = 0; i < nVertices; ++i)
	{
		parent[i]=i;
	}

	int nMstEdge=0;
	int edgeIndex=0;
	while(nMstEdge < (nVertices-1) )
	{
		//as soon as we get nVertices-1 edges in our mst don't need to go further because if we
		// go further and add any single edge then it make cycle in mst because a tree of n node
		// has atmost n-1 edges.. otherwise it become a graph
		int source = edges[ edgeIndex ].Source;
		int destination = edges[ edgeIndex ].Destination;
		//check weather both source and destination has same root node?
		int sourceParent = getParent(source , parent);
		int destinationParent = getParent(destination , parent);
		if (sourceParent != destinationParent)
		{
			//that's means our source and destination is from different clusture
			//we can make an edge from source to destination in our mst
			outputMST[ nMstEdge ] = edges[ edgeIndex ];
			//and now we have to make both clusture (source and destination) same..
			//i.e. now root node of both source and destination became same in mst due to this edge
			//update parent
			parent[ sourceParent ] = destinationParent;
			//that's means now the parent of source is equal to parent of destination
			nMstEdge++;
		}
		//in each condition we have to traverse one step further in edge
		edgeIndex++;
	}
	return outputMST;
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;
	Edge *edges=new Edge[nEdges];
	for (int i = 0; i < nEdges; ++i)
	{
		int s,d,w;
		cin>>s>>d>>w;
		//store edges with weight
		edges[i].Source = s;
		edges[i].Destination = d;
		edges[i].weight = w;
	}
	//we need an output array of type edge which store mst of given graph
	Edge *outputMST=getMst(nVertices , nEdges , edges);
	//print mst
	for (int i = 0; i < nVertices-1; ++i)
	{
		if (outputMST[i].Source < outputMST[i].Destination)
		{
			cout<<outputMST[i].Source <<" "<<outputMST[i].Destination<<" "<<outputMST[i].weight<<endl;
		}else{
			cout<<outputMST[i].Destination <<" "<<outputMST[i].Source<<" "<<outputMST[i].weight<<endl;
		}
	}
	return 0;
}