#include <iostream>
#include <vector>
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define pb(n) push_back(n)
using namespace std;
int timer;
void dfs(vector<int>* edges ,bool * visited , int *entryNode ,int* exitNode,int start , int parent=-1)
{
	//make current node as visited
	visited[start]=true;
	//initialize the timer initially
	entryNode[start]=exitNode[start]=timer++;
	//explore all the edges of start
	fon(i , edges[start].size())
	{
		int adjacent=edges[start][i];
		if (adjacent==parent)
		{
			continue;
		}
		if (!visited[adjacent])
		{
			//do first dfs with current adjacent
			dfs(edges , visited , entryNode , exitNode,adjacent , start);
			//once we have done with current adjacent then while backtracking we store
			//the acknowledgement of exitNode
			exitNode[start]=min(exitNode[start] , exitNode[adjacent]);
			if (exitNode[adjacent]>entryNode[start])
			{
				cout<<start<<" "<<adjacent;
			}
		}else{
			//already visited we are going to back track
			exitNode[start]=min(exitNode[start] , entryNode[adjacent]);
		}
	}
}
void printBridges(vector<int>* edges ,int nVertices)
{
	bool *visited=new bool[nVertices];
	fon(i , nVertices) visited[i]=false;
	int *entryNode=new int[nVertices];
	int *exitNode=new int[nVertices];
	timer=0;
	fon(i , nVertices)
	{
		if(!visited[i])
		{
			dfs(edges , visited , entryNode , exitNode,i);
		}
	}
}
int main()
{
	int nVertices , nEdges;
	cin>>nVertices>>nEdges;
	vector<int> *edges=new vector<int>[nVertices];
	fon(i , nEdges)
	{
		int source,destination;
		cin>>source>>destination;
		edges[source].pb(destination);
		edges[destination].pb(source);
	}
	printBridges(edges , nVertices);
	return 0;
}
/*
6 6
0 1
1 2
2 3
2 4
3 5
3 4
*/