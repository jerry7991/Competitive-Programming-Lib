#include <bits/stdc++.h>
using namespace std;
class Tries{
public:
	unordered_map<char , Tries*> node;
	bool endOfWord;
	char ch;
	Tries(char ch='\0'){
		endOfWord=false;
		this->ch=ch;
	}
};
class StreamChecker {
private:
	Tries *root=new Tries();
	string word;
	void insert(string &str , Tries*root ,unsigned int len=0){
		if(len==str.size()){
			root->endOfWord=true;
			return;
		}
		if(!root->node[str[len]]){
			root->node[str[len]]=new Tries(str[len]);
		}
		root=root->node[str[len]];
		insert(str , root , len+1);
	}
	bool getQuery(){
		Tries *temp=root;
		for(int i=word.size()-1 ; i>=0 ; i--){
			if(temp->node[word[i]]){
				temp=temp->node[word[i]];
				if(temp->endOfWord) return true;
			}else{
				return false;
			}
		}
		return false;
	}
public:
    StreamChecker(vector<string>& words) {
        for(auto x:words){
        	reverse(x.begin(), x.end());
        	insert(x , root);
        }
    }
    
    bool query(char letter) {
        word.push_back(letter);
        return getQuery();
    }
};
int main(){
	int n;
	cin>>n;
	vector<string> st;
	for(int i=0 ; i<n ; i++){
		string str;
		cin>>str;
		st.push_back(str);
	}
	StreamChecker *stream=new StreamChecker(st);
	while(true){
		char ch;
		cin>>ch;
		if(ch=='1') return 0;
		cout<<stream->query(ch)<<'\n';
	}
	return 0;
}