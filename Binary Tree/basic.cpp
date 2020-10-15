#include <bits/stdc++.h>
#define BNode BinaryTreeNode
#define cin(data) int data ;cin>>data;
using namespace std;
template <typename T> class BNode
{
public:
    BNode<T>*left;
    BNode<T>*right;
    T data;
    BNode(T data)
    {
      this->data=data;
    }
};
queue<BNode<int>*> pending;
BNode<int>* takeInput()
{
  //Input in level order
  cin(data);
  if (data==-1) return NULL;//empty tree
  BNode<int>*root=new BNode<int>(data);
  pending.push(root);
  while(pending.size())
  {
    BNode<int>*temp=pending.front();
    pending.pop();
    //for left subtree
    cin(leftdata);
    if(leftdata!=-1)
    {
      temp->left=new BNode<int>(leftdata);
      pending.push(temp->left);//append cause have to make further tree from that node ,it's not ended here
    }else{
      temp->left=NULL;
    }
    //for right subtree
    cin(rightData);
    if(rightData!=-1)
    {
      temp->right=new BNode<int>(rightData);
      pending.push(temp->right);//append cause have to make further tree from that node ,it's not ended here
    }else{
      temp->right=NULL;
    }
  }
  return root;
}
BNode<int>* takeInputWithAddress()
{
  queue<long> append;//cause for 64-bit operating system address value might be exceed greater int capacity
  cin(data);
  if(data==-1)return NULL;
  BNode<int>*root=new BNode<int>(data);
  append.push((long)root);//append the address instead of pointer
  while(append.size())
  {
    BNode<int>*temp=(BNode<int> *)append.front();//cause we need a pointer to store the address as we usually do
    append.pop();
    cin(leftData);
    if(leftData!=-1)
    {
      temp->left=new BNode<int>(leftData);
      append.push((long)(temp->left));//store just the address of root node of left subtree
    }else{
      temp->left=NULL;
    }
    cin(rightData);
    if(rightData!=-1)
    {
      temp->right=new BNode<int>(rightData);
      append.push((long)((*temp).right));//store just the address of root node of right subtree
    }else{
      temp->right=NULL;
    }
  }
  return root;
}
BNode<int>* takeInputInDepth(bool is_root=true , int parent=-1 , bool is_left=false)//a null tree has a root ,nothing like as a parent and neither left subtree nor right subtree
{
  if(is_root)    cout<<"Enter root data=\t";
  else{
    if(is_left) std::cout << "Enter root data of left subtree of " << parent<<" =\t";
    else  std::cout << "Enter root data of right subtree of " << parent<<" =\t";
  }
  cin(rootData);
  if(rootData==-1) return NULL;
  BNode<int>*root=new BNode<int>(rootData);
  //now tell our function to get the left subtree and right subtree to...........
  root->left=takeInputInDepth(false,rootData , true);
  root->right=takeInputInDepth(false,rootData , false);
  //and now have a complete tree after poping all function from stack just return root for each poping operation
  return root;
}
void print(BNode<int>*root)
{
  if(!root)return;
  pending.push(root);
  pending.push(NULL);//NULL tells me that we are reached at new level;
  while(pending.size())
  {
    BNode<int>*temp=pending.front();
    pending.pop();
    if(!temp)//cause null works like false in c/c++
    {
      if(pending.size()){
        pending.push(NULL);//as a flag for new level
        cout<<endl;
      }
    }else{
      cout<<(*temp).data<<" ";///cuase . has higher pricedence to *
      if(temp->left)  pending.push(temp->left);
      if(temp->right)  pending.push(temp->right);
    }
  }
}
void printL(BNode<int>*root,int parent=-1)
{
  if(!root) return;
  //root data allways will be parent it true for all trees ...i.e. leafe is also a prent of itself
    cout<<(*root).data<<" :";
  //before printing the left and right root data have to check weather they exist or not cause we might be stuck with
  //null pointer exception
  if(root->left)  cout<<" L "<<(*(*root).left).data;
  if(root->right)  cout<<", R "<<(*(*root).right).data;
  cout<<endl;
  printL(root->left , root->data);
  printL(root->right , root->data);
}
void preorder(BNode<int>*root)
{
  if(!root) return;
  //in preorder we get the root data first and then go for left subtree and rightsubtree
  cout<<(*root).data<<" ";
  //let's explore the left subtree till the leafe
  preorder(root->left);
  //and once left subtree has ended then go the left of the  parent of current leafe node i.e.
  preorder(root->right);
}
void postOrder(BNode<int>*root)
{
  if(!root) return;
  //first go the end of left subtree and then print ,backtrack the root node and print right node the turn comes for root
  //explore  left;
  postOrder(root->left);
  postOrder(root->right);
  //while backtracking we are going to print the node
  cout<<root->data<<" ";
  //no null address will hit cause our base case wouldn't allow to enter a NULL in the function
}
void inOrder(BNode<int>*root)
{
  if(!root)return;
  inOrder(root->left);//go till the left
  cout<<root->data<<" ";//print the data
  inOrder(root->right);//go for right subtree
}
void sum(BNode<int>*root , int &x)
{
  if(!root) return;
  x+=(*root).data;
  sum(root->left , x);
  sum(root->right,x);
}
void deletePointer(BNode<int>*root)
{
  if(!root) return;
  //let's find the node which has no child then delete while backtracking...
  //it's safe..we can't delete as inOrder or preorder traversal because if delete then we can't use further that
  //memory so first insure that is we are deleting the memory then we are not allowed to use that memory further
  //if we try to access , will get stuck with NullPointer
  deletePointer(root->left);
  deletePointer(root->right);
  delete root;
}
int main()
{
  cout<<"Enter tree details in level order use -1 for end of node \n";
  BNode<int>*root=takeInput();
  cout<<endl<<"Tree in level order :- "<<endl;
  print(root);
  cout<<endl<<"Tree in depth order :- \n";
  printL(root);
  cout<<endl<<"Tree in inOrder :-"<<endl;
  inOrder(root);
  cout<<endl<<"Tree in preorder :-"<<endl;
  preorder(root);
  cout<<endl<<"Tree in postOrder :- "<<endl;
  postOrder(root);
  int totalS=0;
  sum(root,totalS);
  cout<<endl<<"total sum of tree element is "<<totalS<<endl;
  cout<<endl<<"Enter tree details in depth order use -1 for end of tree"<<endl;
  BNode<int>*root1=takeInputInDepth();
  cout<<endl<<"Tree in level order :- "<<endl;
  print(root1);
  cout<<endl<<"Tree in depth order :- \n";
  printL(root1);
  cout<<endl<<"Tree in inOrder :-"<<endl;
  inOrder(root1);
  cout<<endl<<"Tree in preorder :-"<<endl;
  preorder(root1);
  cout<<endl<<"Tree in postOrder :- "<<endl;
  postOrder(root1);
  sum(root1,totalS);
  cout<<endl<<"total sum of tree element is "<<totalS<<endl;
  cout<<endl<<"Enter tree details in depth order use -1 for end of tree with use address"<<endl;
  BNode<int>*root2=takeInputWithAddress();
  cout<<endl<<"Tree in level order :- "<<endl;
  print(root2);
  cout<<endl<<"Tree in depth order :- \n";
  printL(root2);
  cout<<endl<<"Tree in inOrder :-"<<endl;
  inOrder(root2);
  cout<<endl<<"Tree in preorder :-"<<endl;
  preorder(root2);
  cout<<endl<<"Tree in postOrder :- "<<endl;
  postOrder(root2);
  sum(root2,totalS);
  cout<<endl<<"total sum of tree element is "<<totalS<<endl;
  /*
  print depth order is just like postOrder....................
  let's look how we should clear the memory of the tree data
  we can't delete dircetly root cause rest of the subtree remains on heap.. so have to delete all the pointer
  which created dynamically
  Is it necessary to remove?Not at all but the memory is created by me so also removed by me...
  cause system wouldn't able to know that what should be the scope of your memory i.e. how much time have the memory
  on the disk
  */
  deletePointer(root);
  deletePointer(root1);
  deletePointer(root2);
  return 0;
}
