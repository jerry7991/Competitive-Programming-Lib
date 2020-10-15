#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int countPaths(int **maze , int n , int m ){
	int **dp=new int*[n];
	fon(i,n)
		dp[i]=new int[m];
	//base case
	dp[n-1][m-1]=1;
	//base case for col
	fon(i,n-1){
		dp[i][m-1]=(maze[i][m-1]!=-1);
	}
	//base case for row
	fon(i,m-1){
		dp[n-1][i]=(maze[n-1][i]!=-1);
	}
	for(int i=n-2 ; i>=0 ; i--){
		for(int j=m-2 ; j>=0 ; j--){
			dp[i][j]=(dp[i][j+1]*(maze[i][j+1]!=-1))+(dp[i+1][j]*(maze[i+1][j]!=-1));
		}
	}
	// fon(i,n){
	// 	fon(j,m) cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	int ans=dp[0][0];
	fon(i,n) delete[] dp[i];
	delete[]dp;
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	int **maze;
	maze=new int*[n];
	fon(i,n)
	{
		maze[i]=new int[m];
		fon(j,m) cin>>maze[i][j];
	}
	cout<<countPaths(maze , n  , m);
	fon(i,n) delete []maze[i];
	delete []maze;
	return 0;
}