#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
bool **visited;
int row,si;
int col,sj;
bool is3Cycle(char board[][MAXN] ,int currI , int currJ , int count=1){
	if(visited[currI][currJ] &&	currI==si && currJ==sj )	return count>3;
	if(visited[currI][currJ]) return false;
	bool found=false;
	visited[currI][currJ]=true;
	char currChar=board[si][sj];
	if(currI+1<row &&	board[currI+1][currJ]==currChar){
		found |=is3Cycle(board , currI+1 , currJ , count+1 );
		if(found) return found;
	}
	if(currI>0 && board[currI-1][currJ]==currChar){
		found |=is3Cycle(board , currI-1 , currJ , count+1 );
		if(found) return found;
	}
	if(currJ+1<col && board[currI][currJ+1]==currChar){
		found |=is3Cycle(board , currI , currJ+1 , count+1 );
		if(found) return found;
	}
	if(currJ>0 && board[currI][currJ-1]==currChar){
		found |=is3Cycle(board , currI , currJ-1 , count+1 );
		if(found) return found;
	}
	//backtrack
    visited[currI][currJ]=false;
	return found;
}
bool solve(char board[][MAXN] , int n , int m){
	row=n;
	col=m;
	visited=new bool*[n];
	for(int i=0  ; i<n ;i++){
		visited[i]=new bool[m];
		for(int j=0 ; j<m ; j++) visited[i][j]=false;
	}
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++)
		{
			if(visited[i][j]) continue;
			bool ans=false;
			si=i;
			sj=j;
			ans=is3Cycle(board  , i , j);
			if(ans) return ans;
		}
	}
	return false;
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