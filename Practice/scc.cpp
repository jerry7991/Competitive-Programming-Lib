#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edge,bool *visited,int s,int v,stack<int> &fin)
{
    visited[s]=0;
    for(int i=0;i<edge[s].size();i++)
    {
        int x=edge[s][i];
        if(visited[x]==0)
        {
            dfs(edge,visited,x,v,fin);
        }
    }
    fin.push(s);
}
void dfs1(vector<int> *edgeT,bool *visited,int s,int v,unordered_set<int>*comp)
{
    visited[s]=0;
    comp->insert(s);
    for(int i=0;i<edgeT[s].size();i++)
    {
        int x=edgeT[s][i];
        if(visited[x]==0)
        {
            dfs1(edgeT,visited,x,v,comp);
        }
    }
}

unordered_set<unordered_set<int>*>* solve(vector<int> *edge,vector<int> *edgeT,int v)
{
    unordered_set<unordered_set<int>*>* out=new unordered_set<unordered_set<int>*>();
    bool *visited=new bool[v]();
    stack<int> fin;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            dfs(edge,visited,i,v,fin);
        }
    }
    for(int i=0;i<v;i++)
    visited[i]=0;
    while(fin.size()!=0)
    {
        int el=fin.top();
        fin.pop();
        unordered_set<int>* comp=new unordered_set<int>();
        dfs1(edgeT,visited,el,v,comp);
        out->insert(comp);
    }
    return out;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> *edge=new vector<int>[v];
    vector<int> *edgeT=new vector<int>[v];
    while(e--)
    {
        int f,s;
        cin>>f>>s;
        edge[f-1].push_back(s-1);
        edgeT[s-1].push_back(f-1);

    }
   unordered_set<unordered_set<int>*>* ans=solve(edge,edgeT,v);
   unordered_set<unordered_set<int>*>::iterator it=ans->begin();
   while(it!=ans->end())
   {
       unordered_set<int>* comp=*it;
       unordered_set<int>::iterator it2=comp->begin();
       while(it2!=comp->end())
       {
           cout<<*it2+1<<" ";
           it2++;
       }
       cout<<endl;
       delete comp;
       it++;
   }
    return 0;
}