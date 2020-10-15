#include<iostream>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
           TreeNode() : val(0), left(NULL), right(NULL) {}
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 TreeNode * takeInput(){
         queue<TreeNode *> pending;
   TreeNode *root;
          int data;cin>>data;
   if(data==-1) return NULL;
   root=new TreeNode(data);
         pending.push(root);
   while(pending.size()){
     TreeNode *temp=pending.front();
     pending.pop();
     //left data
     cin>>data;
     if(data==-1){
       temp->left=NULL;
     }else{
       temp->left=new TreeNode(data);
       pending.push(temp->left);
     }
     //for right subtree
     cin>>data;
     if(data==-1){
       temp->right=NULL;
     }else{
       temp->right=new TreeNode(data);
       pending.push(temp->right);
     }
   }
   return root;
 }
void print(TreeNode *root){
  if(!root) return;
  print(root->left);
  cout<<root->val<<" ";
  print(root->right);
 }
int sumOfLeftLeaves(TreeNode* root) {
  if(!root)  return 0;
  if(root->left && !root->left->left && !root->left->right){
    int output=root->left->val+sumOfLeftLeaves(root->right);
    return output;
  }
  int leftAns=sumOfLeftLeaves(root->left);
  int rightAns=sumOfLeftLeaves(root->right);
  return leftAns+rightAns;
}
int main(){
  TreeNode *root=takeInput();
  print(root);
  cout<<'\n'<<sumOfLeftLeaves(root);
  return 0;
}