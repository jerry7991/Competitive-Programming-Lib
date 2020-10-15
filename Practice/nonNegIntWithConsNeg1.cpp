#include <iostream>
using namespace std;
int findIntegers(int n ,int i=0){
	if((1<<i)>n) return 1;
	int op1=findIntegers(n-(1<<i),i+2);
	int op2=findIntegers(n,i+1);
	return (op1+op2);
}
int getPossible1(string str , int len=0 , int prev=0){
	if(len==str.size()) return 1;
	int ans=0;
	if(prev){
		 ans=getPossible1(str , len+1, 0);
	}else{
		ans+=getPossible1(str , len+1 , 0);
		ans+=getPossible1(str , len+1 , 1);
	}
	return ans;
}
int solve(int n){
	string str="";
	while(n){
		str=to_string(n%2)+str;
		n/=2;
	}
	return getPossible1(str);
}
int main(){
	int n;
	cin>>n;
	cout<<solve(n);
}