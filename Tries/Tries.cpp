#include<bits/stdc++.h>
#define nullptr NULL
using namespace std;
class Tries
{
public:
	char ch;
	Tries ** node;
	bool endOfWord;
	Tries(char ch){
		node=new Tries*[27];
		for(int i=0 ; i<27 ; i++) node[i]=nullptr;
		endOfWord=false;
		this->ch=ch;
	}
};
class WordDictionary {
private:
	Tries *root;
public:
    WordDictionary() {
        root=new Tries('\0');
    }
    void addWord(string word) {
        add(word , root);
    }
    bool search(string word) {
 				return find(word ,root);       
    }
    void print(){
    	print(root );
    }
private:
	void add(string word , Tries *root){
		if(word.size()==0){
			root->endOfWord=true;
			return;
		}
		int index=word[0]-'a';
		if(root->node[index]!=nullptr){
			root=root->node[index];
		}else{
			root->node[index]=new Tries(word[0]);
			root=root->node[index];
		}
		add( word.substr(1) , root);
	}
	void print(Tries *root, string str=""){
		if(!root) return;
		str=str+root->ch;
		if(root->endOfWord){
			cout<<str<<'\n';
		}
		for(int i=0 ; i<27; i++){
			if(root->node[i])
				print( root->node[i] , str);
		}
	}
	 bool find(string word , Tries *root){
	 	if(!root || word.size()==0) return word.size()==0;
	 	bool found=false;
	 	if(word[0]!='.')
	 	{
	 		int index=word[0]-'a';
	 		if(root->node[index]==nullptr || word.size()==1) return root->node[index]!=nullptr;
	 		return find(word.substr(1) , root->node[index]);
	 	}else{
	 		for(int i=0 ; i<27 ; i++)
	 		{	
	 			if(root->node[i]!=nullptr){
		 			found |=find(word.substr(1) , root->node[i]);
		 			if(found) return found;
	 			}
	 		}
	 	}
	 	return found;
	 }
};
int main(){
	int query;
	cin>>query;
	WordDictionary *dictionay=new WordDictionary();
	while(query--){
		int choice;cin>>choice;
		if(choice==0){
			string str;
			cin>>str;
			dictionay->addWord(str);
		}else if(choice==1){
			string str;
			cin>>str;
			cout<<dictionay->search(str)<<'\n';
		}else{
			dictionay->print();
		}
	}
return 0;
}