#include <iostream>
#include <unordered_map>
using namespace std;
class Tries{
public:
	int val;
	unordered_map<char , Tries *> node;
	Tries(){
		val=0;
	}
};
void insert(Tries *root , string &str  , int &val ,unsigned int index=0){
	if(index==str.size()){
		root->val=max(root->val , val);
		return;
	}
	if(! root->node[str[index]]){
		root->node[str[index]]=new Tries();
	}
	root->val=max(root->val , val);
	insert(root->node[str[index]] , str , val , index+1);
}
int getVal(Tries *root , string &str){
	for(unsigned int i=0; i<str.size();i++){
		if(! root->node[str[i]]){
			return -1;
		}
		root=root->node[str[i]];
	}
	return root->val;
}
int main(){
	int n,nQ;
	cin>>n>>nQ;
	Tries *root=new Tries();
	string str;int val;
	for(int i=0 ; i<n  ; i++){
		cin>>str>>val;
		insert(root , str , val);
	}
	while(nQ--){
		cin>>str;
		cout<<getVal(root, str)<<'\n';
	}
}