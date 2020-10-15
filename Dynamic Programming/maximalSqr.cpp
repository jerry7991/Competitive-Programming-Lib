#include <bits/stdc++.h>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix) {
	int n=matrix.size();//number of rows
	if(n==0) return 0;
	   int m=matrix[0].size();//number of colls
	 if(n==1){
	   for(int i=0 ; i<m ; i++) if(matrix[0][i]=='1') return 1;
	   return 0;
	 }
	int nMax=0;
	int **dp=new int*[n];
	for(int i=0 ; i<n ; i++)dp[i]=new int[m];
	//base case
	for(int i=0  ; i<m ; i++) nMax=max(dp[0][i]=(matrix[0][i]=='1') , nMax);
	for(int i=0  ; i<n ; i++) nMax=max(dp[i][0]=(matrix[i][0]=='1') , nMax);
	for(int i=1; i<n ; i++){
	for(int j=1; j<m ; j++){
		dp[i][j]=0;
		if(matrix[i][j]=='1'){
			dp[i][j]=1+min({dp[i-1][j-1] , dp[i-1][j]  , dp[i][j-1]});
		}
	nMax=max(nMax , dp[i][j]);
	}
	}
	return nMax*nMax;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> v;
	for(int i=0 ; i<n ; i++){
		vector<char> p;
		for(int j=0 ; j<m ; j++){
			char x;cin>>x;
			p.push_back(x);
		}
		v.push_back(p);
	}
	cout<<maximalSquare(v);
}	