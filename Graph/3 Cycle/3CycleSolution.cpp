#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int m,vector<int>u,vector<int>v)
{
	bool **isPath=new bool*[n+1];
	for (int i = 1; i <= n; ++i)
	{
		isPath[i]=new bool[m+1];
		for(int j=1 ; j<=m; j++)
		{
			isPath[i][j]=false;
		}
	}
	for (int i = 0; i <m; ++i)
	{
		int x=u[i], y=v[i];
		isPath[ x ][ y ]=true;
		isPath[ y ][ x ]=true;
	}

	int totalCycle=0;
	for (int i = 1; i <=n; ++i)
	{
		for(int j=1 ; j<=m ; ++j)
		{
			if (i==j || (! isPath[i][j]) )
			{
				continue;
			}
			//if there is any path from i to j
			for( int k=1 ; k <=m ; k++)
			{
				//then check all the adjaceny vertex from j to k
				if (k==j || (! isPath[j][k]) )
				{
					continue;
				}
				//if there is any adjacency vertex from i to k
				if (isPath[i][k])
				{
					totalCycle++;
				}
			}
		}
	}
	//because each vertex exactly called 2 times that's why total 3 vertex gives 6 time more input
	return (totalCycle/6);
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