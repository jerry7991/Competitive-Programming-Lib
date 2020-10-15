#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    trieNode *left;
    trieNode *right;
};

void insert(int n,trieNode *root){
    trieNode *curr=root;
    for(int i=31;i>=0;i--){
        int b=(n>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left=new trieNode();
            }
            curr=curr->left;
        }else{
            if(!curr->right){
                curr->right=new trieNode();
            }
            curr=curr->right;
        }
    }
}

int findmax(trieNode *root,int *ar,int n){
    int maxi=0;
    //initially insert for the first time first element
    insert(ar[0] , root);
    int value=ar[0];//total exor till any point of time in trie
    for(int i=1;i<n;i++){
    int element=ar[i];
         value=value^element;//make exor of curr element with complete xor with trie
        /*
        	because if tries has the xor value of 1,5,7,9 and now we are going to store 10 ok!!
	so we can get the all subset from 1^5^7^9 with 10 how let's look
	if we want subset {5,7,9 } ok...
	then what i did
	value =value ^arr[i];  and now value =1^5^7^9^10; ok and we want get {5,7,9,10}
	so just xor value with 1 i.e. (1^5^7^9^10)^1 ;xor of same number become 0 and xor of non
	zeor number with 0 become that number...
	so finally we get 5^7^9^10

	other example v..
    value=1^5^7^9 , curr arr[i]=10;
    update value=1^5^7^9^10;
    we want a subset 5^7^10 then just make value^1^9 then same value become 0  and xor of non
	zeor number with 0 become that number...
	..........................
so instead of storing just arr[i] store complete xor till in trie with arr[i]..
this is most tricky part..
no you must be clear
        */
        trieNode *curr=root;
        //cout<<value<<endl;
        int curr_xor=0;
        for(int j=31;j>=0;j--){
            int b=(value>>j)&1;
            if(b==0){
                //for max we should take one side edge if it is
                if(curr->right){
                    //it give the value
                    curr_xor+=pow(2,j);
                    curr=curr->right;
                }else if(curr->left){
                    //before going to left check weather left sub tree exist or not
                    //and it dosen't increase the value
                    curr=curr->left;
                }
            }else{
                //we have already 1 bit so go to 0 one if it is
                if(curr->left){
                    //for max we should take 0 side edge if it is
                    curr_xor+=pow(2,j);
                    curr=curr->left;
                }else if(curr->right){
                      //before going to left check weather left sub tree exist or not
                    //and it dosen't increase the value
                    curr=curr->right;
                }
            }
            //cout<<cur_xor<<endl;
        }
        //now insert value in tries
        insert(value  , root);
        if(curr_xor>maxi)
            maxi=curr_xor;
    }
    return maxi;
}

int main() {

	// Write your code here
    int n;
    cin>>n;
    int *ar=new int[n];
    trieNode *root=new trieNode();
    // don't insert all element into trie ,insert one element at a time
    for(int i=0;i<n;i++){
         cin>>ar[i];
    //     insert(ar[i],root);
     }
    cout<<findmax(root,ar,n)<<endl;
    return 0;
}
