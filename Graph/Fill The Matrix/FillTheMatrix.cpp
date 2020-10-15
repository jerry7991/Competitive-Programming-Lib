#include <bits/stdc++.h>
using namespace std;
#define N 100000
#define pb push_back
typedef pair<int,int> pii;
inline int read(){
    int n= 0;
    char c;
    while((c=getchar_unlocked())<48);
    n += (c-'0');
    while((c=getchar_unlocked())>=48){
        n=n*10+(c-'0');
    }
    return n;
}
int find(int parent[],int d[], int x){
    if(parent[x]<0){
        return x;
    }
    int root = find(parent,d,parent[x]);
    d[x] = d[x]^d[parent[x]];
    parent[x] = root;
    return root;
}
bool unionE(int parent[],int d[], int u, int v, int x){
    int root1 = find(parent,d,u);
    int root2 = find(parent,d,v);
    if(root1 == root2){
        if(d[u]^d[v]!=x){
            return false;
        }
        return true;
    }else{
        if(parent[root1] == parent[root2]){
            parent[root1]--;
        }
        if(parent[root1]<parent[root2]){
            parent[root2] = root1;
            d[root2] = d[u]^d[v]^x;
        }else{
            parent[root1] = root2;
            d[root1] = d[u]^d[v]^x;
        }
    }
    return true;
}
int main() {
	int t = read();
	int n,q,u,v,x;
	while(t--){
	 n = read();
	 q = read();
	 int parent[n+1];
	 int d[n+1];
	 for(int i=1;i<=n;i++){
	     parent[i] = -1;
	     d[i] = 0;
	 }
	 bool possible = true;
	 for(int i=0;i<q;i++){
	     u = read();
	     v = read();
	     x = read();
	     if(possible){
	         possible = unionE(parent,d,u,v,x);
	     }
	 }
	 if(!possible){
	     cout<<"no\n";
	 }else{
	     cout<<"yes\n";
	 }
	}
	return 0;
}
