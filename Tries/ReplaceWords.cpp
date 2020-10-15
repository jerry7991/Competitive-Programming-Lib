#include<bits/stdc++.h>
using namespace std;
class Tries{
public:
  char ch;
  bool endOfWord;
  Tries **node;
  Tries(char ch){
    this->ch=ch;
    endOfWord=false;
    node=new Tries*[26];
    for(int i=0 ; i<26 ; i++) node[i]=NULL;
  }
};
class Solution{
private:
  Tries *root;
public:
  Solution(){
    root=new Tries('\0');
  }
public:
 string replaceWords(vector<string>& dictionary, string& sentence) {
   for(auto x: dictionary){
     insert(x , root);
   }
   //get the word
   vector<string> word;
   int i=0;
   while(i<sentence.size()){
     string temp;
     while(i<sentence.size()  && sentence[i]!=' '){
       temp+=sentence[i];
       i++;
     }
     i++;
     word.push_back(temp);
   }
   string output;
   for(int i=0  ; i<word.size() ; i++){
     int index=word[i][0]-'a';
     if(root->node[index]==NULL){
       output+=word[i];
     }else{
       string temp="";
      bool isValid=getString(word[i] , root , temp);
       if(isValid)
         output+=temp;
       else
         output+=word[i];
     }
     if(i!=word.size()-1){
       output+=" ";
     }
   }
   return output;
 }
private:
  void insert(string& str , Tries *root , int len=0){
    if(len==str.size()){
      root->endOfWord=true;
      return;
    }
    int index=str[len]-'a'; 
    if(!root->node[index]){
      root->node[index]=new Tries(str[len]);
    }
    root=root->node[index];
    insert(str , root  , len+1);
  }
  bool getString(string & str, Tries *root , string& output, int len=0){
    if(len==str.size() || root->endOfWord){
      return root->endOfWord;
    }
    int index=str[len]-'a';
    if(root->node[index]){
      output=output+str[len];
      return getString(str , root->node[index] , output , len+1);
    }
    return false;
  }
};
int main(){
  int n;cin>>n;
  vector<string> v;
  string sentence;
  for(int i=0 ; i<n ; i++){
    string str;
    cin>>str;
    v.push_back(str);
  }
  getline(cin , sentence);
  Solution *sl=new Solution();
  cout<<sl->replaceWords(v , sentence)<<endl;
return 0;
}