#include<bits/stdc++.h>
using namespace std;
  class Treis{
public:
	unordered_map<char , Treis*> child;
};
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
void insertTreis(Treis* root , string str){
	if(str.size()==0) return;
	Treis *children;
	char ch=str[0];
	if((root->child).find(ch)==(root->child).end()){
		children=new Treis();
		(root->child)[ch]=children;
	}
	insertTreis((root->child)[ch] ,str.substr(1));
}
int getEqPref(Treis *root , string str){
	Treis *temp=root;
	int n=0;
	while(temp && n<str.size()){
		if((temp->child).find(str[n])==(temp->child).end()) break;
		n++;
		temp=(temp->child)[str[n]];
	}
	return n;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
	vector<string> output;
	Treis *root=new Treis();
	for(int i=0 ; i<words.size() ; i++){
		int x=getEqPref(root , words[i]);
		bool ans=exist(board , words[i].substr(x));
		if(ans){
			output.push_back(words[i]);
			insertTreis(root ,words[i]);
		}
	}
	return output;
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
	vector<string> v;
	int x;
	cin>>x;
	while(x--){
		string str;
		cin>>str;
		v.push_back(v);
	}
	vector<string> output=findWords(board , words);
	for(int i=0 ; i<output.size() ; i++) cout<<output[i]<<'\n';
	return 0;
}