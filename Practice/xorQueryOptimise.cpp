#include<bits/stdc++.h>
using namespace std;
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		int n=arr.size();
		vector<int> Xor(n+1,0);
		Xor[0]=0;
		for(int i=1 ; i<=n ; i++) Xor[i]=Xor[i-1]^arr[i-1];
		vector<int> output;
	    int a=0;
		for(auto x:queries){
			output.push_back(Xor[x[1]+1] ^ Xor[x[0]]);
		}
		return output;
}
int main(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n ; i++) cin>>arr[i];
	cin>>n;
	vector<vector<int>> q(n,vector<int>(2));
	for(int i=0 ;i<n;i++){
		cin>>q[i][0]>>q[i][1];
	}
	vector<int> output=xorQueries(arr,q);
	for(auto x:output) cout<<x<<' ';
 return 0;
}