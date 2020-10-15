#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
void dfs(vector<int> *edges , unordered_set<int> & visited , stack<int> &finishedStack , int start )
{
	visited.insert(start);
	//explore the start vertex
	for (unsigned int i = 0; i < edges[start].size(); ++i)
	{
		int adjacent=edges[start][i];
		if ( visited.count(adjacent)==0 )
		{
			dfs(edges , visited , finishedStack , adjacent );
		}	
	}
	//once we have done with each start then we are going to store start
	finishedStack.push(start);
}
void dfs2(vector<int>* transposeEdges ,unordered_set<int> & visited ,unordered_set<int>* component  , int start)
{
	visited.insert(start);
	//insert this node in component
	component->insert(start);
	//explore start node and till the end ,one by one adjacent node
	for (unsigned int i = 0; i < transposeEdges[start].size(); ++i)
	{
		int adjacent=transposeEdges[start][i];
		if ( visited.count(adjacent)==0 )//such no element like i
		{
			dfs2(transposeEdges , visited , component ,adjacent );
		}
	}
}
unordered_set< unordered_set<int>*> * getSCC(vector<int>* edges ,vector<int>* transposeEdges ,int nVertices)
{
	//we need to track what i have done
	unordered_set<int>visited;
	//we need an stack whichs store the vertex according their finish time
	stack<int> finishedVertices;
	for (int i = 0; i < nVertices; ++i)
	{
		if ( visited.count(i)==0 )
		{
			dfs(edges , visited , finishedVertices , i);
		}
	}
	//once we have done than we have a stack of finishedVertex
	//clear acknowledgement about previous visited data
	visited.clear();
	//we need a data structre to store the all strongly connected component
	unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
	while(  finishedVertices.size()!=0 )
	{
		int element=finishedVertices.top();
		finishedVertices.pop();
		//check if it is visited or not
		if ( visited.count(element)==0 )
		{
			unordered_set<int> * component=new unordered_set<int>();
			dfs2(transposeEdges , visited , component  , element);
			//and we have got one new strongly connected component
			output->insert(component);
			//delete component;
		}
	}
	//now return all strongly connected component
	return output;
}
int main()
{
	int nVertices, nEdges;
	cin>>nVertices>>nEdges;
	vector<int> * edges=new vector<int>[nVertices];
	vector<int> *transposeEdges=new vector<int>[nVertices];
	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		edges[source-1].push_back(destination-1);
		//store transpose too
		transposeEdges[destination-1].push_back(source-1);
	}
	unordered_set<unordered_set<int>*> *connectedComp;//= new unordered_set<unordered_set<int>*>();
	connectedComp=getSCC(edges , transposeEdges , nVertices);
	//print the connected component
	unordered_set<unordered_set<int>*> ::iterator it=connectedComp->begin();

	while(it!= connectedComp->end())
	{
		unordered_set<int> *component=*it;

		unordered_set<int>::iterator it2=component->begin();
		while(it2!= component->end())
		{
			cout<<*it2 +1 <<" ";
			it2++;
		}
		delete component;
		cout<<endl;
		it++;
	}
	delete []edges;
	delete [] transposeEdges;
	delete connectedComp;
}
/*
7
8
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
//////////////////
11
13
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
8 7
8 9
9 8
9 10
10 11
*/