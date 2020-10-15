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
bool isBipartite(int g[][100],int v)
{
	uos<int>* color=new uos<int>[2];
	color[0].insert(0);
	queue<int> pending;
	pending.push(0);
	while(pending.size()){
		int curr=pending.front();
		pending.pop();
		int currColor= (color[0].find(curr)==color[0].end())?1:0;
		fon(i,v){
			if(g[curr][i]==1){
				//if i neither in 0 color nor in 1
				if((color[0].find(i)==color[0].end()) && (color[1].find(i)==color[1].end())){
					//assign a opposite color
					color[ currColor^1 ].insert(i);
					pending.push(i);
				}else if(color[currColor].find(i)!=color[currColor].end()){
					//if with in same color
					return false;
				}
				//no need of else if i present in opposite color then no affects........
			}
		}
	}
	return true;
}
void solve(){
	int v,e;
	cin>>v>>e;
	int g[100][100]{{0}};
	fon(i,e){
		int x,y;
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
	}
	cout<<isBipartite(g , v);
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	solve();
    return 0;
}