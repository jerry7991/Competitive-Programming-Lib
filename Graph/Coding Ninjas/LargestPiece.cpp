#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];
int traverseDfs(bool **isVisited , int n , int si , int sj)
{
	isVisited[si][sj]=true;
	int answer=0;
	if (	(si+1)<n && cake[si+1][sj]=='1'	&& !isVisited[si+1][sj])
	{
		answer = 1+ traverseDfs(isVisited , n , si+1 , sj);
	}
	if (	(sj+1)<n && cake[si][sj+1]=='1'	&& !isVisited[si][sj+1])
	{
		answer += 1+traverseDfs(isVisited , n , si , sj+1);
	}
	if (	(si-1)>=0 && cake[si-1][sj]=='1'	&& !isVisited[si-1][sj])
	{
		answer += 1+ traverseDfs(isVisited , n , si-1 , sj);
	}
	if (	(sj-1)>=0 && cake[si][sj-1]=='1'	&& !isVisited[si][sj-1])
	{
		answer += 1+traverseDfs(isVisited , n , si , sj-1);
	}
	return answer;
}	
int solve(int n,char cake[NMAX][NMAX])
{
	bool **isVisited=new bool*[n];
	for (int i = 0; i < n; ++i)
	{
		isVisited[i]=new bool[n];
		for (int j = 0; j < n; ++j)
		{
			isVisited[i][j]=false;
		}
	}
	int maxOne=0;
	for (int i = 0; i < n; ++i)
	{
		for(int j=0 ; j<n ; j++)
		{
			if ( ! isVisited[i][j] && cake[i][j]=='1')
			{
				int currMax=traverseDfs(isVisited , n , i , j);
				maxOne	=	(currMax>maxOne)? currMax :maxOne;
			}
		}
	}
	return maxOne+1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}