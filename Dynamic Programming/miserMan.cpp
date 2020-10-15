#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int grid[100][100];
int n,m;
int solve(int curr_i , int curr_j)
{
	int ans,opt1=100000,opt2=100000,opt3=100000;
	if(curr_i==n)	return 0;
	if(curr_j<m && curr_i<n)
		opt1=grid[curr_i][curr_j]+solve(curr_i+1 ,curr_j);
	if(curr_j>0 && curr_i<n)
		opt2=grid[curr_i][curr_j]+solve(curr_i+1 ,curr_j-1);
	if(curr_j<m-1 && curr_i<n)
		opt3=grid[curr_i][curr_j]+solve(curr_i+1 ,curr_j+1);
	ans=min(opt1,min(opt2,opt3));
	return ans;
}
int main()
{
	cin>>n>>m;
	fon(i,n)
	 fon(j,m)	cin>>grid[i][j];
	 int ans=INT_MAX;
	 fon(i,m)
		ans=min(ans,solve(0 , i));
	cout<<ans;
}