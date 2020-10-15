#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
	map<char , trieNode*>children;
	map<char , int>nWords;
	bool endOfWord;
	trieNode()
	{
		endOfWord=false;
	}
};
void insertInTrie(trieNode * root , string str)
{
	if(str.length()==0)
	{
		//mark this reference as a end of word
		root->endOfWord=true;
		return;
	}

	trieNode *child;
	char ch=str[0];
	if(root->children.find(ch)==root->children.end())
	{
		//we have to create an edge
		child=new trieNode();
		(root->children)[ch]=child;
		(root->nWords)[ch]=1;//newly created
		//and go to next;
	}else{
		//we have already then use it don't waste space
		//just increment the number of word
		root->nWords[ch] =(root->nWords)[ch]+1;
	}
	//check weather current ch character is last of the string
	//now we have done the current root so go their child
	//and do same as we did
	insertInTrie((root->children)[ch] ,str.substr(1));
}
int query(trieNode * root ,string str)
{
	int wordCount;
	trieNode *currNode=root;
	char ch;
	for (unsigned int i = 0; i < str.length(); ++i)
	{
		 ch=str[i];
		if(currNode->children.find(ch)==currNode->children.end())
		{
			//bad prefix ,not yet inserted any string of such prefix
			return 0;
		}
			wordCount=(currNode->nWords[ch]);
			currNode = currNode->children[ch];
			//cout<<wordCount<<endl;
	}
	//if loop ended ,that's means a valide prefix are
	return wordCount;
}
void printTries(trieNode *root  , string str="")
{
	if (root->endOfWord)
	{
		cout<<str<<endl;
	}
	map<char , trieNode *>::iterator itr=root->children.begin();
	while(itr!=root->children.end())
	{
		str +=itr->first;cout<<(root->nWords[itr->first]);
		printTries(itr->second , str);
		itr++;
	}
}
int main()
{
	int n;
	cin>>n;
	trieNode * root=new trieNode();
	while(n--)
	{
		string opt,str;
		cin>>opt>>str;
		if(opt=="add")
			insertInTrie(root , str);
		else{
			cout<<query(root , str)<<endl;
		}
	}
	//printTries(root);
}