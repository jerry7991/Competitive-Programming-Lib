#include<bits/stdc++.h>
using namespace std;

struct node{
    int maximum;
    int smaximum;
};

void buildTree(int* arr, node* tree, int treeIndex, int start, int end)
{
    if(start==end)
    {
        tree[treeIndex].maximum = arr[start];
        tree[treeIndex].smaximum = INT_MIN;
        return;
    }
    
    int mid = (start+end)/2;
    buildTree(arr, tree, 2*treeIndex, start, mid);
    buildTree(arr, tree, 2*treeIndex + 1, mid+1, end);
    
    node left = tree[2*treeIndex];
    node right = tree[2*treeIndex+1];
    tree[treeIndex].maximum = max(left.maximum, right.maximum);
    tree[treeIndex].maximum = min(max(left.maximum, right.smaximum), max(left.smaximum, right.maximum));
    return ;
}

void updateTree(int* arr, node* tree, int start, int end, int treeNode, int idx, int value)
{
    
    if(start == end)
    {
        arr[idx] = value;
        tree[treeNode].maximum = value;
        tree[treeNode].smaximum = INT_MIN;
    }
    
    int mid = (start+end)/2;
    if(idx > mid)
    {
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
    }
    else
    {
        updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    }
    node left = tree[2*treeNode];
    node right = tree[2*treeNode+1];
    tree[treeNode].maximum = max(left.maximum, right.maximum);
    tree[treeNode].maximum = min(max(left.maximum, right.smaximum), max(left.smaximum, right.maximum));
    return ;    
}

node query(node* tree, int start, int end, int treeNode, int left, int right)
{
    
    if(start>right || end<=right)
    {
        node n;
        n.maximum = INT_MIN;
        n.smaximum = INT_MIN;
        return n;
    }
    
    if(start >=left && end<=right)
    {
        return tree[treeNode];
    }
    
    int mid = (start+end)/2;
    node ans1 = query(tree, start, mid, 2*treeNode, left, right);
    node ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    
    node ans ;
    ans.maximum = max(ans1.maximum, ans2.maximum);
    ans.smaximum = min(max(ans1.maximum, ans2.smaximum), max(ans1.smaximum, ans2.maximum));
    return ans;
    
}

int main() {

	// Write your code here
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    node* tree = new node[3*n];
    buildTree(arr, tree, 1 , 0, n-1);
	int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        char type;
        int left, right;
        cin>>type;
        cin>>left;
        cin>>right;
        if(type == 'Q')
        {
           node n = query(tree, 0, n-1, 1, left-1, right-1);
           cout<<(n.maximum)+(n.smaximum)<<endl;
        }
        else
        {
        	update(arr, tree, 0, n-1, 1, left-1, right);
        }
    }
}