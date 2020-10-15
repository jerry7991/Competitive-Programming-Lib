#include <iostream>
#include <string>
#include <vector>
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define pb(n) push_back(n)
using namespace std;
class trieNode
{
public:
	trieNode **children;
	bool isTerminal;
	trieNode()
	{
		children=new trieNode*[26];
		fon(i , 26)
		 children[i]=NULL;
		 isTerminal=false;
	}
};
void insertInTries(trieNode *root ,string str )
{
	//if str is empty ,we don't have to do
	if (str.empty())
	{
		return;
	}
	//get the current char
	int index=str[0]-'a';
	trieNode *child;
	//if index value of this character is empty in root that's means it not had
	if (root->children[index])
	{
		child = root->children[index];
	}else{
		//create space for current
		root->children[index]=new trieNode();
		child=root->children[index];
	}
	if(str.size()==1)
	{
		//mark as this is end of word
		child->isTerminal=true;
	}
	//now insert in same way to rest of string
	insertInTries(child , str.substr(1));
}
void printSuggest(trieNode *root ,string suggest)
{
	if(root->isTerminal)
	{
			cout<<suggest<<endl;
	}
	if(!root)
		return;
	fon(i , 26)
	{
		if(root->children[i])
		{
			char ch=((char)(i+97));
			printSuggest(root->children[i] ,suggest+ch);
		}
	}
}
void getsuggestions(trieNode * root ,string prefix)
{
	string nSuggest="No suggestions";
	string suggest="";
	trieNode *currentNode=root;
	fon(i , prefix.length())
	{
		int index=prefix[i]-'a';
		if(currentNode->children[index])
		{
			//is not equal to null ,search rest of prefix in rest of trie
			currentNode=currentNode->children[index];
			//and store the prefix char in suggest
			suggest +=prefix[i];
		}else{
			cout<<nSuggest<<endl;
			//insert this new prefix in tries
			insertInTries(root , prefix);
			return;
		}
	}
	printSuggest(currentNode , suggest);
}
void printTries(trieNode *root)
{
	if (!root)
	{
		cout<<endl;return;
	}
	fon(i , 26)
	{
		if (root->children[i])
		{
			cout<<(char)(i+97);
			printTries(root->children[i]);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	trieNode *root=new trieNode();
	while(n--)
	{
		string str;
		cin>>str;
		insertInTries(root , str);
	}
	//printTries(root);
	int nQuery;
	cin>>nQuery;
	while(nQuery--)
	{
		string prefix;
		cin>>prefix;
		getsuggestions(root , prefix);
	}
}