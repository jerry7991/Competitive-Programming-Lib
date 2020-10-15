#include<bits/stdc++.h>
using namespace std;
int solve(string &s , int curr  , char last , int count , int k){
	int ans=101;
	if(k<0) return 101;
	if(curr>=s.size()) return 0;
	//delete 
	ans=min(ans ,solve(s , curr+1 , last , count , k-1));
	//concatinate
	if(s[curr]!=last){
		ans=min(ans  , 1+solve(s , curr+1 , s[curr] ,1, k));//need one more length a2 like
	}else{
		//we can cancatinate
		if(count==1 || count==9 || count==99){
			//need one more length to concatinate 
			ans=min(ans , 1+solve(s , curr+1 ,last, count+1 , k));
		}else{
			ans=min(ans , solve(s , curr+1 , last , count+1 , k));//no need one more length cause a3->a4,a6,a8 in same length
		}
	}
	return ans;
}
int getLengthOfOptimalCompression(string s , int k){
	return solve(s , 0 , 'A' ,0 , k);
}
int main(){
	string str;
	cin>>str;
	int k;cin>>k;
	cout<<getLengthOfOptimalCompression(str ,k)<<'\n';
	return 0;
}