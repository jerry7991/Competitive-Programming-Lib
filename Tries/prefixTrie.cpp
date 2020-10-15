#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    char ch;
    Node** node;
    bool endOfWord;
    Node(char ch) {
        this->ch=ch;
        node=new Node*[26];
        for(int i=0 ;i<26 ; i++){
            node[i]=NULL;
        }
        endOfWord=false;
    }
};
class Trie {
private:
    Node *trie;
public:
    Trie(){
        trie=new Node('\0');
    }
    void insert(string word) {
        insert(word , trie);
    }
    bool search(string word) {
        return search(word , trie);
    }
    bool startsWith(string prefix) {
        return startsWith(prefix ,  trie);
    }
private:
    bool startsWith(string &prefix , Node *trie , int len=0){
        if(prefix.size()==len) return true;
        int index=prefix[len]-'a';
        if(trie->node[index]){
            return startsWith(prefix , trie->node[index] , len+1);
        }
        return false;
    }
    bool search(string &word ,Node *trie , int len=0){
        if(word.size()==len) return trie->endOfWord;
        int index=word[len]-'a';
        if(trie->node[index]){
            return search(word , trie->node[index] , len+1);
        }
        return false;
    }
    void insert(string &word , Node *root , int len=0){
        if(word.size()==len){
            root->endOfWord=true;
            return;
        }
        Node *child;
        int index=word[len]-'a';
        if(root->node[index]==NULL){
            child=new Node(word[len]);
            root->node[index]=child;
            root=child;
        }else{
            root=root->node[index];
        }
        insert(word , root , len+1);
    }
};
int main(){
Trie * trie=new Trie();
int nq;
cin>>nq;
while(nq){
    int choice;string str;
    cin>>choice>>str;
    if(choice==0){
        //insert
        trie->insert(str);
    }else if(choice==1){
        cout<<trie->search(str)<<endl;
    }else{
        cout<<trie->startsWith(str)<<endl;
    }
}
return 0;
}