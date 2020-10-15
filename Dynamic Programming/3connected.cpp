#include<iostream>
#include<vector>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int solve(int n , int m  , vector<int> u , vector<int> v){
	bool **edge=new bool*[n];
	fon(i,n){
		edge[i]=new bool[n];
		fon(j,n) edge[i][j]=false;
	}
	fon(i,m){
		edge[u[i]-1][v[i]-1]=true;
		edge[v[i]-1][u[i]-1]=true;
	}
	int nCycle=0;
	fon(i,n){
		fon(j,n){
			if(j==i || !edge[i][j]) continue;
			fon(k,n){
				if(j==k	|| !edge[j][k]) continue;
				if(edge[k][i]) nCycle++;
			}
		}
	}
	fon(i,n) delete []edge[i];
	delete[] edge;
	return nCycle/6;
}
int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}