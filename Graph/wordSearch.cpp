#include<bits/stdc++.h>
using namespace std;
bool exploreAllPossible(vector<vector<char>> & board , bool **visited , string word  ,unsigned int i,unsigned int j,unsigned int strLen){
	if(strLen==word.size()) return true;
	bool ans=false;
	visited[i][j]=true;
	char nextChar=word[strLen];
	if(i>0 && !visited[i-1][j] && board[i-1][j]==nextChar){
		ans |=exploreAllPossible(board , visited , word , i-1,j,strLen+1);
		if(ans) return ans;
	}
	if(i<board.size()-1 && !visited[i+1][j] && board[i+1][j]==nextChar){
		ans|=exploreAllPossible(board , visited ,word , i+1 , j , strLen+1);
		if(ans)return ans;
	}
	if(j>0 && !visited[i][j-1] && board[i][j-1]==nextChar){
		ans |= exploreAllPossible(board , visited ,word ,i,j-1 ,strLen+1);
		if(ans) return ans;
	}
	if(j<board[i].size()-1 && !visited[i][j+1] && board[i][j+1]==nextChar){
		ans|=exploreAllPossible(board , visited , word , i , j+1 ,strLen+1);
		if(ans) return ans;
	}
	visited[i][j]=false;
	return ans;
}
bool exist(vector<vector<char>>& board, string word) {
   bool **visited=new bool*[board.size()];
   for(unsigned int i=0 ; i<board.size() ; i++){
   	visited[i]=new bool[board[i].size()];
   	for(unsigned int j=0  ; j<board[i].size() ; j++) visited[i][j]=false;
   }
	bool ans=false;
	for(unsigned int i=0 ; i<board.size() && !ans ; i++){
		for(unsigned int j=0 ; j<board[i].size() && !ans ;j++){
			if(board[i][j]==word[0]){
				ans=exploreAllPossible(board , visited , word , i,j,1);
				if(ans) return ans;
			}
		}
	}
	return ans;
}
int main()
{
	vector<vector<char>> board;
	int n;
	cin>>n;
	while(n--){
		string str;
		cin>>str;
		vector<char>v;
		for(unsigned int i=0  ; i<str.size();i++) v.push_back(str[i]);
		board.push_back(v);
	}
	string str;
	cin>>str;
	if(exist(board , str)) cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';
	return 0;
}