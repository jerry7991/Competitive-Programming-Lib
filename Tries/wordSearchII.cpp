#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Trie{
  public:
    unordered_map<char , Trie*> leaf;
    bool endOfWord;
    int wordIdx;
    int prefixCount;
    Trie(){
      endOfWord=false;
      wordIdx=0;
      prefixCount=0;
    }
};
void insert(Trie *root , string& word  , int index , int len=0){
  if(len==word.size()){
    //mark current root as end of word and assign the index value
    root->endOfWord=true;
    root->wordIdx=index;
    return;
  }
  root->prefixCount+=1;
  if(!root->leaf[word[len]]){
    //make a root value
    root->leaf[word[len]]=new Trie();
  }
  root=root->leaf[word[len]];
  root->prefixCount +=1;
  insert(root , word , index , len+1);
}
void buildTrie(vector<string>& words , Trie *root){
  for(int i=0 ; i<words.size() ;i++) insert(root , words[i] , i);
}

int dfs_tries(vector<string>&output , Trie *root , vector<vector<char>>& board ,vector<string>& words , int i , int j){
  //cout<<i<<" "<<j<<'\n';
  int detected=0;//how many word is detected till now
  if(root->endOfWord){
    //then we have a word which needs to find let's store that word
    output.push_back(words[root->wordIdx]);
    //and unmark the current root as not end of word
    root->endOfWord=false;
    //increase detected cause we found one word
    detected++;
  }
  //boundry condition
  if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
    return detected;
  }
  //shift root
  Trie *child=root->leaf[board[i][j]];
  //base case(invalid condition)
  if( board[i][j]=='*' || !child || child->prefixCount<=0 ){
    return detected;
  }
  char temp=board[i][j];
  board[i][j]='*';//mark as visited
  //explore all the path from i and j
  detected += dfs_tries(output , child , board , words , i+1 , j);
  detected += dfs_tries(output , child , board , words , i , j+1);
  detected += dfs_tries(output , child , board , words , i-1 , j);
  detected += dfs_tries(output , child , board , words , i , j-1);
  //while backtracking we are going to reduce detected with prefixCount
  root->prefixCount -= detected;
  //and reset the val what i changed for further use
  board[i][j]=temp;
  return detected;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  int row , col , wordLen=words.size();
  vector<string> output;
  //base case
  if( !(row=board.size()) || !(col=board[0].size()) || !wordLen){
    return output;
  }
  Trie *root=new Trie();
  //build the tree i.e. insert all words into the tries
  buildTrie(words , root);
  //do dfs
  //if no prefix count then we have not any element in words which is in board
  for(int i=0 ; i<row  && root->prefixCount; i++){
    for(int j=0 ; j<col ; j++){
      dfs_tries(output , root  , board , words , i ,j);
    }
  }
  return output;
}
int main(){
  int n ,m;cin>>n>>m;
  vector<vector<char>> matrix;
  vector<string> words;
  for(int i=0 ; i<n ; i++){
    vector<char> v;
    for(int j=0 ; j<n ; j++){
      char ch;cin>>ch;
      v.push_back(ch);
    }
    matrix.push_back(v);
  }
  for(int i=0 ; i<m; i++){
    string str;cin>>str;
    words.push_back(str);
  }
  vector<string> output=findWords(matrix , words);
  for(auto x: output) cout<<x<<endl;
  return 0;
}
/*
4 4
o a a n
e t a e
i h k r
i f l v
oath
pea
eat
rain



https://leetcode.com/explore/learn/card/trie/149/practical-application-ii/1056/discuss/802511/complete-process-to-do-with-comment-using-unordered_mapdfstries
*/