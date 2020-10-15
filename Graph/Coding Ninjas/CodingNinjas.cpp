#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
bool isTheirWay(char Graph[][MAXN] ,bool ** isVisited ,char * requiredStr ,int n,int m ,int req_len , int si ,int sj )
{
    if(req_len>11)
    {
        return true;
    }
    if(Graph[si][sj]=='A')
        return true;
	isVisited[si][sj]=true;
    bool answer = false;
	if ( (si+1)<n	&& Graph[si+1][sj]==requiredStr[req_len] && !isVisited[si+1][sj] )
	{
		answer=answer||isTheirWay(Graph , isVisited , requiredStr , n, m , req_len+1 , si+1 , sj);
		
	}
    if ( (sj+1)<m && Graph[si][sj+1]==requiredStr[req_len] && !isVisited[si][sj+1] )
	{
		answer= answer||isTheirWay(Graph , isVisited , requiredStr , n, m , req_len+1 , si , sj+1);
		
	}
    if( (si+1)<n && (sj+1)<m && Graph[si+1][sj+1]==requiredStr[req_len] && !isVisited[si+1][sj+1] )
	{
		answer=answer||isTheirWay(Graph , isVisited , requiredStr , n, m , req_len+1 , si+1 , sj+1);
		
	}
  	 if( (si-1)>=0 && Graph[si-1][sj]==requiredStr[req_len] && !isVisited[si-1][sj] )
	{
		answer=answer||isTheirWay(Graph , isVisited , requiredStr , n, m , req_len+1 , si-1 , sj);
		
	}
     if ( (sj-1)>=0 && Graph[si][sj-1]==requiredStr[req_len] && !isVisited[si][sj-1] )
	{
        answer=answer||isTheirWay(Graph , isVisited , requiredStr , n, m , req_len+1 , si , sj-1);
		
	}
    if ( (si-1)>=0 && (sj-1)>=0 && Graph[si-1][sj-1]==requiredStr[req_len] && !isVisited[si-1][sj-1] )
	{
		answer=answer||isTheirWay(Graph , isVisited , requiredStr , n, m , req_len+1 , si-1 , sj-1);
		
	}
    if ( (si+1)<n && (sj-1)>=0 && Graph[si+1][sj-1]==requiredStr[req_len] && !isVisited[si+1][sj-1] )
	{
		answer=answer||isTheirWay(Graph , isVisited , requiredStr , n , m, req_len+1 , si+1 , sj-1);
		
	}
    if ( (si-1)>=0 && (sj+1)<m && Graph[si-1][sj+1]==requiredStr[req_len] && !isVisited[si-1][sj+1])
	{
		 answer=answer||isTheirWay(Graph , isVisited , requiredStr , n, m , req_len+1 , si-1 , sj+1);
		
	}
    return answer;
}
int solve(char Graph[][MAXN],int N, int M)
{
	char requiredStr[11]={'C','O','D','I','N','G','N','I','N','J','A'};
	bool **isVisited=new bool*[N];
	for (int i = 0; i < N; ++i)
	{
		isVisited[i]=new bool[M];
		for(int j=0 ; j<M ; j++)
		{
			isVisited[i][j] =  false;
		}
	}
	for (int si = 0; si < N; ++si)
	{
		for(int sj=0 ; sj<M ; sj++)
		{
			if (Graph[si][sj]==requiredStr[0])
			{
				bool answer =isTheirWay( Graph , isVisited , requiredStr ,N,M ,1 , si , sj );
				if (answer)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}