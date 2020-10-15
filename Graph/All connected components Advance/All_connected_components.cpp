#include<iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
void dfs(vector<int>* edges ,bool * visited ,unordered_set<int> * connectComp ,int start)
{
	//first make visited start
	visited[start]=true;
	//store it in connectedComponent
	connectComp->insert(start);
	//explore start's neighbours
	for (unsigned int i = 0; i < edges[start].size(); ++i)
	{
		int next = edges[start][i];
		if (!visited[next])
		{
			dfs(edges , visited , connectComp , next);
		}
	}
}
unordered_set< unordered_set<int>* >* getConnectedComponent(std::vector<int> * edges ,int nVertices)
{
	//we need an visited array
	bool *visited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		visited[i]=false;
	}
	//we need an array of set (of an array of set) to store output
	unordered_set< unordered_set<int>* > * output = new unordered_set< unordered_set<int> *>();
	for (int i = 0; i < nVertices; ++i)
	{
		if ( !visited[i])
		{
			//we will call the dfs for each non-visited element 
		//and each dfs will give me the all the vertices that can be reached by current i
		//so we need to store each connected component
		unordered_set<int >* currConnectComp=new unordered_set<int>();

		dfs(edges , visited , currConnectComp , i);
		//now after doing dfs on i we get all the vertices that can be reached way i 
		//so store it
		output->insert(currConnectComp);//-> because we are storing the reference
		}
	}

	delete [] visited;
	return output;
}
int main()
{
	int nVertices,nEdge;
	cin>>nVertices>>nEdge;

	//using adjacent matrix
	std::vector<int> * edges=  new std::vector<int>[nVertices];
	for (int i = 0; i < nEdge; ++i)
	{
		int source,destination;
		cin>>source>>destination;

		//store the source->destinaton and vice versa
		edges[source].push_back(destination);
		edges[destination].push_back(source);
	}

	//now we need an set of set of connected component
	unordered_set< unordered_set<int>* > * connectedComponent = getConnectedComponent(edges , nVertices);

	//now let's print the all connected components;
	//make an iteratore
	unordered_set< unordered_set<int> * > ::iterator itr=connectedComponent->begin();

	while(itr != connectedComponent->end())//->because of type pointer
	{
		unordered_set<int> *component= *itr;
		//make an iterator for each individual connected components
		unordered_set< int> :: iterator it=component->begin();
		while(it!= component->end())
		{
			cout<<*it<<" ";
			it++;
		}
		cout<<endl;
		//delete component;
		itr++;
		//delete connectedComponent;
	}
	return 0;
}