#include <iostream>
#include <vector>
#define fon(i , n) for(int i=0 ; i<n ; i++)
#define pb(n) push_back(n)
using namespace std;
bool checkCycle(int start ,bool * visited ,vector<int>* edges , int parent)
{
	//mark start as visited
	visited[start]=true;
	//explore start
	fon(i , edges[start].size())
	{
		int neighbour=edges[start][i];
		if (!visited[neighbour])
		{
		  bool isCycle=checkCycle(neighbour , visited , edges , start);//now parent will be start
		  if (isCycle)
		  {
		  	return true;
		  }
		}else if (parent!=neighbour)
		{
			return true;
		}
	}
	return false;
}
bool checkItIsTree(int n,vector<int>* edges)
{
	bool *visited=new bool[n];
	fon(i,n) visited[i]=false;
	
	//first check weather graph has cycle or not
	bool isCycle=checkCycle(0 , visited , edges , -1);
	if (isCycle)
	{
		return false;
	}
	//if not cyclic then check weather all node is visited or not
	fon(i , n) if(!visited[i] && i!=1) return false;
	return true;
}
int main()
{
	int n,m;
	cin>>n>>m;
	if (m!=n-1)	//for making a tree of node n we have at least n-1 edges;
	{
		cout<<"NO";
		return 0;
	}
	vector<int>*edges=new vector<int>[n];
	fon(i,m)
	{
		int src,dest;
		cin>>src>>dest;
		edges[src-1].pb(dest-1);
		edges[dest-1].pb(src-1);
	}
	if(checkItIsTree(n,edges))
	cout<<"YES";
	else
		cout<<"NO";
	return 0;
}