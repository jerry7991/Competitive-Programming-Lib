#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Tries{
public:
	bool eOF;
	char ch;
	bool isCompressed;
	unordered_map<char, Tries*> node;
	Tries(char ch='\0'){
		isCompressed=eOF=false;
		this->ch=ch;
	}
};
Tries *root;
void insert(Tries *root , string &words , int len=0){
	if(words.size()==len){
		if(root->node.size()==0)
			root->eOF=true;
		return;
	}
	if(root->eOF){
		root->eOF=false;
		root->isCompressed=true;
	}
	if(root->node[words[len]]==0) root->node[words[len]]=new Tries(words[len]);
	Tries *child=root->node[words[len]];
	child->isCompressed=root->isCompressed;
	insert(root->node[words[len]] ,words , len+1);
}
void getConcatenat(Tries *root , vector<string> &output , string &str){
	if(root->isCompressed){
			output.push_back(str);
		return;
	}
	for(auto x: root->node){
		str.push_back(x.first);
		getConcatenat(x.second , output , str);
		str.pop_back();
	}
}
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
	root=new Tries();
	for(auto x: words){
		insert(root , x);
	}
	vector<string> output;	
	string curr;
	getConcatenat(root , output , curr);
	return output;
}
int main(){
	int n;cin>>n;
	vector<string> v;
	for(int i=0 ;i<n ;i++){
		string str;
		cin>>str;
		v.push_back(str);
	}
	v=findAllConcatenatedWordsInADict(v);
	for(auto x:v) cout<<x<<'\n';
	return 0;	
}