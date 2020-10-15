#include<bits/stdc++.h>
using namespace std;
void dfs( vector<vector<char>>&grid , int i  ,int j){
	grid[i][j]='0';
	if(i>0 && !visited[i-1][j] && grid[i-1][j]=='1'){
		dfs( grid , i-1 , j);
	}
	if(j>0 && !visited[i][j-1] && grid[i][j-1]=='1'){
		dfs( grid , i , j-1);
	}
	if(i+1<grid.size() && !visited[i+1][j] && grid[i+1][j]=='1'){
		dfs( grid , i+1 ,j);
	}
	if(j+1<grid[i].size() && !visited[i][j+1] && grid[i][j+1]=='1'){
		dfs( grid , i,j+1);
	}
}
int numIslands(vector<vector<char>>& grid) {
 int n=grid.size();
 int m=grid[0].size();
int count=0;
for(int i=0 ; i<n ; i++){
	for(int j=0 ; j<m ; j++){
		if( grid[i][j]=='0') continue;
		count++;
		dfs(grid , i , j);
	}
}
return count;
}
int main(){
	int row;
	cin>>row;
	vector<vector<char>> grid;
	for(int i=0 ; i<row ; i++){
		vector<char> v;
		string str;
		cin>>str;
		for(int j=0 ; j<str.size() ; j++) v.push_back(str[j]);
		grid.push_back(v);
	}
	cout<<numIslands(grid);
	return 0;
}