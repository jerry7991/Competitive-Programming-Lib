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
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
void solve(){
	int n,m;
	cin>>n>>m;
	int *rank=new int[n];
	for(int i=0 ; i<n ; i++) cin>>rank[i];
	int **progress=new int*[n];
	for(int i=0 ; i<n ; i++){
		progress[i]=new int[m];
		for(int j=0 ; j<m ; j++) cin>>progress[i][j];
	}
	int count=0;
	for(int i=0 ; i<m && count!=n ; i++){
		int maxRank=0 , index=-1;
		for(int j=0 ; j<n ; j++){
			rank[j]=rank[j]+progress[j][i];
			if(maxRank<rank[j]){
				maxRank=rank[j];
				index=j;
			}
		}
		int flag=0;
		for(int j=0;j<n && flag<2;j++){
			if(rank[j]==maxRank) flag++;
		}
		if(flag==1)
		{
	     rank[index]=-1888;
		 count++;
		}
	}
	cout<<count<<'\n';
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
    return 0;
}