#include<iostream>
#include<vector>
using namespace std;
void traverseDFS(bool **isPath , bool *isVisited , int n,int start)
{
	isVisited[start]=true;
	for (int i = 0; i < n; ++i)
	{
		if (i==start)
		{
			continue;
		}
		if (isPath[start][i]==1 && !isVisited[i])
		{
			//make it visited
			isVisited[i]=true;
			//and exploring this i
			traverseDFS(isPath , isVisited , n , i);
		}
	}
}
int solve(int n,int m,vector<int> source,vector<int> destination)
{
	bool **isPath=new bool*[n];
	for (int i = 0; i < n; ++i)
	{
		isPath[i]=new bool[n];
		for(int j=0 ; j<n ; j++)
		{
			isPath[i][j]=false;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		isPath[source[i]-1][destination[i]-1]=true;
		isPath[destination[i]-1][source[i]-1]=true;
	}
	bool *isVisited=new bool[n];
	for (int i = 0; i < n; ++i)
	{
		isVisited[i]=false;
	}
	int nDisconnected=0;
	for (int start = 0; start < n; ++start)
	{
		if (!isVisited[start])
		{
			traverseDFS(isPath , isVisited , n ,start);
			nDisconnected++;
		}
	}
	return nDisconnected;
}
int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}