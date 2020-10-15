#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
#define fon(i , n) for(int i=0  ; i<n ; i++)
bool checkPath(char graph[][MAXN] , char req[] ,bool **visited ,int si , int sj ,int n,int m)
{
	//base case
	//cout<<req[0]<<" "<<si<<", "<<sj<<endl;
	if(req[0]=='\0')	return true;	//string formed
	bool ans=false;
	visited[si][sj]=true;
	if(si+1<n)//one row down
	{
		if(graph[si+1][sj]==req[0] && !visited[si+1][sj]){
			ans = ans || checkPath(graph , req+1 , visited , si+1 , sj , n , m);
			if(ans) return ans;//for more efficience
		}
		if(sj+1<m && graph[si+1][sj+1]==req[0] && !visited[si+1][sj+1]){
			ans = ans || checkPath(graph , req+1, visited , si+1, sj+1 , n , m);
			if(ans) return ans;
		}
		if(sj>0 && graph[si+1][sj-1]==req[0] && !visited[si+1][sj-1]){
			ans = ans || checkPath(graph , req+1, visited , si+1, sj-1 , n , m);
			if(ans) return ans;	
		}
	}
	if(si>0)//one row up
	{
		if(graph[si-1][sj]==req[0] && !visited[si-1][sj]){
			ans = ans || checkPath(graph , req+1, visited , si-1, sj , n , m);
			if(ans) return ans;
		}
		if(sj>0 && graph[si-1][sj-1]==req[0] && !visited[si-1][sj-1]){
			ans = ans || checkPath(graph , req+1, visited , si-1, sj-1 , n , m);
			if(ans) return ans;
		}
		if(sj+1<m && graph[si-1][sj+1]==req[0] && !visited[si-1][sj+1]){
			ans = ans || checkPath(graph , req+1, visited , si-1, sj+1 , n , m);
			if(ans) return ans;
		}
	}
	if(sj>0 && graph[si][sj-1]==req[0] && !visited[si][sj-1]){//left
		ans = ans || checkPath(graph , req+1, visited , si, sj-1 , n , m);
			if(ans) return ans;
	}
	if(sj+1<m && graph[si][sj+1]==req[0] && !visited[si][sj+1]){//right
		ans = ans || checkPath(graph , req+1, visited , si, sj+1 , n , m);
			if(ans) return ans;
	}
    //we should back track
    visited[si][sj]=false;
	return ans;
}
int solve(char Graph[][MAXN],int n, int m)
{
	char req[]={'C','O','D','I','N','G','N','I','N','J','A','\0'};
	bool **visited=new bool*[n];
	fon(i,n){
		visited[i]=new bool[m];
		fon(j,m) visited[i][j]=false;
	}
	fon(i,n){
		fon(j,m){
			if(Graph[i][j]==req[0]){
				//do dfs
				bool isPath=checkPath(Graph , req+1 ,visited, i,j,n,m);
				if(isPath) return isPath;
			}
		}
	}
	return 0;
}
int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	fon(i,N){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}