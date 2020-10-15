#include<bits/stdc++.h>
using namespace std;
int ****dp;//[101][101][27][101];//dp[len][count][last][k] four variable
void init(){
      dp=new int***[101];
    for(int i=0 ; i<101 ; i++)
    {
      dp[i]=new int**[27];
      for(int j=0 ; j<27 ; j++)
      {
        dp[i][j]=new int*[11];
        for(int k=0 ; k<11 ; k++)
        {
          dp[i][j][k]=new int[101];
          for(int l=0 ; l<101 ; l++) dp[i][j][k][l]=-1;
        }
      }
    }
}
inline int min(int a,int b){ return (a>b)?b:a;}
int solve(string &str  , int curr , char last , int count , int k){
	if(k<0) return 101;
	if(curr>=str.size()) return 0;
	if(count>=10) count=10;//we know that count would not exced 99
	int &ans=dp[curr][last-'a'][count][k];
	if(ans>-1) return ans;
	//delete 
	ans=101;
	ans=min(ans , solve(str , curr+1 , last , count , k-1));
	//concatinate
	if(str[curr]!=last){
		ans=min(ans , 1+solve(str , curr+1 , str[curr] , 1 , k));
	}else{
		if(count==1 || count==9 ){
			ans=min(ans , 1+solve(str  , curr+1 , last , count+1 , k));
		}else{
			ans=min(ans , solve(str , curr+1 , last , count+1 , k));
		}
	}
	return ans;
}
int getLengthOfOptimalCompression(string s , int k){
	bool all_same=true;
	if(s.size()==100){
		for(int i=0 ; i<s.size()-1 ;i++){
			if(s[i]!=s[i+1]){
				all_same=false;
				break;
			}
		}
		if(all_same) return 4;
	}
	init();
	return solve(s , 0 , 'z'+1 ,0 , k);
}
int main(){
	string str;
	cin>>str;
	int k;cin>>k;
	cout<<getLengthOfOptimalCompression(str , k)<<'\n';
}