#include<bits/stdc++.h>
using namespace std;
//it would not work since both are playing optimimaly
bool solve(vector<int>&piles , int left , int right , int alicCount , int bobCount ,int prevPlayer , int **dp){
	//base case
	if(left>right){
		return alicCount>bobCount;
	}
	if(dp[left][right]!=-1) return dp[left][right];
	bool ans=false;
	if(prevPlayer){
		//now bob turns
		//since we want to win alic so we give bob to min stone
		if(piles[left]>piles[right]){
			ans |= solve(piles , left , right+1 , alicCount , bobCount+piles[right] ,prevPlayer^1 , dp);
		}else{
			ans |= solve(piles , left+1 , right ,alicCount , bobCount+piles[left] ,prevPlayer^1 ,dp)
		}
	}else{
		//now alice turns
		//since we want to let alic win that's why we allowed a max value
		if(piles[left]>piles[right]){
			ans |= solve(piles , left+1 ,right , alicCount+piles[left] , bobCount , prevPlayer^1 , dp);
		}else{
			ans |= solve(piles , left ,right+1 , alicCount+piles[right] , bobCount , prevPlayer^1 , dp);
		}
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