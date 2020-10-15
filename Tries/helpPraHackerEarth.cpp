#include <iostream>
#include<unordered_map>

using namespace std;
class Tries{
public:
	unordered_map<char , Tries*> node;
	// for maintaining order
	//map<char , Tries*> node;
	char ch;
	bool eOF;
	Tries(char ch='\0'){
		this->ch=ch;
		eOF=false;
	}
};
void insert(Tries *root , string &str , int len=0){
	if(len==str.size()){
		root->eOF=true;
		return;
	}
	if( ! root->node[str[len]]){
		root->node[str[len]]=new Tries(str[len]);
	}
	root=root->node[str[len]];
	insert(root , str , len+1);
}
void printAllSuggesation(Tries *root , string &str){
	if(root->eOF){
		cout<<str<<'\n';
	}
	for(auto x:root->node){
		str.push_back(x.first);
		printAllSuggesation(x.second , str);
	}
}
void printSuggesation(Tries *root , string &str){
	Tries *temp=root;
	for(int i=0;i<str.size();i++){
		if(temp->node[str[i]]==0){
			cout<<"No suggestions"<<'\n';
			insert(root  ,str);
			return;
		}
		temp=temp->node[str[i]];
	}
	printAllSuggesation(temp , str);
}
int main(){
	Tries *root=new Tries();
	int n;cin>>n;
	string str;
	while(n--){
		cin>>str;
		insert(root, str);
	}
	//number of query
	cout<<""<<'\n';
	cin>>n;
	while(n--){
		cin>>str;
		printSuggesation(root  ,str);
	}
}