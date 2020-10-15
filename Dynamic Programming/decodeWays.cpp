#include <iostream>
using namespace std;
inline int getInt(char ch) {return ch-'0';}
int numDecodings(string s ,unsigned int len=0) {
	if(len>=s.size()) return 0;
	int ans=0;
	if(getInt(s[len])>=1){
		ans+=1+numDecodings(s , len+1);
	}
	if(getInt(s[len]*10+getInt(s[len+1]))<27 && getInt(s[len]*10+getInt(s[len+1]))>9){
		ans+=1+numDecodings(s , len+2);
	}
	return ans;
}
int numDecodings2(string s){
	if(s.size()==1) return s[0]!='0';
	int n=s.size();
	int *dp=new int[n];
	dp[0]=getInt(s[0])>0;
	if(!dp[0]) return 0;
	dp[1]=0;
	if(getInt(s[1])>=1){
		dp[1]=dp[0];
	if((getInt(s[0])*10+getInt(s[1]))<27 && (getInt(s[0])*10+getInt(s[1]))>9) dp[1]++;
	}else if((getInt(s[0])*10+getInt(s[1]))<27 && (getInt(s[0])*10+getInt(s[1]))>9){
		dp[1]++;
	}
	if(dp[1]==0) return 0;
	//cout<<dp[0]<<" "<<dp[1];
	for(unsigned int i=2 ; i<n ; i++){
		dp[i]=0;
		if(getInt(s[i])>=1)
		{
			dp[i]=dp[i-1];
			if( (getInt(s[i-1])*10+getInt(s[i]))<27 && (getInt(s[i-1])*10+getInt(s[i]))>9) dp[i]+=dp[i-2];	
		}
		else if( (getInt(s[i-1])*10+getInt(s[i]))<27 && (getInt(s[i-1])*10+getInt(s[i]))>9) dp[i]+=dp[i-2];
		//else return 0;
	}
	int ans=dp[n-1];
	delete []dp;
	return ans;
}
int main(){
	string str;
	cin>>str;
	cout<<numDecodings2(str);
}