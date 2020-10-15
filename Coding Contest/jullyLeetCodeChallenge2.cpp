#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define mod 1000000007
#define pb push_back
#define fon(i,n) for(unsigned int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define upm unordered_map
#define data val
using namespace std;
template <typename T=int> class TreeNode
{
public:
	T data;
	TreeNode<T>*left;
	TreeNode<T>*right;
	TreeNode(T data){
		this->data=data;
	}
};
TreeNode<int>* takeInput(){
	queue<TreeNode<int>*> q;
	int data;
	cin>>data;
	if(data==-1) return NULL;
	TreeNode<int>*root=new TreeNode<int>(data);
	q.push(root);
	while(q.size()){
		TreeNode<int>*temp=q.front(); q.pop();
		cin>>data;
		if(data!=-1){
			temp->left=new TreeNode<int>(data);
			q.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if(data!=-1){
			temp->right=new TreeNode<int>(data);
			q.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
vector<vector<int>> levelOrderBottom(TreeNode<int>* root) {
 	vector<vector<int>>output;
 	stack<vector<int>> level;
 	if(root==NULL) return output;
 	queue<TreeNode<int>*> q;
 	q.push(root);
 	q.push(NULL);
 	vector<int> currLevel;
 	while(q.size()){
 		TreeNode<int>*temp=q.front();q.pop();
 		if(!temp){
 			level.push(currLevel);
 			if(q.size()){
 				q.push(NULL);
 				std::vector<int> v;
 				currLevel=v;
 			}
 		}else{
 			currLevel.pb(temp->data);
 			if(temp->left) q.push(temp->left);
 			if(temp->right) q.push(temp->right);
 		}
 	}
 	while(level.size()){
 		output.pb(level.top());
 		level.pop();
 	}
 	return output;
}
int main(){
	TreeNode<int>*root=takeInput();
	vector<vector<int>> output=levelOrderBottom(root);
	fon(i,output.size()){
		vector<int> v=output[i];
		fon(j,v.size()) cout<<v[j]<<" ";
		cout<<endl;
	}
}