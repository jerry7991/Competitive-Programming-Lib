#include <iostream>
#include <vector>
using namespace std;
std::vector<int> path;
bool getPath(bool ** isPath ,bool *isVisited ,int nVertices ,int source ,int destination)
{
	if (source==destination)
	{
        return true;
	}
	for (int i = 0; i < nVertices; ++i)
	{
		if (i==source)
		{
			continue;
		}
		if(isPath[source][i]==1 && !isVisited[i])
		{
			//make i as visited
			isVisited[i]=true;
			bool answer=getPath(isPath ,isVisited ,nVertices , i ,destination);
            if(answer)
            {
			//now new source will be i and i is included into our path from source to destination
			path.push_back(i);
            return true;//because we have found the paht just pop the funciton and store i which i have visited
            }
            //if not then look for other path which goes next i-th vertex
		}
	}
    return false;
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;

	bool **isPath=new bool*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isPath[i]=new bool[nVertices];
		for(int j=0 ; j<nVertices ; j++)
		{
			isPath[i][j]=false;
		}
	}
	bool * isVisited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isVisited[i]=false;
	}
	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		isPath[source][destination]=true;
		isPath[destination][source]=true;//cause of undirected
	}
	int source,destination;
	cin>>source>>destination;
	//initialy path has starting point i.e. source:-
	isVisited[source]=true;
	bool answer=getPath(isPath ,isVisited ,nVertices , source ,destination);
    
	path.push_back(source);
    if(answer)
    {
        std::vector<int> ::iterator itr=path.begin();
        while(itr!= path.end())
        {
            cout<<*itr<<" ";
            itr++;
        }
    }
	return 0;
}