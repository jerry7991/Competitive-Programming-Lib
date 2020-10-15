#include<bits/stdc++.h>
using namespace std;
class Tries{
  public:
  char ch;
  int level;
  Tries **node;
  bool endOfWord;
  Tries(char ch , int level){
    this->ch=ch;//no need of ch but for debugging it will helps 
    this->level=level;
    endOfWord=false;//weather node is a complete word or not
    node=new Tries*[26];
    for(int  i=0 ; i<26 ; i++) node[i]=NULL;
  }
};
class MapSum {
  private:
  Tries *root;
public:
    MapSum() {
        root=new Tries('\0' , 0);
    }
    
    void insert(string key, int val) {
       bool ans=insertHelper(key , val ,root);
    }
    
    int sum(string prefix) {
        return sumHelper(prefix , root);
    }
    //implementation helper fuction
    private:
    int sumHelper(string & prefix  , Tries *root , int index=0){
      if(index==prefix.size()){
        return root->level;//return the level of current root
      }
      int currIndex=prefix[index]-'a';
      if(root->node[currIndex]){
        return sumHelper(prefix , root->node[currIndex] , index+1);
      }
      //else no tries has nothing which start with given prefix
      return 0;
    }
    bool insertHelper(string& key , int& val , Tries *root ,int index=0){
      if(key.size()==index){
        bool ans=root->endOfWord;//copy is this end of word or not
        root->endOfWord=true;//make this is as end of word because key is going to end here
        return ans;//return weather key allready has in tries or not
      }
      int currIndex=key[index]-'a';
      if(!root->node[currIndex]){
        root->node[currIndex]=new Tries(key[index] ,0);
      }
      root=root->node[currIndex];
      bool isWord=false;
      isWord=insertHelper(key , val , root , index+1);
      //while backtracking check
      if(isWord){
        //if key has allready in tries then just initialise with new val
        root->level=val;
      }else{
        //other wise whatever value has it
        root->level+=val;
      }
      return isWord;
    }
};
int main(){
  MapSum *mp=new MapSum();
  int q;
  cin>>q;
  while(q--){
    int choice;cin>>choice;
    if(choice==1){
      //insert
      string str;int val;cin>>str>>val;
      mp->insert(str , val);
    }else{
      //fors sum
      string str;
      cin>>str;
      cout<<mp->sum(str)<<endl;
    }
  }
  return 0;
}