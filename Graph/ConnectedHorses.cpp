#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define infinte 2147483647
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define ump unordered_map
#define mp make_pair
#define nMax 1000001
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
ull *fact;
void dfs(int **adjMatrix ,  int i  , int j , int &cLen,int n , int m){
 if(i>=n || j>= m || i<0 || j<0 || adjMatrix[i][j]!=1){
    return ;
 }
    adjMatrix[i][j]=2;
    cLen++;
    dfs(adjMatrix  , i-1 , j+2 , cLen , n , m);
    dfs(adjMatrix  , i+1 , j+2 , cLen , n , m);
    dfs(adjMatrix  , i+2 , j+1 , cLen , n , m);
    dfs(adjMatrix  , i+2 , j-1 , cLen , n , m);
    dfs(adjMatrix  , i+1 , j-2 , cLen , n , m);
    dfs(adjMatrix  , i-1 , j-2 , cLen , n , m);
    dfs(adjMatrix  , i-2 , j-1 , cLen , n , m);
    dfs(adjMatrix  , i-2 , j+1 , cLen , n , m);
}
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    int **adjMatrix=new int*[n];
    fon(i,n){
        adjMatrix[i]=new int[m];
        fon(j,m) adjMatrix[i][j]=0;
    }
    fon(i,q){
        int x,y;cin>>x>>y;
        adjMatrix[x-1][y-1]=1;//would be directed!!! mind it
    }
    int np=1;//number of photograph
    fon(i,n){
        fon(j,m){
            if(adjMatrix[i][j]!=1) continue;
            int cl=0;
            dfs(adjMatrix ,  i , j, cl , n , m);	//cl instance for connected length
            np=(np*fact[cl])%mod;
        }
    }
    fon(i,n) delete []adjMatrix[i];
    delete []adjMatrix;
    cout<<np<<'\n';
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    fact=new ull[nMax];
    fact[0]=1;
    for(int i=1 ; i<nMax ; i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}