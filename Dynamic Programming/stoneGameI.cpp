#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>&piles , int left , int right , int alicCount , int bobCount ,int prevPlayer , int **dp){
	//base case
	if(left>right){
		return alicCount>bobCount;
	}
	if(dp[left][right]!=-1) return dp[left][right];
	bool ans=false;
	if(prevPlayer){
		//now bob turns
		int option1=solve(piles , left+1 , right , alicCount , bobCount+piles[left] , prevPlayer^1 ,dp);
		int option2=solve(piles , left , right-1 , alicCount , bobCount+piles[right] , prevPlayer^1 ,dp);
		ans =option1 || option2;
	}else{
		//now alice turns
		int option1=solve(piles , left+1 , right , alicCount+piles[left], bobCount , prevPlayer^1 ,dp);
		int option2=solve(piles , left , right-1 , alicCount+piles[right], bobCount , prevPlayer^1 ,dp);
		ans= option1 || option2;
	}
	return dp[left][right]=ans;
}
bool stoneGame(vector<int>& piles) {
	if(piles.size()==1) return true;
	int **dp=new int*[piles.size()];
	for(int i=0 ; i<piles.size() ; i++){
		dp[i]=new int[piles.size()];
		for(int j=0 ; j<piles.size() ; j++) dp[i][j]=-1;
	}
	return solve(piles , 0 , piles.size()-1 , 0 , 0 , 0 ,dp);//0 for alice turn and 1 for bob turn
}
int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0 ; i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	cout<<stoneGame(v)<<'\n';
}