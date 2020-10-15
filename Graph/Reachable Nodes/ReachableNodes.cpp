#include <iostream>
#include <vector>
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define pb(n) push_back(n)
using namespace std;
int numberOfNodes=0;
void dfs(int n ,vector<int>* edges , bool *visited, int start)
{
	visited[start]=true;
	fon(i , edges[start].size())
	{
		int adjacent=edges[start][i];
		if (!visited[adjacent])
		{
			numberOfNodes++;
			dfs(n , edges ,visited,adjacent );
		}
	}
}
void printSolution(int n ,vector<int>* edges)
{
	bool *visited=new bool[n];
	fon(i,n) visited[i]=false;
	numberOfNodes=1;
	fon(i ,n)
	{
		numberOfNodes=1;
        fon(j,n)
            visited[j]=false;
        dfs(n, edges , visited ,i);
        cout<<numberOfNodes<<endl;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>* edges=new vector<int>[n];
	fon(i , m)
	{
		int src,dest;
		cin>>src>>dest;
		edges[src-1].pb(dest-1);
	}
	printSolution(n , edges);
	return 0;
}