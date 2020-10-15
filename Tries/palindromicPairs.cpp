#include<bits/stdc++.h>
using namespace std;
class Tries{
public:
	unordered_map<char , Tries*> node;
	bool endOfWord;
	int index;
	Tries(){
		endOfWord=false;
		index=-1;
	}
};
class Solution{
private:
	Tries *root;
public:
	Solution(){
		root=new Tries();
	}
	vector<vector<int>> palindromePairs(vector<string>& words) {
		for(int i=0 ; i<words.size();i++){
			insert(words[i] , root , i);
		}
		vector<vector<int>> output;
		for(int i=0; i<words.size() ;i++){
			vector<int> curr;
			getAnswer(words[i] , root   , words[i].size() , curr);
			getAnswer(words[i] , root , words[i].size()-1 , curr);
			for(auto x:curr){
				if(x==-1 || x==i)continue;
			if(isPalindrom(words[i]+words[x]))
				output.push_back({i,x});
			else
				output.push_back({x,i});
			}
		}
		return output;
	}

	//operations........
private:
	bool isPalindrom(string str){
		if(str.size()==1 || str.size()==0) return true;
		int left=0,right=str.size()-1;
		while(left<right){
			if(str[left]!=str[right]) return false;
			left++;right--;
		}
		return true;
	}
	void insert(string& str , Tries *root , int& index , unsigned int len=0){
		if(len==str.size()){
			root->endOfWord=true;
			root->index=index;
			return;
		}
		if(!root->node[str[len]]){
			root->node[str[len]]=new Tries();
		}
		root=root->node[str[len]];
		insert(str , root , index , len+1);
	}
	void getAnswer(string &str , Tries *root , int len , vector<int> &curr){
		if(len==0){
			if(root->endOfWord){
				curr.push_back(root->index);
			}
			return;
		}
		if(root->endOfWord){
			curr.push_back(root->index);
		}
		if(root->node[str[len-1]]){
		 getAnswer(str , root->node[str[len-1]] , len-1 , curr);
		}
	}
};
int main(){
	int n;cin>>n;
	vector<string> st;
	for(int i=0 ; i<n ; i++){
		string str;cin>>str;
		st.push_back(str);
	}
	Solution *sol=new Solution();
	vector<vector<int>> output=sol->palindromePairs(st);
	for(int i=0  ; i<output.size() ; i++){
		for(int j=0 ; j<output[i].size() ; j++) cout<<output[i][j]<<' ';
	cout<<'\n';
	}
	return 0;
}