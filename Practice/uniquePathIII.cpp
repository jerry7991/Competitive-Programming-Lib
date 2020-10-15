#include<bits/stdc++.h>
using namespace std;
int uniquePathsIII(vector<vector<int>>& grid , int i , int j , int zCount) {
	if(grid[i][j]==2) return zCount<0;//because we have substracted one time for grid[i][j]==1
	int ans=0;
	int x=grid[i][j];
	zCount--;
	grid[i][j]=-1;
	int n=grid.size(),m=grid[i].size();
	if(j+1<m && grid[i][j+1]!=-1){
		ans+=uniquePathsIII(grid , i ,j+1 , zCount);
	}
	if(i+1<n && grid[i+1][j]!=-1){
		ans+=uniquePathsIII(grid , i+1, j , zCount);
	}
	if(i>=1 && grid[i-1][j]!=-1){
		ans+=uniquePathsIII(grid , i-1 ,j , zCount);
	}
	if(j>=1 && grid[i][j-1]!=-1){
		ans+=uniquePathsIII(grid , i , j-1 , zCount);
	}
	//for other use
	grid[i][j]=x;
	return ans;
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> path(n,vector<int>(m));
	int si,sj , zCount=0;
	for(int i=0;i<n;i++){
		for(int j=0 ; j<m ; j++){
		 cin>>path[i][j];
		 zCount+=(path[i][j]==0);
		 if(path[i][j]==1){
		 	si=i;sj=j;
		 }
		}
	}
	cout<<uniquePathsIII(path , si , sj , zCount)<<'\n';
}
int main(){
	while(true){
		solve();
	}
 return 0;
}
		