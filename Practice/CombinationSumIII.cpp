#include<bits/stdc++.h>
using namespace std;
void solve(int k ,int n , vector<vector<int>> &output , vector<int> current , int start=1){
	// cout<<n<<'\n';
	if(n==0 && k==0){
		output.push_back(current);
		return;
	}
	if(n<=0 || start>9 || k<=0) return;
	for(int i=start ; i<10 ; i++){
		if(i>n) break;
		vector<int> temp;
		temp=current;
		temp.push_back(i);
		//we have two option either we can include it or not
		solve(k-1 , n-i , output , temp , i+1);
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> output;
	vector<int> current;
	solve(k,n,output , current);
	return output;
}
int main(){
	int n,k;
	cin>>k>>n;
	vector<vector<int>> output=combinationSum3(k,n);
	for(auto x:output){
		for(auto y:x) cout<<y<<' ';
	cout<<'\n';
	}
 return 0;
}
		