#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
	if(grid.size()==0 || grid[0].size()==0) return 0;
	unordered_map<string,int> minutes;
	queue<pair<int,int>> pending;
	int i,j,maxMin=0 , found=0;
	for( i=0 ; i<grid.size() ; i++){
		for( j=0 ;j<grid[i].size() ; j++){
			if(grid[i][j]==2){
				pending.push(make_pair(i,j));
        string str=to_string(i)+to_string(j);
      	minutes[str]=0;
			}
      if(grid[i][j]==1) found++;
		}
	}
  if(pending.size()==0) return (found==0)?0:-1;
      string str;
	while(pending.size()){
		pair<int,int> curr=pending.front();
		pending.pop();
		i=curr.first;
		j=curr.second;
		grid[i][j]=2;
		str=to_string(i)+to_string(j);
		if(i+1<grid.size() && grid[i+1][j]==1){
			pending.push(make_pair(i+1 , j));
      grid[i+1][j]=2;
      found--;
			string st=to_string(i+1)+to_string(j);
			maxMin=max(minutes[st]=minutes[str]+1 , maxMin);
		}
		if(i-1>=0 && grid[i-1][j]==1){
			pending.push(make_pair(i-1 , j));
			string st=to_string(i-1)+to_string(j);
			minutes[st]=minutes[str]+1;
      grid[i-1][j]=2;
      found--;
			maxMin=max(minutes[st]=minutes[str]+1 , maxMin);
		}
		if(j+1<grid[i].size() && grid[i][j+1]==1){
			pending.push(make_pair(i , j+1));
			string st=to_string(i)+to_string(j+1);
			minutes[st]=minutes[str]+1;
      grid[i][j+1]=2;
      found--;
			maxMin=max(minutes[st]=minutes[str]+1 , maxMin);
		}
		if(j-1>=0 && grid[i][j-1]==1){
			pending.push(make_pair(i , j-1));
			string st=to_string(i)+to_string(j-1);
			minutes[st]=minutes[str]+1;
      grid[i][j-1]=2;
      found--;
			maxMin=max(minutes[st]=minutes[str]+1 , maxMin);
		}
	}
      return (found==0)?maxMin:-1;
}
int main(){
	vector<vector<int>> grid;
	int n,m;
	cin>>n>>m;
	for(int i=0 ; i<n;i++){
		vector<int> v;
		for(int j=0  ; j<m ; j++){
			int x;cin>>x;
			v.push_back(x);
		}
		grid.push_back(v);
	}
	cout<<orangesRotting(grid)<<'\n';
}