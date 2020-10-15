#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int isCyclic(char board[][MAXN] ,bool ** isVisited ,int n ,int m ,int si , int sj)
{
	isVisited[si][sj]=true;
	int answer = 1;
	if ( (si+1)<n && board[si+1][sj]==board[si][sj] && !isVisited[si+1][sj])
	{	
		answer =1+ isCyclic(board , isVisited , n , m , si+1 , sj);
	}
	if ( (sj+1)<m && board[si][sj+1]==board[si][sj]  && !isVisited[si][sj+1])
	{
		answer =1+ isCyclic(board , isVisited , n , m , si , sj+1);
	}
	if ( (si-1)>=0 && board[si-1][sj]==board[si][sj] && !isVisited[si-1][sj])
	{
		answer =1+ isCyclic(board , isVisited , n , m , si-1 , sj);
	}
	if ( (sj-1)>=0 && board[si][sj-1]==board[si][sj] && !isVisited[si][sj-1])
	{
		answer	=1+ isCyclic(board , isVisited , n , m , si , sj-1);
	}
	return answer;
}
int solve(char board[][MAXN],int n, int m)
{
	bool **isVisited=new bool*[n];
	for (int i = 0; i < n; ++i)
	{
		isVisited[i]=new bool[m];
		for(int j=0 ; j< m ; j++)
		{
			isVisited[i][j]=false;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for(int j= 0; j<m ; ++j)
		{
			if ( ! isVisited[i][j])
			{
				int answer=isCyclic(board , isVisited , n , m , i , j);
				//cout<<board[i][j]<<"\t"<<answer<<endl;
				if (answer >3)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}