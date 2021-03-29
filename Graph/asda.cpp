#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


int*vis=new int[10000]();

bool bip(vector<vector<int>>&v,int n,int m)
{
   
	
    queue<int>q;
   
    q.push(0);
    unordered_set<int>s[2];
    
    s[0].insert(0);
    
    
    
    while(q.empty()==0)
    {
        int top=q.front();
        cout<<top<<" ";
          vis[top]=1;
          int curr=1;
        if(s[0].count(top)>0)
       {
        curr=0;
       }
        else if(s[1].count(top)>0)
       {
        curr=1;
        }
        for(auto it:v[top])
        {
            if(vis[it]==0)
            {
                 q.push(it);
                 s[1-curr].insert(it);
                 vis[it]=1;
            }
            else
            {
                if(s[curr].count(it)>0)
                {
                    return false;
                    break;
                }
            }
               
        }
        q.pop();
    }
    return true;
    
}
int main() 
{
   
     int n;
     cin>>n;
     int m;
     cin>>m;
     vector<vector<int>>v(n);
     while(m--)
     {
         int a,b;
         cin>>a>>b;
         v[a-1].pb(b-1);
         v[b-1].pb(a-1);
         
     }
     

     if(bip(v,n,m)==true)
     {
         cout<<"TRUE"<<" \n";
     }
     else
     {
         cout<<"FALSE"<<"\n";
     }
	
	

	
	return 0;
}