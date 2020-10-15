#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    unordered_map<string , vector<string>> loc;
    for(int i=0 ; i<k ; i++){
        string src,dest;
        cin>>src>>dest;
        loc[src].push_back(dest);
        loc[dest].push_back(src);
    }
    string src,dest;
    cin>>src>>dest;
    int level=0;
    unordered_map<string , int>visited;
    
    unordered_map<string , vector<string>>::iterator itr=loc.begin();
    while(itr!=loc.end()){
        vector<string> v=itr->second;
        cout<<itr->first<<" : ";
        for(int i=0 ; i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
    itr++;
    }
}