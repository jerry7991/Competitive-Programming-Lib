#include<bits/stdc++.h>
using namespace std;
int solve(string &word1 , string &word2 ,int **dp ,unsigned int i=0 ,unsigned int j=0){
	if(i==word1.size() && j==word2.size()) return 0;
	if(i==word1.size() || j==word2.size()){
		return max(word1.size()-i , word2.size()-j);
	}
	int &ans=dp[i][j];
	if(ans!=-1) return ans;
	if(word1[i]==word2[j]){
		ans=solve(word1 , word2, dp , i+1 , j+1);
	}else{
		//for convert word1 to word2
		//opt1 replace word1[i] with word2[j]
		int opt1=1+solve(word1 , word2, dp , i+1 , j+1);//if we replace then both string become same so increase length
		//insert word2[j] into word1[i]
		int opt2=1+solve(word1 , word2, dp , i , j+1);//word1 has inserted so his length will be same and other hand word2 will be decrease
		//delete word1[i]
		int opt3=1+solve(word1 , word2, dp , i+1, j);//word1[i] will be deleted and word2[j] remains same
		ans=min(opt3 , min(opt1 , opt2));
	}
	return ans;
}
int minDistance(string& word1, string& word2) {
	if(word1.size()==0 || word2.size()==0) return max(word1.size() , word2.size());
	int **dp=new int*[word1.size()+1];
	for(unsigned int i=0 ; i<=word1.size() ; i++){
		dp[i]=new int[word2.size()+1];
		for(unsigned int j=0 ; j<=word2.size() ;j++) dp[i][j]=-1;
	}
	return solve(word1 , word2,dp );
	return 0;        
}
int main(){
	while(true){
	string word1,word2;
	cin>>word1>>word2;
	if(word1=="x")
		return 0;
	cout<<minDistance(word1 , word2)<<'\n';
	}
}