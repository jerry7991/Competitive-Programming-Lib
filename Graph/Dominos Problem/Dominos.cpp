#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#define fon(i , n) for(unsigned int i=0 ; i<n ; i++)
#define uos unordered_set
using namespace std;
void dfs2(vector<int>* edges ,uos<int>& visited ,int start )
{
	visited.insert(start);
	fon(i , edges[start].size())
	{
		int Adjacent=edges[start][i];
		if (visited.count(Adjacent)==0)
		{
			dfs2(edges , visited ,  Adjacent );
		}
	}
}
void dfs(vector<int>* edges ,uos<int>& visited , stack<int> & finishedVertices,int start )
{
	visited.insert(start);
	fon(i , edges[start].size())
	{
		int Adjacent=edges[start][i];
		if (visited.count(Adjacent)==0)
		{
			dfs(edges , visited , finishedVertices ,  Adjacent );
		}
	}
	//once we have done........
		finishedVertices.push(start);
}
int getSCC(vector<int> * edges ,int nVertices)
{
	uos<int> visited;
	stack<int> finishedVertices;
	fon(i , nVertices)
	{
		if (visited.count(i)==0)
		{
			dfs(edges , visited ,finishedVertices , i );
		}
	}
	visited.clear();
	int knockByHand=0;
	while( !finishedVertices.empty())
	{
		int currentNode=finishedVertices.top();
		cout<<currentNode<<endl;
		finishedVertices.pop();
		if (visited.count(currentNode)==0)
		{
			knockByHand++;
			dfs2(edges , visited , currentNode );
		}
	}
	return knockByHand;
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int nVertices,nEdges;
		cin>>nVertices>>nEdges;
		//Adjacent List
		vector<int> * edges=new vector<int>[nVertices];
		fon( i , nEdges)
		{
			int source,destination;
			cin>>source>>destination;
			edges[source-1].push_back(destination-1);
		}
		int answer=getSCC(edges , nVertices);
		cout<<answer<<endl;
	}
}