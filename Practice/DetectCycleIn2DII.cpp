#include<bits/stdc++.h>
using namespace std;
vector<int> dir={0,1,0,-1,0};
bool isCycle(vector<vector<char>>&grid ,vector<vector<bool>> &vis , int i , int j , int x,int y){
	vis[i][j]=true;
	for(int d=0;d<4;d++){
		int a=i+dir[d];
		int b=j+dir[d+1];
		if(a>=0 && a<grid.size() && b>=0 && b<grid[0].size() && grid[a][b]==grid[i][j] && !(a==x && b==y)){
			if(vis[a][b] || isCycle(grid , vis  , a,b,i,j)) 
				return true;
		}
	}
}
bool containsCycle(vector<vector<char>>& grid) {
  int m=grid.size() ,n=grid[0].size();
  vector<vector<bool>> vis(m,vector<bool>(n,false));
  bool found=false;
  for(int i=0;i<m;i++){
  	for(int j=0 ; j<n ; j++){
  		if(vis[i][j]) continue;
  		found |=isCycle(grid , vis , i,j,-1,-1);
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
		