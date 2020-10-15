#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	char data;
	bool endOfWord;
	unordered_map<char , Node*> child;
	Node(char data){
		this->data=data;
		endOfWord=false;
	}
};
class Tries
{
private:
	Node *root;
public:
	Tries(){
		root=new Node('\0');
	}
	void insert(string str){
		insertHelper(root , str);
	}
	void print(){
		printHelper(root);
	}
	bool search(string &str){
		return searchHelper(root ,str);
	}
private:
	bool searchHelper(Node *root , string &str , int index=0){
		if(index==str.size()) return root->endOfWord;
		bool found=false;
		if(root->child[str[index]]){
			found |= searchHelper(root->child[str[index]], str , index+1);
		}
		return found;
	}
	void printHelper(Node *root , string output=""){
		if(root->endOfWord){
			cout<<output<<'\n';
		}
		unordered_map<char , Node*>:: iterator itr;
		unordered_map<char , Node*> child=root->child;
		for(itr=child.begin() ; itr!=child.end() ; itr++){
			output.push_back((itr->second)->data);
			if((*itr).second)
				printHelper((*itr).second , output);
			output.pop_back();
		}
	}
	void insertHelper(Node *root , string &str ,unsigned int index=0){
		//base case
		if(index==str.size()){
			root->endOfWord=true;
			return;
		}
		Node *child;
		child=root->child[str[index]];
		if(child==NULL){
			child=new Node(str[index]);
			root->child[str[index]]=child;
		}
		insertHelper(child , str , index+1);
	}
};