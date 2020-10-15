#include <iostream>
#include <queue>
using namespace std;
bool isTheirAnyPath(bool ** isPath , int nVertices , int source ,int destination)
{
	if (source==destination)
	{
		return true;
	}
	bool *isVisited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isVisited[i]=false;
	}
	//initialize a queue
	queue<int> pendingVertices;
	pendingVertices.push(source);
	isVisited[source]=true;

	//now let's explore each path from source according to bfs rule OK!!!!
	while(	!pendingVertices.empty())
	{
		//get front pended vertex and explore them
		int currentVertex=pendingVertices.front();
		//marks currentVertex as Visited
		isVisited[currentVertex]=true;
		//remove that element form pending queue
		pendingVertices.pop();
		//check weather the current gotted element is our destination or not
		if(currentVertex==destination)
			return true;
		//other wise explore and append all non-visited vertex from currentIndex
		for (int i = 0; i < nVertices; ++i)
		{
			if (i==currentVertex)
			{
				continue;
			}
			if(isPath[currentVertex][i]==1 && !isVisited[i])
			{
				/*
					if there is such path from currentVertex to i which is not visited then append this 
					in queue and mark it visited so that it wouldn't get appended again
				*/
				pendingVertices.push(i);
				//mark visited:
				isVisited[i]=true;
			}
		}
	}
	//if none of above return gets invoked i.e. there is no such path from source to destination
	return false;
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;

	bool ** isPath=new bool*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isPath[i]=new bool[nVertices];
		for(int j=0 ; j<nVertices ; j++)
		{
			isPath[i][j]=false;
		}
	}

	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		isPath[source][destination]=true;
		isPath[destination][source]=true;//cause of undirected graph
	}
	int source,destination;
	cin>>source>>destination;
	bool answer=isTheirAnyPath(isPath , nVertices , source ,destination);
	if (answer)
	{
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
}