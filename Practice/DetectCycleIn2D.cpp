#include <iostream>
#include <vector>
using namespace std;
int x[]={0,0,-1,1};
int y[]={1,-1,0,0};
inline bool isValid(int i,int j,int m,int n,vector<vector<char>> &grid,char ch){
	return (i>=0 && i<m && j>=0 && j<n && grid[i][j]==ch);
}
bool isCycle(vector<vector<char>>&grid , vector<vector<bool>> &vis ,int i,int j,int m,int n,int si,int sj,int len=0){
cout<<len<<' '<<i<<' '<<j<<endl;
	vis[i][j]=true;
	bool found=false;
	if(i+1<m && grid[i+1][j]==grid[si][sj]){
	if(vis[i+1][j]){
		return len>=3 && (i+1==si && j==sj);
	}
		found=isCycle(grid , vis , i+1 , j , m , n , si,sj , len+1);
		if(found) return found;
	}
	if(i-1>=0 && grid[i-1][j]==grid[si][sj]){
	if(vis[i-1][j]){
		return len>=3 && (i-1==si && j==sj);
	}
		found=isCycle(grid , vis , i-1 , j , m , n , si,sj , len+1);
		if(found) return found;	
	}
	if(j+1<n && grid[i][j+1]==grid[si][sj]){
	if(vis[i][j+1]){
		return len>=3 && (i==si && j+1==sj);
	}
		found=isCycle(grid , vis , i , j+1 , m , n , si,sj , len+1);
		if(found) return found;
	}
	if(j-1>=0 && grid[i][j-1]==grid[si][sj]){
	if(vis[i][j-1]){
		return len>=3 && (i==si && j-1==sj);
	}
		found=isCycle(grid , vis , i , j-1 , m , n , si,sj , len+1);
		if(found) return found;
	}
	return vis[i][j]=found;
}
bool containsCycle(vector<vector<char>>& grid) {
  int m=grid.size() ,n=grid[0].size();
  vector<vector<bool>> vis(m,vector<bool>(n,false));
  bool found=false;
  for(int i=0;i<m;i++){
  	for(int j=0 ; j<n ; j++){
  		if(vis[i][j]) continue;
  		found |=isCycle(grid , vis , i,j,m,n,i,j);
  		if(found) return found;
  	}
  }
  return found;
}
int main(){
	while(true){
		int n,m;
		cin>>n>>m;
		vector<vector<char>> grid(n , vector<char>(m));
		for(int i=0 ;i<n;i++){
			for(int j=0 ; j<m ; j++)cin>>grid[i][j];
		}
	cout<<containsCycle(grid)<<'\n';
	}
}