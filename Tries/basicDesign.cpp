#include<bits/stdc++.h>
using namespace std;
class Tries{
public:
	char data;
	Tries **node;
	bool endOfWord;
	Tries(char data){
		this->data=data;
		endOfWord=false;
		node=new Tries*[26];
		for (int i = 0; i < 26; ++i)
		{
			node[i]=NULL;
		}
	}
	// ~Tries(){
	// 	delete []Tries;
	// }
};
void insert(Tries *root ,string &str , int index=0){
	//base case
	if(index==str.size()){
		root->endOfWord=true;
		return;
	}
	int childIndex=str[index]-'a';
	if(! root->node[childIndex]){
		Tries *child=new Tries(str[index]);
		root->node[childIndex]=child;
	}
	// if(index==str.size()-1){
	// 	root->endOfWord=true;
	// }
	insert(root->node[childIndex] , str , index+1);
}
void  print(Tries *root , string output=""){
	if(root->endOfWord){
		cout<<output<<'\n';
	}
	for(int i=0 ; i<26 ; i++){
	 if(root->node[i]){
	 	output.push_back(root->node[i]->data);
		print(root->node[i] , output);
	  }
	}
}
// void release(Tries  *root){
// 	if(!root) return;
// 	for(int i=0 ; i<26 ; i++)
// 	{
// 		release(root->node[i]);
// 	}
// 	delete []root;
// }
int main(){
	Tries *root=new Tries('\0');
	while(true){
		char ch;
		cin>>ch;
		if(ch=='i'){
			string str;
			cin>>str;
			insert(root , str);
		}else if(ch=='r'){
			release(root);
		}
		else{
			print(root);
		}
	}
 return 0;
}
		