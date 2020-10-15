#include <bits/stdc++.h>
using namespace std;
int countSquares(vector<vector<int>>& matrix) {
	for(int i=matrix.size()-2 ;i>=0 ; i--){
		vector<int> row=matrix[i];
		for(int j=row.size()-2 ; j>=0 ; j--){
			if(row[j]){
				matrix[i][j]+=min({matrix[i+1][j+1] , matrix[i][j+1] , matrix[i+1][j]});
			}
		}
	}
	int sum=0;
	for(int i=0 ; i<matrix.size();i++){
		vector<int> row=matrix[i];
		for(int j=0 ; j<row.size() ; j++){
			//cout<<row[j]<<" ";
			sum+=row[j];
		}
		// cout<<endl;
	}
	return sum;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v;
	for(int i=0 ; i<n ;i++){
		vector<int> p;
		for(int j=0 ; j<m ; j++){
			int x;
			cin>>x;
			p.push_back(x);
		}
		v.push_back(p);
	}
	cout<<countSquares(v);
}