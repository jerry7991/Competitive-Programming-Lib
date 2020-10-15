#include <iostream>
#include <vector>
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define pb(n) push_back(n)
using namespace std;
bool isReachable(int * edges,bool *visited, int src ,int dest , int n)
{
	visited[src]=true;
	if(src==dest)
		return true;
	if (src>=n || visited[edges[src]])
	{
		return false;
	}
	return isReachable(edges ,visited ,edges[src] , dest, n);
}
int main()
{
	int n,t;
	cin>>n>>t;
	int * edges=new int[n];
	bool *visited=new bool[n];
	fon(i , n-1)
	{
		int x;
		cin>>x;
		edges[i]=i+x;
		visited[i]=false;
	}
	bool ans=isReachable( edges, visited,0 , t-1 , n);
	if (ans)
	{
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}