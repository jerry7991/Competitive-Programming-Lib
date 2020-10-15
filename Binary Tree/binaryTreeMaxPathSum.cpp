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
TreeNode *takeInput(){
	TreeNode *root;
	int data;cin>>data;
	root=new TreeNode(data);
	queue<TreeNode *> pending;
	pending.push(root);
	while(pending.size()){
		TreeNode *temp=pending.front();
		pending.pop();
		cin>>data;
		if(data!=-1){
			temp->left=new TreeNode(data);
			pending.push(temp->left);
		}
		cin>>data;
		if(data!=-1){
			temp->right=new TreeNode(data);
			pending.push(temp->right);
		}
	}
	return root;
}
void print(TreeNode *root){
	if(!root) return ;
	print(root->left);
	cout<<root->val<<' ';
	print(root->right);
}
int solve(TreeNode *root , int &maxSum){
if(!root) return 0;
	int curr=root->val;
	int leftAns=solve(root->left  , maxSum);
	int rightAns=solve(root->right , maxSum);
	int temp=max(max(leftAns , rightAns)+curr , curr);//take one path only
	int ans=max(temp , leftAns+rightAns+curr);//take both path
	maxSum=max(ans , maxSum);
	return temp;
}
int maxPathSum(TreeNode* root) {
	int maxSum=INT_MIN;
	maxSum=max(maxSum,solve(root , maxSum ));
	return maxSum;
}
int main(){
	TreeNode *root=takeInput();
	print(root);
	cout<<maxPathSum(root)<<'\n';
	return 0;
}