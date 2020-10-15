#include <bits/stdc++.h>
using namespace std;

class tries{
    public:
    int e=0;
    tries **children;
    tries(){
        this->children=new tries*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};


tries* insert(tries *root,string s){
    tries *temp=root;
    for(int i=0;i<s.length();i++){
        int a=s[i]-'a';
        if(temp->children[a]){
            if(i==s.length()-1)
                temp->children[a]->e=1;
             temp=temp->children[a];
        }
        else{
            tries *n=new tries;
            n->e=0;
             if(i==s.length()-1)
                n->e=1;
            temp->children[a]=n;
             temp=temp->children[a];
        }
        
    }
    return root;
}
void dfs(tries *root,string s){
    if(root->e==1)
    {
        cout<<s<<endl;
    }
    for(int i=0;i<26;i++){
        if(root->children[i]){
            char c= 97+i;
            dfs(root->children[i],s+c);
        }
    }
    return;
}
int query(tries *root,string s){
    if(root==NULL)
        return -1;
    tries *temp=root;
    for(int i=0;i<s.length();i++){
         int a=s[i]-'a';
        if(temp->children[a]){
             temp=temp->children[a];
        }
        else{
          return -1;
        }
    }
    dfs(temp,s);
    return 1;
}

int main()
{
    int n;
    cin>>n;
     string c;
   
    tries *root=new tries;
    for(int i=0;i<n;i++){
        cin>>c;
        root=insert(root,c);
    }
    int q;
    cin>>q;
    while(q--){
        cin>>c;
        int a=query(root,c);
        if(a==-1){
            cout<<"No suggestions"<<endl;
            root=insert(root,c);
        }
        
    }
    return 0;
}
