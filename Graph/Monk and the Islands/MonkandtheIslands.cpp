#include<iostream>
#include <vector>
#include <queue>
#define pb(n) push_back(n)
#define fon(i , n ) for(int i=0 ; i<n ; i++)
using namespace std;
int getMinPath(vector<int> * edges ,int nVertices)
{
	bool *visited=new bool[nVertices];
	//we need to maintain a level array
	int *level=new int[nVertices];
	fon(i , nVertices)
	{
		visited[i]=false;
		level[i]=0;
	}
	queue<int> pendingVertices;
	visited[0]=true;
	pendingVertices.push(0);
	while(!pendingVertices.empty())
	{
		int currentNode=pendingVertices.front();
		pendingVertices.pop();
		if (currentNode==(nVertices-1))
		{
			break;
		}
		fon(i , edges[currentNode].size())
		{
			int neighbour=edges[currentNode][i];
			if ( !visited[neighbour] )
			{
				//make it visited 
				visited[neighbour]=true;
				pendingVertices.push(neighbour);
				//update the level of neighbour
				level[neighbour]=level[currentNode]+1;
			}
		}
	}
	// fon(i , nVertices)
	// {
	// 	cout<<i<<" level "<<level[i]<<endl;
	// }
    int ans=level[nVertices-1];
    delete []visited;
    delete []level;
	return ans;
}
int main()
{
	int testCase;
	cin>>testCase;
	while(testCase--)
	{
		int nVertices,nEdges;
		cin>>nVertices>>nEdges;
		vector<int> * edges=new vector<int> [nVertices];
		fon(i , nEdges)
		{
			int soure,destination;
			cin>>soure>>destination;
			edges[soure-1].pb(destination-1);
			edges[destination-1].pb(soure-1);	//cause Bidirectional 
		}
		int minDistance=getMinPath(edges , nVertices);
		cout<<minDistance<<endl;
        delete []edges;
	}
}