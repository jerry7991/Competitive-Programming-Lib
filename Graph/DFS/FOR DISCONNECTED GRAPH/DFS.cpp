#include<iostream>
using namespace std;
void printDFS(int **isPath ,int nVertex ,int startVertex ,bool * isVisited )
{
	cout<<startVertex<<endl;
	//first make startVertex as a visited
	isVisited[startVertex]=true;
	for (int i = 0; i < nVertex; ++i)
	{
		if(i==startVertex)
		{
			continue;
		}
		//if there is any path in betweeen startVertex to i
		if (isPath[startVertex][i]==1)
		{
			//and that i-th node is not visited yet
			if ( ! isVisited[i])
			{
				//make it visited and start explorign path from i-th vertex to rest of non-visited
				printDFS(isPath , nVertex , i , isVisited);
			}
		}
	}
}
int main()
{
	int nVertex,nEdges;
	cin>>nVertex>>nEdges;
	int **isPath=new int*[nVertex];
	for (int i = 0; i < nVertex; ++i)
	{
		isPath[i]=new int[nVertex];
		for(int j=0 ; j<nVertex ; j++)
		{
			isPath[i][j]=0;
		}
	}
	cout<<"Enter the path like (source and distination)"<<endl;
	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		isPath[source][destination]=1;
		isPath[destination][source]=1;
	}
	bool * isVisited=new bool[nVertex];
	for (int i = 0; i < nVertex; ++i)
	{
		isVisited[i]=false;
	}
	for (int i = 0; i < nVertex; ++i)
	{
		if (! isVisited[i])
		{
			//we find non-visited and start exploring them
			printDFS(isPath , nVertex ,i , isVisited );
		}
	}
	//free all allocated memory
	for (int i = 0; i < nVertex; ++i)
	{
		delete [] isPath[i];
	}
	delete [] isPath;
	delete [] isVisited;
}
/*
 INPUT:-
 0 1
1 3
1 4
3 5
4 5
6 7
6 8
9 10
7 8
OUTPUT:-
0
1
3
5
4
2
6
7
8
9
10
*/