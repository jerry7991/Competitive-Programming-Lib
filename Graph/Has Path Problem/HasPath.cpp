#include <iostream>
using namespace std;
bool isTheirPath(bool **isPath ,int nVertices ,bool * isVisited ,int source ,int  destination)
{
	if (source==destination)
	{
		isVisited[source]=true;
		return true;
	}
	for (int i = 0; i < nVertices; ++i)
	{
		if (i==source)
		{
			continue;
		}
		//find the first non-visited vertex and explore them ok!!!!
		if (isPath[source][i]==1 && ! isVisited[i])
		{
			/*
				if there is any such path from source to i which is not yet visited then 
				make i as a new source and start exploring the rest of node....
			*/
			isVisited[i]=true;
			int isAnyPath=isTheirPath(isPath , nVertices , isVisited , i , destination);
			if (isAnyPath)
			{
				return true;
			}
		}
	}
	//none of above return got invoke then their is no such path:-
	return false;
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;

	//make way to store the path related data;
	bool ** isPath=new bool*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isPath[i]=new bool[nVertices];
		for(int j=0 ; j<nVertices ; j++)
		{
			isPath[i][j]=false;
		}
	}

	//store the path:-
	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		//save it;
		isPath[source][destination]=true;
		isPath[destination][source]=true;
	}
	//for acknowledgement of either visited or not
	bool *isVisited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isVisited[i]=false;
	}
	int source,destination;
	cin>>source>>destination;
	bool isAnyPath=isTheirPath(isPath , nVertices , isVisited , source , destination);
	if (isAnyPath)
	{
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
}