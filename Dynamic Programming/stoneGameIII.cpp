#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &stoneValue ,int **dp ,unsigned int len=0 , int turns=1){
	if(len==stoneValue.size()) return 0;
	int &ans=dp[len][turns];
	if(ans!=-1) return ans;
	if(turns){
		//alice turns
		int opt1,opt2,opt3;
		opt1=opt2=opt3=-10000;
		opt1=stoneValue[len]+solve(stoneValue, dp , len+1 , turns^1);
		if(len+1<stoneValue.size())
			opt2=stoneValue[len]+stoneValue[len+1]+solve(stoneValue, dp , len+2 , turns^1);
		if(len+2<stoneValue.size())
			opt3=stoneValue[len]+stoneValue[len+1]+stoneValue[len+2]+solve(stoneValue, dp , len+3 , turns^1);
		ans= max(opt1 ,max( opt2 , opt3));
	}else{
		//bob turnes
		int opt1,opt2,opt3;
		opt1=opt2=opt3=10000;
		opt1=solve(stoneValue, dp , len+1 , turns^1)-stoneValue[len];
		if(len+1<stoneValue.size())
			opt2=solve(stoneValue, dp , len+2 , turns^1)-stoneValue[len]-stoneValue[len+1];
		if(len+2<stoneValue.size())
			opt3=solve(stoneValue, dp , len+3 , turns^1)-stoneValue[len]-stoneValue[len+1]-stoneValue[len+2];
		ans=min(opt1 ,min( opt2 , opt3));
	}
	return ans;
}
string stoneGameIII(vector<int>& stoneValue) {
	int **dp=new int*[stoneValue.size()+1];
	for(unsigned int i=0 ; i<=stoneValue.size(); i++){
		dp[i]=new int[2];
		dp[i][0]=-1000000;
		dp[i][1]=-1000000;
	}
	int val=solve(stoneValue , dp);
	if(val>0){
		return "Alice";
	}else if(val<0){
		return "Bob";
	}else{
		return "Tie";
	}
}
//optmise
int stoneGameIIIOptimise(vector<int> &v){
	int n=v.size();
	vector<int> dp(n,-1e9);
	for(int i=n-1 ; i>=0 ; i--){
		for(int k=0 , take=0 ; k<3 && (i+k)<n; k++){
			take +=v[k+i];//if we include k then answer at k-th will be affected by i+k+1 because 
			//bob will decrease that
			dp[i]=max(dp[i] , take-(i+k+1<n ? dp[i+k+1] :0));
		}
	}
	if(dp[0]<0){
		return "Bob";
	}else if(dp[0]>0){
		return "Alice";
	}else{
		return "Tie";
	}
}
int main(){
	vector<int> v;
	int n;cin>>n;
	while(n--){
		int x;cin>>x;
		v.push_back(x);
	}
	cout<<stoneGameIII(v)<<'\n';
	return 0;
}