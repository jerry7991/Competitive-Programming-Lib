#include <iostream>
using namespace std;
int uniquePaths(int m, int n ,int currM=0 , int currN=0) {
    if(currN>=n || currM>=m) return 0;
    if(currM==m-1 && currN==n-1) return 1;
    int rightMove=uniquePaths(m , n , currM+1 , currN);
    int downMove=uniquePaths(m , n , currM , currN+1);
    return (rightMove+downMove);
}
int uniquePathsOptimise(int m , int n){
	int **dp=new int*[m];
	for(int i=0 ; i<m ; i++) dp[i]=new int[n];
	for(int i=0 ; i<n ; i++) dp[m-1][i]=1;
	for(int i=0 ; i<m ; i++) dp[i][n-1]=1;
	for(int i=m-2 ; i>=0 ; i--){
		for(int j=n-2 ; j>=0 ; j--){
			dp[i][j]=dp[i+1][j]+dp[i][j+1];
		}
	}
	int ans=dp[0][0];
	return ans;
}
int uniquePathsOptimise2(int m , int n){
	if(m==1 || n==1) return 1;
	int **dp=new int*[2];
	dp[0]=new int[n];
	dp[1]=new int[n];
	for(int i=0 ; i<n ; i++) dp[0][i]=1;
	dp[1][0]=1;
	int flag=1;
	for(int i=1; i<m ; i++){
		for(int j=1; j<n;j++){
			dp[flag][j]=dp[flag^1][j]+dp[flag][j-1];
		}
		flag^=1;
	}
	int ans=dp[flag^1][n-1];
	return ans;
}
int main(){
	int n,m;
	cin>>m>>n;
	cout<<uniquePathsOptimise2(m , n);
	return 0;
}