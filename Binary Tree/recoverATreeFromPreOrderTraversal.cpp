#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* recoverFromPreorder(string str) {
	TreeNode *root=new TreeNode();
	if(str.size()==0) return root=nullptr;//an empty tree
	stack<pair<TreeNode * , int>> pending;
	//first element of pair is for the storing the node and secod pair is for the storing the depth of that node
	int index=0,nodeVal=0;
	//find the node val for tree
	while(index<str.size() && str[index]!='-') nodeVal=nodeVal*10+str[index++]-'0';
	root=new TreeNode(nodeVal);
	pending.push(make_pair(root , 0));
	while(pending.size() && index<str.size()){
		int depth=0;
		while(index<str.size() && str[index]=='-') index++ , depth++;	//find the depth of next node
		nodeVal=0;
		while(index<str.size() && str[index]!='-') nodeVal=nodeVal*10+str[index++]-'0';
	//if(index>=str.size()) break;
	TreeNode * currNode=new TreeNode(nodeVal);
	//LET'S find get the parent what i have inserted earlier
		pair<TreeNode* , int> parent=pending.top();
		//if the difference between parent and current node is 1 then make curr node as left child of parent
		//because question has given that If a node has only one child, that child is guaranteed to be the left child.
		if((depth-parent.second)==1){
			//make curr node as a left child of the parent
			(parent.first)->left=currNode;
			pending.push(make_pair(currNode , depth));
		}else{
			//find the parent of current node and append curr node as a right child of that parent
			while(pending.size() && (depth - pending.top().second)!=1){
				pending.pop();
			}
			//now our top has suitable parent for the curr node now append the curr node with parent as a right child .....
			//right child cause of we have been backtracking that's why we assumed that our left subtree completed
			parent=pending.top();
			(parent.first)->right=currNode;
			pending.push(make_pair(currNode  , depth));//append curr node
		}
	}
	return root;
}
void print(TreeNode *root){
	if(!root) return;
	print(root->left);
	cout<<root->val<<' ';
	print(root->right);
}
int main(){
	string str;
	cin>>str;
	TreeNode *root=recoverFromPreorder(str);
	print(root);
	return 0;
}