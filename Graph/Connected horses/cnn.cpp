#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 100000007

ll modExp(ll a, ll b){
    if(a == 0){
        return 0;
    }
    if(b == 0){
        return 1;
    }
    ll sub = modExp(a, b/2);
    ll ans; 
    if(b%2 == 0){
        ans = (sub*sub)%mod;
    }
    else{
        ans = (((sub*sub)%mod)*a)%mod;
    }
    return (ans+mod)%mod;    
}

ll fact(ll n){
    if(n>=mod){
        return 0;
    }
    ll ans = 1;
    for(ll i=n+1;i<mod;i++){
        ans = (ans * modExp(i, mod-2))%mod;
    }
    ans = (ans * -1)+mod;
    return ans;
}

struct horse{
    int x;
    int y;
};

void dfs(vector<int> *edges, int start, unordered_set<int>* component, bool *visited){
    visited[start] = true;
    component->insert(start);
    for(int i=0;i<edges[start].size();i++){
        int next = edges[start][i];
        if(!visited[next]){
            dfs(edges, next, component, visited);
        }
    }
}

unordered_set<unordered_set<int>*>* getComponents(vector<int> *edges, int n){
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            unordered_set<int>* component = new unordered_set<int>();
            dfs(edges, i, component, visited);
            output->insert(component);
        }
    }
    delete[] visited;
    return output;
}

int main()
{
	int t;
    cin>>t;
    while(t--){
        int n, m, q;
        cin>>n>>m>>q;
        horse *h = new horse[q];
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            h[i].x=x-1;
            h[i].y=y-1;
        }
        vector<int>* edges = new vector<int>;
        for(int i=0;i<q;i++){
            for(int j=0;j<q;j++){
                if(i!=j){
                    if(abs(h[i].x-h[j].x)==1 && abs(h[i].y-h[j].y)==2){
                        edges[i].push_back(j);
                        edges[j].push_back(i);
                    }
                    if(abs(h[i].y-h[j].y)==1 && abs(h[i].x-h[j].x)==2){
                        edges[i].push_back(j);
                        edges[j].push_back(i);
                    }
                }
            }
        }
        cout<<"hi"; 
        unordered_set<unordered_set<int>*>* components = getComponents(edges, q);
        unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
        ll res = 1;
        while(it1!=components->end()){
            unordered_set<int>* component = *it1;
            ll size = component->size();
            res = (res*fact(size))%mod;     
            it1++;
        }
        cout<<(int)res<<endl;
    }
	return 0;
}
