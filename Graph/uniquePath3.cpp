#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> table;
int n,m;
inline bool isValidPath(){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++)
			if(table[i][j]==0) return false;
	}
	return true;
}
inline bool isValidDir(int row , int col){
	return (row<n && row>=0 && col<m && col>=0 && (table[row][col]==0 || table[row][col]==2));
}
int dfs(int row , int col){
	if(table[row][col]==2) return isValidPath();
	int x=table[row][col];
	table[row][col]=-1;
	int ans=0;
	if(isValidDir(row+1,col)){
		ans+=dfs(row+1,col);
	}
	if(isValidDir(row-1,col)){
		ans+=dfs(row-1 , col);
	}
	if(isValidDir(row , col+1)){
		ans+=dfs(row , col+1);
	}
	if(isValidDir(row , col-1)){
		ans+=dfs(row , col-1);
	}
	table[row][col]=x;
	return ans;
}
int uniquePathsIII(vector<vector<int>>& grid) {
    n=grid.size();
    m=grid[0].size();
    int row=-1,col=-1;
    table=grid;
    for(int i=0 ; i<n &&row==-1 ; i++){
    	for(int j=0 ; j<m && row==-1;j++){
    		if(grid[i][j]==1) row=i,col=j;
    	}
    }
    int ans=dfs(row , col);
    return ans;
}
int main(){
	cin>>n;
	cin>>m;
	vector<vector<int>> grid;
	for(int i=0 ; i<n ; i++){
		vector<int> v;
		for(int j=0 ; j<m; j++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		grid.push_back(v);
	}
	cout<<uniquePathsIII(grid);
}