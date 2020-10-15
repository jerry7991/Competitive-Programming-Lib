#include <iostream>
#include<queue>
#include <vector>
#define mod 1000000007
#define pb push_back
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define upm unordered_map
#define Tree BinaryTreeNode
using namespace std;
template <typename T> class Tree{
	public:
		T data;
		Tree<int>*left;
		Tree<int>*right;
		Tree(T data){
			this->data=data;
		}
};
Tree<int>* takeInput(){
	int data;cin>>data;
	if(data==-1) return NULL;
	Tree<int>* root=new Tree<int>(data);
	queue<Tree<int>*> pending;
	pending.push(root);
	while(pending.size()){
		Tree<int>*temp=pending.front();//get the front node from queue and delete them
		pending.pop();
		//now time comes to take input for left and right child of temp
		int leftData;cin>>leftData;//scanf("%d" , &leftData);
		if(leftData!=-1){
			temp->left=new Tree<int>(leftData);
			//left subtree not ended yet.. so have to store for further taking input
			pending.push(temp->left);
		}else{
			temp->left=NULL;//left subtree has ended no need to store cause this is child node
		}
		int rightData;cin>>rightData;//scanf("%d" , &rightData);
		if(rightData!=-1){
			temp->right=new Tree<int>(rightData);
			//right subtree not ended yet.. so have to store for further taking input
			pending.push(temp->right);
		}else{
			temp->right=NULL;//right subtree has ended no need to store cause this is child node
		}
	}
	//once pending queue tree has been made just return the root
	return root;
}
void printInorder(Tree<int>*root){
	if(!root) return;
	printInorder(root->left);
	printf("%d ",root->data);
	printInorder(root->right);
}
void reverseAltNode(Tree<int>* root){
	if(!root) return;
	//I am going to use to concept of level Order Traversal.............
	queue<Tree<int>*> pending;
	pending.push(root);
	pending.push(NULL);//null as a dummy node.. that will tell weather i'm a new level or not
	int level=1;//by default the root node is at level 1(My assumption.. You can do yours)
	while(!pending.empty()){
		Tree<int> *temp=pending.front();pending.pop();
		if(!temp){
			//dummy node hitted what i have inserted with root.. i.e. we are reached a new level
			//so level increase by one
			level++;
				//first i put the dummy node at end of queue if and only if queue.size()!=0 other wise we fall in infinite loop
			if(pending.size()) pending.push(NULL);
			else break;//we are done;
			if(!(level&1)){
				//if level is at even position then have to reverse all the node
				temp=pending.front();//for valid entry in while next while loop
				//we need store all the reference of node which is at the current level and data too
				vector<Tree<int>*> node;
				vector<int> data;
				while(temp){	//while temp!=NULL i.e. untill a new level not come
					temp=pending.front();pending.pop();
					if(temp){	//if temp exist then have to store node and correspond data
						node.pb(temp);//store the reference
						data.pb(temp->data);///store the data
						if(temp->left) pending.push(temp->left);//if left subtree exist then store
						if(temp->right) pending.push(temp->right);//if right subtree exist then store 
					}
				}
				//note:- since we have removed dummy node from queue for terminating while loop so we should add again
				if(pending.size()!=0)	pending.push(NULL);
				//now i-th node has data at i-th position so we want to store reverse it
				ui iData=data.size()-1 , iNode=0;
				while(true){
					Tree<int>*curr=node[iNode];
					curr->data=data[iData];
					if(iNode==node.size()-1) break;//cause iData is unsigned so it'll never be -ve
					iData--;iNode++;//forward move for node and backward for data
				}
				//note :- we are recently done with one level so
				level++;
			}
		}else{
			//we are not a new level so just adding the node in queue
			if(temp->left) pending.push(temp->left);
			if(temp->right) pending.push(temp->right);
		}
	}
}
int main(){
	Tree<int> *root=takeInput();
	//printInorder(root);
	reverseAltNode(root);cout<<endl;
	//now tree has been modified print inorder
	printInorder(root);
	return 0;
}