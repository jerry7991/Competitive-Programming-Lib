#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
void printLevelOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int levelSize = q.size();
        while (levelSize != 0)
        {
            TreeNode<int> *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            levelSize = levelSize - 1;
        }
    }
}
void getGreaterSum(TreeNode<int> *root , unordered_map<int,int> &greaterSum)
{
	if(root!=0){
		return;
	}
}
TreeNode<int> *convertBstToGreaterSum(TreeNode<int> *root)
{
    unordered_map<int,int> greaterSum;
    getGreaterSum(root,greaterSum);
}
int main(){
	TreeNode<int> *root=takeInput();

	root=convertBstToGreaterSum(root);
	printLevelOrder(root);
 return 0;
}
		