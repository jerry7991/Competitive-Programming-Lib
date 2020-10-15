#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];
int maxConnected1(char cake[NMAX][NMAX] , bool **visited , int i , int j , int n){
	int ans=0;
	visited[i][j]=true;
	if(i+1<n && !visited[i+1][j] && (cake[i+1][j]-'0')){
		ans+=	maxConnected1(cake , visited , i+1 , j ,n);
	}
	if(i>0 && !visited[i-1][j] && (cake[i-1][j]-'0')){
		ans+=	maxConnected1(cake  , visited , i-1 , j ,n);
	}
	if(j+1<n && !visited[i][j+1] && (cake[i][j+1]-'0')){
		ans+=	maxConnected1(cake , visited , i , j+1, n);
	}
	if(j>0 && !visited[i][j-1] && (cake[i][j-1]-'0')){
		ans+=	maxConnected1(cake , visited , i , j-1,n);
	}
	return 1+ans;//1 for current 1'ones
}
int solve(int n,char cake[NMAX][NMAX])
{
	bool **visited=new bool*[n];
	for(int i=0 ; i<n ; i++){
		visited[i]=new bool[n];
		for(int j=0 ; j<n ; j++){
			visited[i][j]=false;
		}
	}
	int ans=0;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n;j++){
			if(visited[i][j] || !(cake[i][j]-'0')) continue;
			ans=max(ans , maxConnected1(cake , visited , i , j , n));
		}
	}
	return ans;
}
int solve1(int n , char cake[NMAX][NMAX]){
	int **dp=new int*[n+1];
	for(int i=0 ; i<=n ; i++) dp[i]=new int[n+1];
	//base case
	for(int i=0 ; i<=n ; i++){
		dp[n][i]=dp[i][n]=0;
	}
	for(int i=n-1 ; i>=0 ; i--){
		for(int j=n-1 ; j>=0 ; j--){
			if(cake[i][j]-'0'){
				dp[i][j]=max(dp[i+1][j] , dp[i][j+1])+1;
			}else{
				dp[i][j]=0;
			}
		}
	}
	for(int i=0 ; i<=n ; i++){
		for(int j=0 ; j<=n ; j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve1(n,cake)<<endl;
}