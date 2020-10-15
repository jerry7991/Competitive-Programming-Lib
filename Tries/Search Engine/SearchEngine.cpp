#include <iostream>
#include<string>
#define fon(i ,n) for(int i=0 ; i<n ; i++)
using namespace std;
class treiNode
{
public:
	treiNode ** children;//an array of treiNode cause character can vary from a-z
	int weight;
	treiNode()
	{
		//allocate the memory for each char
		children=new treiNode*[26];
		fon(i , 26)
		{
			children[i]=NULL;
		}
		weight=0;
	}
};
void insertInTries(treiNode * root , string str , int weight)
{
	if (str.empty())
	{
		return ;//nothing have to do
	}
	//we need to do
	treiNode *child;
	int index=str[0]-'a';
	if (root->children[index])
	{
		//if not null , that's means we have str[i] char in our tree
		child=root->children[index];//now go deeper
	}else{
		//we need to create a new child for our str[i]
		root->children[index]=new treiNode();
		child=root->children[index];//go deeper
	}
	//update weight also
	root->weight = ((root->weight)<weight)? weight : (root->weight);
	//now we are done with current 0'th character of string and rood
	// now traverse to child of root for rest of string's character
	insertInTries(child , str.substr(1) , weight);
}
int getAnswer(treiNode * root ,string prefix)
{
	treiNode * currNode=root;
	int  bestWeight=-1;
	fon(i , prefix.length())
	{
		//check weather current node has present the prefix current character
		int index = prefix[i]-'a';
        treiNode *child=currNode->children[index];
		if (child)
		{
			//store bestWeight till now
			bestWeight =child->weight;
			//and move to child of current node
			currNode=child;
		}else{
			//otherwise prefix is not in tries
			return -1;
		}
	}
    if(bestWeight==0)//that's means we got all the prefix string as a whole string so prefix can not be string
        return -1;
	return bestWeight;
}
void deleteTreiNode(treiNode * root)
{
	if(root)
	{
		fon(i,26)
		{
			deleteTreiNode(root->children[i]);
			delete  root->children[i];
			delete root;
		}
	}
}
int main()
{
	int n , nQuery;
	cin>>n>>nQuery;
	treiNode *root=new treiNode();
	while(n--)
	{
		string str;
		int weight;
		cin>>str>>weight;
		insertInTries(root,str , weight);
	}
	//get queries
	while(nQuery--)
	{
		string prefix;
		cin>>prefix;
		cout<<getAnswer(root , prefix)<<endl;
	}
	deleteTreiNode(root);
}