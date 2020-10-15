#include <iostream>
#include<stack>
using namespace std;
//we need an stack to store vertices as their finish time
stack<int> finishVertices;
void dfs(int **edges  ,int nEdges ,bool * visited , int start  , bool flag)
{
	//make start as visited 
	visited[start]=true;
	if (!flag)
	{
		cout<<start<<" ";
	}
	//pick one vertex one by one explore them till the end
	for (int i = 0; i < nEdges; ++i)
	{
		if(i==start)
		{
			continue;
		}
		if (!visited[i] && edges[start][i]==1)
		{
			dfs(edges  , nEdges , visited, i,flag);
		}
	}
	if(flag)
	{
		//and once node done dfs from all the path which is going from him store it in stack
		finishVertices.push(start);
	}
}
void getConnecedComponent(int **edges ,int nVertices , int nEdges)
{
	//we need an visited array
	bool *visited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		visited[i]=false;
	}
	for (int i = 0; i < nVertices; ++i)
	{
		if (!visited[i])
		{
			dfs(edges  , nEdges , visited, i , true);
		}
	}
	//need to transpose the graph
	int **transposeEdges=new int*[nEdges];
	for (int i = 0; i < nEdges; ++i)
	{
		transposeEdges[i]=new int[nVertices];
		for(int j=0 ; j< nVertices ; j++)
		{
			transposeEdges[i][j]=edges[j][i];
		}
	}
	for (int i = 0; i < nVertices; ++i)
	{
		visited[i]=false;
	}
	//now perform stack operation:-
	while( !finishVertices.empty())
	{
		int currentIndex=finishVertices.top();
		finishVertices.pop();
		//cout<<currentIndex;
		if (!visited[currentIndex])
		{
			dfs(transposeEdges  , nEdges , visited, currentIndex , false);
			cout<<endl;
		}
	}
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;
	int **edges=new int*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		edges[i]=new int[nEdges];
		for (int j = 0; j < nEdges; ++j)
		{
			edges[i][j]=0;
		}
	}
	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		edges[source][destination]=1;//directed so vice verse not possible
	}
	getConnecedComponent(edges , nVertices , nEdges);
	return 0;
}
/*
10
12
0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4
7 6
7 8
8 9
8 7
*/